﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OCS_PLAYER_H__VER2__
#define __OCS_PLAYER_H__VER2__

#include "zCCsPlayer.h"


  // sizeof 68h
  class oCCSPlayer : public zCCSPlayer {
  public:
    zCLASS_DECLARATION( oCCSPlayer )

    void oCCSPlayer_OnInit()                                           zCall( 0x004038D0 );
    oCCSPlayer() : zCtor( zCCSPlayer )                                 zInit( oCCSPlayer_OnInit() );
    static zCObject* _CreateNewInstance()                              zCall( 0x00403850 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x004038C0 );
    virtual ~oCCSPlayer()                                              zCall( 0x00403920 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& ) zCall( 0x00403940 );
    /* for zCCSDebugger num : 7*/

    // user API
    #include "oCCSPlayer.inl"
  };


#endif // __OCS_PLAYER_H__VER2__