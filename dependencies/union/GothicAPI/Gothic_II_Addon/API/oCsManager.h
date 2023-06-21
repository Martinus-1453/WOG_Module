﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OCS_MANAGER_H__VER3__
#define __OCS_MANAGER_H__VER3__

#include "zCCsManager.h"


  // sizeof 70h
  class oCCSManager : public zCCSManager {
  public:
    zCLASS_DECLARATION( oCCSManager )

    void oCCSManager_OnInit()                            zCall( 0x00401600 );
    oCCSManager() : zCtor( zCCSManager )                 zInit( oCCSManager_OnInit() );
    static zCObject* _CreateNewInstance()                zCall( 0x00401550 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x004022C0 );
    virtual ~oCCSManager()                               zCall( 0x00402360 );
    virtual zCEventMessage* CreateMessage( int )         zCall( 0x00402420 );
    virtual zCEventMessage* CreateOuMessage()            zCall( 0x00402410 );
    virtual zCCSPlayer* CreateCutscenePlayer( zCWorld* ) zCall( 0x00402370 );
    virtual zCCSProps* CreateProperties()                zCall( 0x00402B10 );

    // user API
    #include "oCCSManager.inl"
  };


#endif // __OCS_MANAGER_H__VER3__