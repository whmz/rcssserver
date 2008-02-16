// -*-c++-*-

/***************************************************************************
                             initsenderlogger.h
                  Classes for writing init messages for logger
                             -------------------
    begin                : 2008-02-16
    copyright            : (C) 2008 by The RoboCup Soccer Simulator
                           Maintenance Group.
    email                : sserver-admin@lists.sourceforge.net
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU LGPL as published by the Free Software  *
 *   Foundation; either version 2 of the License, or (at your option) any  *
 *   later version.                                                        *
 *                                                                         *
 ***************************************************************************/


#ifndef RCSS_INITSENDER_LOGGER_H
#define RCSS_INITSENDER_LOGGER_H

#include "initsender.h"

class Logger;

namespace rcss {

class SerializerMonitor;

class InitSenderLogger
    : public InitSender {
public:
    class Params {
    public:
        std::ostream & m_transport;
        const Logger & m_self;
        const SerializerMonitor & m_ser;
        const Stadium & M_stadium;

        Params( std::ostream & transport,
                const Player & self,
                const SerializerMonitor & serializer,
                const Stadium & stadium )
            : m_transport( transport )
            , m_self( self )
            , m_serializer( serializer )
            , M_stadium( stadium )
          { }
    };

    typedef std::auto_ptr< InitSenderLogger > Ptr;
    typedef Ptr (*Creator)( const Params & );
    typedef rcss::lib::Factory< Creator, int > Factory;

private:

    const SerializerMonitor & M_serializer;
    /*:TODO: M_self needs to be replaced with a reference to a
      BodyObserver and BodyObserver should have virtual functions for
      stuff like velocity, stamina, etc */
    const Logger & M_self;
    const Stadium & M_stadium;

public:
    static
    Factory & factory();

    virtual
    ~InitSenderLogger();

protected:

    InitSenderLogger( Params & params,
                      const boost::shared_ptr< InitSenderCommon >& common );

    const
    SerializerMonitor & serializer() const
      {
          return M_serializer;
      }

    const
    Logger & self() const
      {
          return M_self;
      }

    const
    Stadium & stadium() const
      {
          return M_stadium;
      }

public:

    void sendInit()
      { }
    void sendChangedPlayers()
      { }
    void sendScore()
      { }

    virtual
    void sendHeader() = 0;

    virtual
    void sendPlayMode() = 0;

    virtual
    void sendTeam() = 0;

};


/*!
  \class InitObserverLogger
 */
class InitgObserverLogger
    : protected BaseObserver< InitSenderLogger > {
public:

    InitObserverLogger()
      { }

    InitObserverLogger( InitSenderLogger & sender )
        : BaseObserver< InitSenderLogger >( sender )
      { }

    ~IntiSenderLogger()
      { }

    void setInitSender( InitSenderLogger & sender )
      {
          BaseObserver< InitSenderLogger >::setSender( sender );
      }

    void setInitSender( std::auto_ptr< InitSenderLogger > sender )
      {
          BaseObserver< InitSenderLogger >::setSender( sender );
      }

    void sendHeader()
      {
          BaseObserver< InitSenderLogger >::sender().sendHeader();
      }

    void sendServerParams()
      {
          BaseObserver< InitSenderLogger >::sender().sendServerParams();
      }

    void sendPlayerParams()
      {
          BaseObserver< InitSenderLogger >::sender().sendPlayerParams();
      }

    void sendPlaeyerTypes()
      {
          BaseObserver< InitSenderLogger >::sender().sendPlayeTypes();
      }

    void sendPlayMode()
      {
          BaseObserver< InitSenderLogger >::sender().sendPlayMode();
      }

    void sendTeam()
      {
          BaseObserver< InitSenderLogger >::sender().sendTeam();
      }

};


class InitSenderLoggerV1
    : public InitSenderLogger {
public:
    InitSenderLoggerV1( const Params & params );

protected:
    InitSenderLoggerV1( const Params & params,
                        const boost::shared_ptr< InitSenderCommon > common );

public:
    virtual
    ~InitSenderLoggerV1();

    virtual
    void sendHeader();

    virtual
    void sendServerParams();

    virtual
    void sendPlayerParams();

    virtual
    void sendPlayerTypes();

    virtual
    void sendPlayMode();

    virtual
    void sendTeam();

};

class InitSenderLoggerV2
    : public InitSenderLoggerV1 {
public:
    InitSenderLoggerV2( const Params & params );

protected:
    InitSenderLoggerV2( const Params & params,
                        const boost::shared_ptr< InitSenderCommon > common );

public:
    virtual
    ~InitSenderLoggerV2();

    virtual
    void sendHeader();

    virtual
    void sendServerParams();

    virtual
    void sendPlayerParams();

    virtual
    void sendPlayerTypes();

    virtual
    void sendPlayMode();

    virtual
    void sendTeam();

};

class InitSenderLoggerV3
    : public InitSenderLoggerV2 {
public:
    InitSenderLoggerV3( const Params & params );

protected:
    InitSenderLoggerV3( const Params & params,
                        const boost::shared_ptr< InitSenderCommon > common );

public:
    virtual
    ~InitSenderLoggerV3();

    virtual
    void sendHeader();

    virtual
    void sendServerParams();

    virtual
    void sendPlayerParams();

    virtual
    void sendPlayerTypes();

    virtual
    void sendPlayMode();

    virtual
    void sendTeam();

};


class InitSenderLoggerV4
    : public InitSenderLoggerV3 {
public:
    InitSenderLoggerV4( const Params & params );

protected:
    InitSenderLoggerV4( const Params & params,
                        const boost::shared_ptr< InitSenderCommon > common );

public:
    virtual
    ~InitSenderLoggerV4();

    virtual
    void sendHeader();

    virtual
    void sendServerParams();

    virtual
    void sendPlayerParams();

    virtual
    void sendPlayerTypes();

    virtual
    void sendPlayMode();

    virtual
    void sendTeam();

};

}

#endif
