﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OGAME_INFO_H__VER3__
#define __OGAME_INFO_H__VER3__

#include "zGameInfo.h"


  // sizeof 18h
  class oCGameInfo : public zCGameInfo {
  public:

    void oCGameInfo_OnInit()                      zCall( 0x00423E30 );
    oCGameInfo() : zCtor( zCGameInfo )            zInit( oCGameInfo_OnInit() );
    virtual ~oCGameInfo()                         zCall( 0x00424000 );
    virtual void Init()                           zCall( 0x00424010 );
    virtual void Pack( zCBuffer&, unsigned char ) zCall( 0x004240D0 );
    virtual void Unpack( zCBuffer& )              zCall( 0x004240E0 );

    // user API
    #include "oCGameInfo.inl"
  };


#endif // __OGAME_INFO_H__VER3__