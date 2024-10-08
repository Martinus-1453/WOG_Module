﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OCS_TRIGGER_H__VER3__
#define __OCS_TRIGGER_H__VER3__

#include "zVob.h"
#include "zVobMisc.h"


  // sizeof 168h
  class oCCSTrigger : public zCTrigger {
  public:
    zCLASS_DECLARATION( oCCSTrigger )

    oCCSTrigger() : zCtor( zCTrigger ) {}
    static zCObject* _CreateNewInstance()    zCall( 0x00404210 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00404330 );
    virtual void Archive( zCArchiver& )      zCall( 0x00404C30 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00404C40 );
    virtual ~oCCSTrigger()                   zCall( 0x00404370 );
    virtual void TriggerTarget( zCVob* )     zCall( 0x00404380 );
    virtual void UntriggerTarget( zCVob* )   zCall( 0x004049F0 );

    // user API
    #include "oCCSTrigger.inl"
  };


#endif // __OCS_TRIGGER_H__VER3__