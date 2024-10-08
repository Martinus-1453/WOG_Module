﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZAI_H__VER3__
#define __ZAI_H__VER3__

#include "zTools.h"
#include "zDisk.h"


  // sizeof 24h
  class zCAIBase : public zCObject {
  public:
    zCLASS_DECLARATION( zCAIBase )

    zDefineInheritableCtor( zCAIBase ) : zCtor( zCObject ) {}
    zCAIBase() : zCtor( zCObject ) {}
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x0048BD20 );
    virtual ~zCAIBase()                                                zCall( 0x0048BE50 );
    virtual void DoAI( zCVob*, int& )                                  zPureCall;
    virtual int CanThisCollideWith( zCVob* )                           zCall( 0x0048BD30 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )       zCall( 0x0048BDF0 );
    virtual int HasAIDetectedCollision()                               zCall( 0x0048BD40 );
    virtual void AICollisionResponseSelfDetected( zVEC3 const&, int& ) zCall( 0x0048BD50 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )           zCall( 0x0048BD60 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )               zCall( 0x0048BE00 );
    virtual int GetIsProjectile()                                      zCall( 0x0048BE10 );

    // user API
    #include "zCAIBase.inl"
  };

  // sizeof 2Ch
  class zCAIBaseSound : public zCAIBase {
  public:
    zCLASS_DECLARATION( zCAIBaseSound )

    int slideSoundHandle; // sizeof 04h    offset 24h
    char slideSoundOn;    // sizeof 01h    offset 28h

    zCAIBaseSound() : zCtor( zCAIBase ) {}
    void RemoveSlideSound()                                             zCall( 0x0050C120 );
    void CheckSlideSound( zCVob* )                                      zCall( 0x0050C140 );
    void StartDefaultCollisionSound( zCVob*, zCCollisionReport const& ) zCall( 0x0050C1D0 );

    // user API
    #include "zCAIBaseSound.inl"
  };


#endif // __ZAI_H__VER3__