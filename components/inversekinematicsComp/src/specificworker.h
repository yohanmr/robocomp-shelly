/*
 *    Copyright (C) 2006-2010 by RoboLab - University of Extremadura
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>

#include <qt4/QtCore/qstring.h>
#include <qt4/QtCore/qdebug.h>
#include <qt4/QtCore/qstringlist.h>
#include <qt4/QtCore/qmap.h>
#include <qt4/QtCore/qpair.h>
#include <qt4/QtCore/qqueue.h>

#include <iostream>
#include <fstream>

#include "cinematica_inversa.h"
#include "target.h"
#include "bodypart.h"
#include "planner.h"


 
using namespace std;

/**
       \brief
       @author Un batiburrillo de personas...
*/


class SpecificWorker : public GenericWorker
{
	Q_OBJECT
	
	public:
		SpecificWorker(MapPrx& mprx, QWidget *parent = 0);	
		~SpecificWorker();
		bool setParams(RoboCompCommonBehavior::ParameterList params);
		void  setTargetPose6D(const string& bodyPart, const Pose6D& target, const WeightVector& weights, float radius);
		void  pointAxisTowardsTarget(const string& bodyPart, const Pose6D& target, const Axis &axis, bool axisConstraint, float axisAngleConstraint);
		void  advanceAlongAxis(const string& bodyPart, const Axis& ax, float dist);
		void  setFingers(float d);
		void  goHome(const string& part);
		void  setRobot(const int type) ;
		TargetState getState(const string &part);
		void  stop(const string& part);
		
		
	public slots:
		void compute(); 

	private:
		
		void init();							// Things to do after params are set
		
		//// VARIABLES DE CLASE ////
		InnerModel *innerModel;							// Para trabajar con el innerModel
		
		QMap<QString, BodyPart>  bodyParts;				// Mapa con identificadorde la parte del robot,lista de motores y tip
		
		QQueue<Target> listaTargetsBrazoDerecho;		// Lista de targets para el brazo derecho
		QQueue<Target> listaTargetsBrazoIzquierdo;		// Lista de targets para el brazo izquierdo
		QQueue<Target> listaTargetsCabeza;				// Lista de targets para la cabeza

		QStringList listaMotores; 						// Tiene TODOS los motores del robot. Para poder actualizar correctamente
		QStringList listaBrazoDerecho;					// Tiene los motores del brazo derecho con los que trabajara cinematica_inversa
		QStringList listaBrazoIzquierdo;				// Tiene los motores del brazo izquierdo con los que trabajara cinematica_inversa
		QStringList listaCabeza;						// Tiene los motores de la cabeza con los que trabajara cinemática_inersa.
		
		Cinematica_Inversa *IK_BrazoDerecho;			// Para realizar las operaciones de cinemática inversa para el brazo derecho
		Cinematica_Inversa *IK_BrazoIzquierdo;			// Para realizar las operaciones de cinemática inversa para el brazo izquierdo
		Cinematica_Inversa *IK_Cabeza;					// Para realizar las operaciones de cinemática inversa para la cabeza
			
		ofstream ficheroErrores;						// fichero de salida con errores 
			
		Planner *planner;
		
		// MÉTODOS PARA ACTUALIZAR //
		void actualizarInnermodel(const QStringList &listaJoints);
		
		// MÉTODOS PARA MOVER COSAS DE LUGAR //
		void moveRobotPart(QVec angles, const QStringList &listaJoints);
		void createInnerModelTarget(Target &target);
		void removeInnerModelTarget(const Target &target);
		void convertInnerModelFromMilimetersToMeters(InnerModelNode* node);
		
		// MÉTODOS AUXILIARES:
		float standardRad(float t);
        void calcularModuloFloat(QVec &angles, float mod);
        void chopPath(const QString &partName, const Target &target);
		
		int correlativeID;
		int typeR;
		RoboCompJointMotor::JointMotorPrx proxy;
	
};

#endif
