﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OCS_MANAGER_H__VER0__
#define __OCS_MANAGER_H__VER0__

#include "zCCsManager.h"


  // sizeof 70h
  class oCCSManager : public zCCSManager {
  public:
    zCLASS_DECLARATION( oCCSManager )

    void oCCSManager_OnInit()                                           zCall( 0x00401430 );
    oCCSManager() : zCtor( zCCSManager )                                zInit( oCCSManager_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x004012F0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00402170 );
    virtual ~oCCSManager()                                              zCall( 0x00402210 );
    virtual zCEventMessage* CreateMessage( int )                        zCall( 0x004022F0 );
    virtual zCEventMessage* CreateOuMessage()                           zCall( 0x004022E0 );
    virtual zCCSPlayer* CreateCutscenePlayer( zCWorld* )                zCall( 0x00402220 );
    virtual zCCSProps* CreateProperties()                               zCall( 0x00402B50 );

    // user API
    #include "oCCSManager.inl"
  };


#endif // __OCS_MANAGER_H__VER0__