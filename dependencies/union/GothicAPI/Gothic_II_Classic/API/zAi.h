﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZAI_H__VER2__
#define __ZAI_H__VER2__


  // sizeof 24h
  class zCAIBase : public zCObject {
  public:
    zCLASS_DECLARATION( zCAIBase )

    zDefineInheritableCtor( zCAIBase ) : zCtor( zCObject ) {}
    zCAIBase() : zCtor( zCObject ) {}
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x0048A3C0 );
    virtual ~zCAIBase()                                                zCall( 0x0048A4D0 );
    virtual void DoAI( zCVob*, int& )                                  zPureCall;
    virtual int CanThisCollideWith( zCVob* )                           zCall( 0x0048A3D0 );
    virtual void ReportCollisionToAI( zCCollisionReport const& )       zCall( 0x0048A480 );
    virtual int HasAIDetectedCollision()                               zCall( 0x0048A3E0 );
    virtual void AICollisionResponseSelfDetected( zVEC3 const&, int& ) zCall( 0x0048A3F0 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )           zCall( 0x0048A400 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )               zCall( 0x0048A490 );

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
    void RemoveSlideSound()                                             zCall( 0x00509370 );
    void CheckSlideSound( zCVob* )                                      zCall( 0x00509390 );
    void StartDefaultCollisionSound( zCVob*, zCCollisionReport const& ) zCall( 0x00509420 );

    // user API
    #include "zCAIBaseSound.inl"
  };


#endif // __ZAI_H__VER2__