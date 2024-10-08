﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZACCOUNT_H__VER3__
#define __ZACCOUNT_H__VER3__


  class zCAccount {
  public:

    zCAccount() {}
    static void Add( void const*, char const*, int, int ) zCall( 0x0065D510 );
    static void Sum( void const* )                        zCall( 0x0065D860 );
    static void Clear( void const* )                      zCall( 0x0065DCB0 );
    static void Begin()                                   zCall( 0x0065DCE0 );
    static void End()                                     zCall( 0x0065DCF0 );
    static int IsActive()                                 zCall( 0x0065DD00 );

    // static properties
    static int& s_actCounter;

    // user API
    #include "zCAccount.inl"
  };


#endif // __ZACCOUNT_H__VER3__