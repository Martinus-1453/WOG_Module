﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OBINK_PLAYER_H__VER3__
#define __OBINK_PLAYER_H__VER3__

#include "zBinkPlayer.h"
#include "zRenderer.h"


  // sizeof 88h
  class oCBinkPlayer : public zCBinkPlayer {
  public:
    int extendedKeys;          // sizeof 04h    offset 80h
    int disallowInputHandling; // sizeof 04h    offset 84h

    void oCBinkPlayer_OnInit()             zCall( 0x00422BD0 );
    oCBinkPlayer() : zCtor( zCBinkPlayer ) zInit( oCBinkPlayer_OnInit() );
    virtual ~oCBinkPlayer()                zCall( 0x00422C10 );
    virtual int OpenVideo( zSTRING )       zCall( 0x00423780 );
    virtual int PlayInit( int )            zCall( 0x00422C20 );
    virtual int PlayFrame()                zCall( 0x00422C90 );
    virtual int PlayDeinit()               zCall( 0x00422C80 );
    virtual int PlayHandleEvents()         zCall( 0x00422CA0 );

    // user API
    #include "oCBinkPlayer.inl"
  };


#endif // __OBINK_PLAYER_H__VER3__