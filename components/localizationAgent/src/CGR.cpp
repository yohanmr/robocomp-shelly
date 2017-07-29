// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `CGR.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <CGR.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __RoboCompCGR__CGRTopic__newCGRPose_name = "newCGRPose";

const ::std::string __RoboCompCGR__CGRTopic__newCGRCorrection_name = "newCGRCorrection";

const ::std::string __RoboCompCGR__CGR__resetPose_name = "resetPose";

}
::IceProxy::Ice::Object* ::IceProxy::RoboCompCGR::upCast(::IceProxy::RoboCompCGR::CGRTopic* p) { return p; }

void
::IceProxy::RoboCompCGR::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::RoboCompCGR::CGRTopic>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::RoboCompCGR::CGRTopic;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::RoboCompCGR::CGRTopic::newCGRPose(::Ice::Float poseUncertainty, ::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __RoboCompCGR__CGRTopic__newCGRPose_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::RoboCompCGR::CGRTopic* __del = dynamic_cast< ::IceDelegate::RoboCompCGR::CGRTopic*>(__delBase.get());
            __del->newCGRPose(poseUncertainty, x, z, alpha, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCGR::CGRTopic::begin_newCGRPose(::Ice::Float poseUncertainty, ::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RoboCompCGR__CGRTopic__newCGRPose_name, __del, __cookie);
    try
    {
        __result->__prepare(__RoboCompCGR__CGRTopic__newCGRPose_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(poseUncertainty);
        __os->write(x);
        __os->write(z);
        __os->write(alpha);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::RoboCompCGR::CGRTopic::end_newCGRPose(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __RoboCompCGR__CGRTopic__newCGRPose_name);
}

void
IceProxy::RoboCompCGR::CGRTopic::newCGRCorrection(::Ice::Float poseUncertainty, ::Ice::Float x1, ::Ice::Float z1, ::Ice::Float alpha1, ::Ice::Float x2, ::Ice::Float z2, ::Ice::Float alpha2, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __RoboCompCGR__CGRTopic__newCGRCorrection_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::RoboCompCGR::CGRTopic* __del = dynamic_cast< ::IceDelegate::RoboCompCGR::CGRTopic*>(__delBase.get());
            __del->newCGRCorrection(poseUncertainty, x1, z1, alpha1, x2, z2, alpha2, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCGR::CGRTopic::begin_newCGRCorrection(::Ice::Float poseUncertainty, ::Ice::Float x1, ::Ice::Float z1, ::Ice::Float alpha1, ::Ice::Float x2, ::Ice::Float z2, ::Ice::Float alpha2, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RoboCompCGR__CGRTopic__newCGRCorrection_name, __del, __cookie);
    try
    {
        __result->__prepare(__RoboCompCGR__CGRTopic__newCGRCorrection_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(poseUncertainty);
        __os->write(x1);
        __os->write(z1);
        __os->write(alpha1);
        __os->write(x2);
        __os->write(z2);
        __os->write(alpha2);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::RoboCompCGR::CGRTopic::end_newCGRCorrection(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __RoboCompCGR__CGRTopic__newCGRCorrection_name);
}

const ::std::string&
IceProxy::RoboCompCGR::CGRTopic::ice_staticId()
{
    return ::RoboCompCGR::CGRTopic::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::RoboCompCGR::CGRTopic::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::RoboCompCGR::CGRTopic);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::RoboCompCGR::CGRTopic::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::RoboCompCGR::CGRTopic);
}

::IceProxy::Ice::Object*
IceProxy::RoboCompCGR::CGRTopic::__newInstance() const
{
    return new CGRTopic;
}
::IceProxy::Ice::Object* ::IceProxy::RoboCompCGR::upCast(::IceProxy::RoboCompCGR::CGR* p) { return p; }

void
::IceProxy::RoboCompCGR::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::RoboCompCGR::CGR>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::RoboCompCGR::CGR;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::RoboCompCGR::CGR::resetPose(::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __RoboCompCGR__CGR__resetPose_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::RoboCompCGR::CGR* __del = dynamic_cast< ::IceDelegate::RoboCompCGR::CGR*>(__delBase.get());
            __del->resetPose(x, z, alpha, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCGR::CGR::begin_resetPose(::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RoboCompCGR__CGR__resetPose_name, __del, __cookie);
    try
    {
        __result->__prepare(__RoboCompCGR__CGR__resetPose_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(x);
        __os->write(z);
        __os->write(alpha);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::RoboCompCGR::CGR::end_resetPose(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __RoboCompCGR__CGR__resetPose_name);
}

const ::std::string&
IceProxy::RoboCompCGR::CGR::ice_staticId()
{
    return ::RoboCompCGR::CGR::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::RoboCompCGR::CGR::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::RoboCompCGR::CGR);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::RoboCompCGR::CGR::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::RoboCompCGR::CGR);
}

::IceProxy::Ice::Object*
IceProxy::RoboCompCGR::CGR::__newInstance() const
{
    return new CGR;
}

void
IceDelegateM::RoboCompCGR::CGRTopic::newCGRPose(::Ice::Float poseUncertainty, ::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __RoboCompCGR__CGRTopic__newCGRPose_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(poseUncertainty);
        __os->write(x);
        __os->write(z);
        __os->write(alpha);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::RoboCompCGR::CGRTopic::newCGRCorrection(::Ice::Float poseUncertainty, ::Ice::Float x1, ::Ice::Float z1, ::Ice::Float alpha1, ::Ice::Float x2, ::Ice::Float z2, ::Ice::Float alpha2, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __RoboCompCGR__CGRTopic__newCGRCorrection_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(poseUncertainty);
        __os->write(x1);
        __os->write(z1);
        __os->write(alpha1);
        __os->write(x2);
        __os->write(z2);
        __os->write(alpha2);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::RoboCompCGR::CGR::resetPose(::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __RoboCompCGR__CGR__resetPose_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(x);
        __os->write(z);
        __os->write(alpha);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::RoboCompCGR::CGRTopic::newCGRPose(::Ice::Float poseUncertainty, ::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Float __p_poseUncertainty, ::Ice::Float __p_x, ::Ice::Float __p_z, ::Ice::Float __p_alpha, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_poseUncertainty(__p_poseUncertainty),
            _m_x(__p_x),
            _m_z(__p_z),
            _m_alpha(__p_alpha)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::RoboCompCGR::CGRTopic* servant = dynamic_cast< ::RoboCompCGR::CGRTopic*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->newCGRPose(_m_poseUncertainty, _m_x, _m_z, _m_alpha, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Float _m_poseUncertainty;
        ::Ice::Float _m_x;
        ::Ice::Float _m_z;
        ::Ice::Float _m_alpha;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __RoboCompCGR__CGRTopic__newCGRPose_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(poseUncertainty, x, z, alpha, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::RoboCompCGR::CGRTopic::newCGRCorrection(::Ice::Float poseUncertainty, ::Ice::Float x1, ::Ice::Float z1, ::Ice::Float alpha1, ::Ice::Float x2, ::Ice::Float z2, ::Ice::Float alpha2, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Float __p_poseUncertainty, ::Ice::Float __p_x1, ::Ice::Float __p_z1, ::Ice::Float __p_alpha1, ::Ice::Float __p_x2, ::Ice::Float __p_z2, ::Ice::Float __p_alpha2, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_poseUncertainty(__p_poseUncertainty),
            _m_x1(__p_x1),
            _m_z1(__p_z1),
            _m_alpha1(__p_alpha1),
            _m_x2(__p_x2),
            _m_z2(__p_z2),
            _m_alpha2(__p_alpha2)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::RoboCompCGR::CGRTopic* servant = dynamic_cast< ::RoboCompCGR::CGRTopic*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->newCGRCorrection(_m_poseUncertainty, _m_x1, _m_z1, _m_alpha1, _m_x2, _m_z2, _m_alpha2, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Float _m_poseUncertainty;
        ::Ice::Float _m_x1;
        ::Ice::Float _m_z1;
        ::Ice::Float _m_alpha1;
        ::Ice::Float _m_x2;
        ::Ice::Float _m_z2;
        ::Ice::Float _m_alpha2;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __RoboCompCGR__CGRTopic__newCGRCorrection_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(poseUncertainty, x1, z1, alpha1, x2, z2, alpha2, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::RoboCompCGR::CGR::resetPose(::Ice::Float x, ::Ice::Float z, ::Ice::Float alpha, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Float __p_x, ::Ice::Float __p_z, ::Ice::Float __p_alpha, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_x(__p_x),
            _m_z(__p_z),
            _m_alpha(__p_alpha)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::RoboCompCGR::CGR* servant = dynamic_cast< ::RoboCompCGR::CGR*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->resetPose(_m_x, _m_z, _m_alpha, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Float _m_x;
        ::Ice::Float _m_z;
        ::Ice::Float _m_alpha;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __RoboCompCGR__CGR__resetPose_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(x, z, alpha, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Object* RoboCompCGR::upCast(::RoboCompCGR::CGRTopic* p) { return p; }

namespace
{
const ::std::string __RoboCompCGR__CGRTopic_ids[2] =
{
    "::Ice::Object",
    "::RoboCompCGR::CGRTopic"
};

}

bool
RoboCompCGR::CGRTopic::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__RoboCompCGR__CGRTopic_ids, __RoboCompCGR__CGRTopic_ids + 2, _s);
}

::std::vector< ::std::string>
RoboCompCGR::CGRTopic::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__RoboCompCGR__CGRTopic_ids[0], &__RoboCompCGR__CGRTopic_ids[2]);
}

const ::std::string&
RoboCompCGR::CGRTopic::ice_id(const ::Ice::Current&) const
{
    return __RoboCompCGR__CGRTopic_ids[1];
}

const ::std::string&
RoboCompCGR::CGRTopic::ice_staticId()
{
    return __RoboCompCGR__CGRTopic_ids[1];
}

::Ice::DispatchStatus
RoboCompCGR::CGRTopic::___newCGRPose(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Float poseUncertainty;
    ::Ice::Float x;
    ::Ice::Float z;
    ::Ice::Float alpha;
    __is->read(poseUncertainty);
    __is->read(x);
    __is->read(z);
    __is->read(alpha);
    __inS.endReadParams();
    newCGRPose(poseUncertainty, x, z, alpha, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
RoboCompCGR::CGRTopic::___newCGRCorrection(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Float poseUncertainty;
    ::Ice::Float x1;
    ::Ice::Float z1;
    ::Ice::Float alpha1;
    ::Ice::Float x2;
    ::Ice::Float z2;
    ::Ice::Float alpha2;
    __is->read(poseUncertainty);
    __is->read(x1);
    __is->read(z1);
    __is->read(alpha1);
    __is->read(x2);
    __is->read(z2);
    __is->read(alpha2);
    __inS.endReadParams();
    newCGRCorrection(poseUncertainty, x1, z1, alpha1, x2, z2, alpha2, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __RoboCompCGR__CGRTopic_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "newCGRCorrection",
    "newCGRPose"
};

}

::Ice::DispatchStatus
RoboCompCGR::CGRTopic::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__RoboCompCGR__CGRTopic_all, __RoboCompCGR__CGRTopic_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __RoboCompCGR__CGRTopic_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___newCGRCorrection(in, current);
        }
        case 5:
        {
            return ___newCGRPose(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
RoboCompCGR::CGRTopic::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
RoboCompCGR::CGRTopic::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
RoboCompCGR::__patch(CGRTopicPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::RoboCompCGR::CGRTopicPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::RoboCompCGR::CGRTopic::ice_staticId(), v);
    }
}

::Ice::Object* RoboCompCGR::upCast(::RoboCompCGR::CGR* p) { return p; }

namespace
{
const ::std::string __RoboCompCGR__CGR_ids[2] =
{
    "::Ice::Object",
    "::RoboCompCGR::CGR"
};

}

bool
RoboCompCGR::CGR::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__RoboCompCGR__CGR_ids, __RoboCompCGR__CGR_ids + 2, _s);
}

::std::vector< ::std::string>
RoboCompCGR::CGR::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__RoboCompCGR__CGR_ids[0], &__RoboCompCGR__CGR_ids[2]);
}

const ::std::string&
RoboCompCGR::CGR::ice_id(const ::Ice::Current&) const
{
    return __RoboCompCGR__CGR_ids[1];
}

const ::std::string&
RoboCompCGR::CGR::ice_staticId()
{
    return __RoboCompCGR__CGR_ids[1];
}

::Ice::DispatchStatus
RoboCompCGR::CGR::___resetPose(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Float x;
    ::Ice::Float z;
    ::Ice::Float alpha;
    __is->read(x);
    __is->read(z);
    __is->read(alpha);
    __inS.endReadParams();
    resetPose(x, z, alpha, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __RoboCompCGR__CGR_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "resetPose"
};

}

::Ice::DispatchStatus
RoboCompCGR::CGR::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__RoboCompCGR__CGR_all, __RoboCompCGR__CGR_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __RoboCompCGR__CGR_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___resetPose(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
RoboCompCGR::CGR::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
RoboCompCGR::CGR::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
RoboCompCGR::__patch(CGRPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::RoboCompCGR::CGRPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::RoboCompCGR::CGR::ice_staticId(), v);
    }
}