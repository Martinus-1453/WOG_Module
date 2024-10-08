﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OBINK_PLAYER_H__VER1__
#define __OBINK_PLAYER_H__VER1__

#include "zBinkPlayer.h"
#include "zRenderer.h"


  // sizeof 88h
  class oCBinkPlayer : public zCBinkPlayer {
  public:
    int extendedKeys;          // sizeof 04h    offset 80h
    int disallowInputHandling; // sizeof 04h    offset 84h

    void oCBinkPlayer_OnInit()             zCall( 0x00424890 );
    oCBinkPlayer() : zCtor( zCBinkPlayer ) zInit( oCBinkPlayer_OnInit() );
    virtual ~oCBinkPlayer()                zCall( 0x004248D0 );
    virtual int OpenVideo( zSTRING )       zCall( 0x004253F0 );
    virtual int PlayInit( int )            zCall( 0x004248E0 );
    virtual int PlayFrame()                zCall( 0x00424950 );
    virtual int PlayDeinit()               zCall( 0x00424940 );
    virtual int PlayHandleEvents()         zCall( 0x00424960 );

    // user API
    #include "oCBinkPlayer.inl"
  };


#endif // __OBINK_PLAYER_H__VER1__