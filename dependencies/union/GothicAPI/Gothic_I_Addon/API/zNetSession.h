﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZNET_SESSION_H__VER1__
#define __ZNET_SESSION_H__VER1__

#include "zNetHost.h"


  // sizeof 2Ch
  class zCNetSession {
  public:
    unsigned short protocol;          // sizeof 02h    offset 04h
    zTNetAddress listenPacketAddress; // sizeof 10h    offset 08h
    zTNetAddress listenStreamAddress; // sizeof 10h    offset 18h
    int valid;                        // sizeof 04h    offset 28h

    zCNetSession() {}
    void zCNetSession_OnInit( unsigned short ) zCall( 0x0045F0A0 );
    zCNetSession( unsigned short a0 )          zInit( zCNetSession_OnInit( a0 ));
    void Reset()                               zCall( 0x0045F140 );
    virtual ~zCNetSession()                    zCall( 0x0045F160 );

    // user API
    #include "zCNetSession.inl"
  };


#endif // __ZNET_SESSION_H__VER1__