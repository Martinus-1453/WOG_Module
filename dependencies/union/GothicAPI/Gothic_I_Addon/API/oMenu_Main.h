﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OMENU__MAIN_H__VER1__
#define __OMENU__MAIN_H__VER1__

#include "zMenu.h"


  // sizeof CC4h
  class oCMenu_ChgKeys : public zCMenu {
  public:

    oCMenu_ChgKeys() : zCtor( zCMenu ) {}
    void oCMenu_ChgKeys_OnInit( zSTRING const& )                   zCall( 0x0047C6D0 );
    oCMenu_ChgKeys( zSTRING const& a0 ) : zCtor( zCMenu )          zInit( oCMenu_ChgKeys_OnInit( a0 ));
    void InitText()                                                zCall( 0x0047D4C0 );
    virtual int HandleEvent( int )                                 zCall( 0x0047C720 );
    virtual void Leave()                                           zCall( 0x0047D410 );
    virtual ~oCMenu_ChgKeys()                                      zCall( 0x0047C710 );
    virtual void ScreenInit()                                      zCall( 0x0047D3F0 );
    virtual int ExecCommand( zSTRING const& )                      zCall( 0x0047C990 );

    // user API
    #include "oCMenu_ChgKeys.inl"
  };

  // sizeof CC4h
  class oCMenu_Main : public zCMenu {
  public:

    zDefineInheritableCtor( oCMenu_Main ) : zCtor( zCMenu ) {}
    oCMenu_Main() : zCtor( zCMenu ) {}
    void oCMenu_Main_OnInit( zSTRING const& )                   zCall( 0x0047C480 );
    oCMenu_Main( zSTRING const& a0 ) : zCtor( zCMenu )          zInit( oCMenu_Main_OnInit( a0 ));
    virtual int HandleEvent( int )                              zCall( 0x0047C4E0 );
    virtual ~oCMenu_Main()                                      zCall( 0x0042F4E0 );
    virtual void ScreenInit()                                   zCall( 0x0047C4C0 );
    virtual void ScreenDone()                                   zCall( 0x0047C4D0 );

    // user API
    #include "oCMenu_Main.inl"
  };


#endif // __OMENU__MAIN_H__VER1__