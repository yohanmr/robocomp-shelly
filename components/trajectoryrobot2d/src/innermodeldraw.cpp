/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2013  pbustos <email>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include <innermodeldraw.h>
#include <boost/concept_check.hpp>

InnerModelDraw::InnerModelDraw()
{
	
}

InnerModelDraw::~InnerModelDraw()
{

}


void InnerModelDraw::addMesh_ignoreExisting(InnerModelViewer *innerViewer, QString item, QString parent, QVec t, QVec r, QString path, QVec scale)
{
	QMutexLocker ml(innerViewer->mutex);
	InnerModelTransform *tparent = dynamic_cast<InnerModelTransform*>(innerViewer->innerModel->getNode(parent));
	InnerModel *im = innerViewer->innerModel;

	if (im->getNode(item) != NULL)
	{
		removeNode(innerViewer, item);
	}

	InnerModelMesh *mesh = im->newMesh (
		item,
		tparent,
		path,
		scale(0), scale(1), scale(2),
		0,
		t(0), t(1), t(2),
		r(0), r(1), r(2));
	mesh->setScale(scale(0), scale(1), scale(2));
	tparent->addChild(mesh);

	innerViewer->recursiveConstructor(mesh, innerViewer->mts[tparent->id], innerViewer->mts, innerViewer->meshHash);
}

bool InnerModelDraw::addTransform_ignoreExisting(InnerModelViewer *innerViewer, QString item, QString base /*, parametros aqui*/)
{
	if (innerViewer->innerModel->getNode(base) == NULL)
	{
		throw QString("parent doesn't exist");
	}
	
	if (innerViewer->innerModel->getNode(item) != NULL)
	{
// 		return true;
		//innerViewer->innerModel->updateTransformValues(XXXX);
		removeNode(innerViewer, item);
	}
	addTransform(innerViewer, item, base);
	
	return true;
}

bool InnerModelDraw::addTransform(InnerModelViewer *innerViewer, QString item, QString base)
{

	InnerModelNode *parent = innerViewer->innerModel->getNode(base);
	if (parent == NULL)
		return false;

	InnerModelNode *node = innerViewer->innerModel->getNode(item);
	if (node != NULL)
	{
		printf("%s ya existe!\n", item.toStdString().c_str());
		return false;
	}
	
	InnerModelTransform *tr;
	try
	{
		tr = innerViewer->innerModel->newTransform(item, "static", parent, 0,0,0, 0,0,0);
		parent->addChild(tr);
		innerViewer->recursiveConstructor(tr, innerViewer->mts[parent->id], innerViewer->mts, innerViewer->meshHash);

		return true;
	}
	catch (QString err)
	{
		printf("%s:%s:%d: Exception: %s\n", __FILE__, __FUNCTION__, __LINE__, err.toStdString().c_str());
		throw;
	}
}

bool InnerModelDraw::addPlane_ignoreExisting(InnerModelViewer *innerViewer, const QString &item, const QString &base, const QVec &p, const QVec &n, const QString &texture, const QVec &size)
{
	
	if (innerViewer->innerModel->getNode(item))
	{
		removeNode(innerViewer, item);
	}
	addPlane_notExisting(innerViewer, item, base, p, n, texture, size);
		
	return true;
}


bool InnerModelDraw::addPlane_notExisting(InnerModelViewer *innerViewer, const QString &item, const QString &base, const QVec &p, const QVec &n, const QString &texture, const QVec &size)
{
	InnerModelNode *parent = innerViewer->innerModel->getNode(base);
	if (parent == NULL)
	{
		printf("%s: parent not exists\n", __FUNCTION__);
		return false;
	}
	InnerModelPlane *plane = innerViewer->innerModel->newPlane(item, parent, texture, size(0), size(1), size(2), 1, n(0), n(1), n(2), p(0), p(1), p(2), true);
	parent->addChild(plane); 
// 	innerViewer->innerModel->save(item+".xml");
	innerViewer->recursiveConstructor(plane, innerViewer->mts[parent->id], innerViewer->mts, innerViewer->meshHash);

	return true;
}


void InnerModelDraw::drawLine(InnerModelViewer *innerViewer, QString name, QString parent, const QVec& normalVector, float length, float width, QString texture)
{
		
	InnerModelDraw::addPlane_ignoreExisting(innerViewer, name, parent, QVec::vec3(0,0,0), normalVector, texture, QVec::vec3(length, width, width));
		
}

void InnerModelDraw::drawLine2Points(InnerModelViewer *innerViewer, QString name, QString parent, const QVec& p1, const QVec& p2, QString texture)
{
	InnerModelDraw::addPlane_ignoreExisting(innerViewer, name, parent, QVec::vec3(0,0,0), QVec::vec3(0,1,0), texture, QVec::vec3(15, (p1-p2).norm2(), 15));
}


bool InnerModelDraw::removeObject(InnerModelViewer *innerViewer, QString name)
{
	if (innerViewer->innerModel->getNode(name))
	{
		removeNode(innerViewer, name);
		return true;
	}
	return false;
}



bool InnerModelDraw::removeNode(InnerModelViewer *innerViewer, const QString &item)
{
	if (item=="root")
	{
		qDebug() << "Can't remove root elements" << item;
		return false;
	}

	InnerModelNode *node = innerViewer->innerModel->getNode(item);
	if (node == NULL)
	{
		qDebug() << "Can't remove not existing elements" << item;
		return false;
	}

	QStringList l;
	innerViewer->innerModel->getSubTree(node, &l);
	innerViewer->innerModel->removeSubTree(node, &l);

	/// Replicate InnerModel node removals in the InnerModelViewer tree. And in handlers Lists
	foreach(QString n, l)
	{
		/// Replicate mesh removals
		if (innerViewer->meshHash.contains(n))
		{
			while (innerViewer->meshHash[n].osgmeshPaths->getNumParents() > 0)
				innerViewer->meshHash[n].osgmeshPaths->getParent(0)->removeChild(innerViewer->meshHash[n].osgmeshPaths);			
			while(innerViewer->meshHash[n].osgmeshes->getNumParents() > 0)
				innerViewer->meshHash[n].osgmeshes->getParent(0)->removeChild(innerViewer->meshHash[n].osgmeshes);
			while(innerViewer->meshHash[n].meshMts->getNumParents() > 0)	
				innerViewer->meshHash[n].meshMts->getParent(0)->removeChild(innerViewer->meshHash[n].meshMts);			
			innerViewer->meshHash.remove(n);
		}
		/// Replicate transform removals
		if (innerViewer->mts.contains(n))
		{
 			while (innerViewer->mts[n]->getNumParents() > 0)
				innerViewer->mts[n]->getParent(0)->removeChild(innerViewer->mts[n]);
 			innerViewer->mts.remove(n);
		}
		/// Replicate plane removals
		if (innerViewer->planeMts.contains(n))
		{
			while(innerViewer->planeMts[n]->getNumParents() > 0)
				((osg::Group *)(innerViewer->planeMts[n]->getParent(0)))->removeChild(innerViewer->planeMts[n]);
			innerViewer->planeMts.remove(n);
			innerViewer->planesHash.remove(n);
		}
		
	}

	return true;
}

