﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZACCOUNT_H__VER2__
#define __ZACCOUNT_H__VER2__


  class zCAccount {
  public:

    zCAccount() {}
    static void Add( void const*, char const*, int, int ) zCall( 0x007A69A0 );
    static void Sum( void const* )                        zCall( 0x007A6CF0 );
    static void Clear( void const* )                      zCall( 0x007A7140 );
    static void Begin()                                   zCall( 0x007A7170 );
    static void End()                                     zCall( 0x007A7180 );
    static int IsActive()                                 zCall( 0x007A7190 );

    // static properties
    static int& s_actCounter;

    // user API
    #include "zCAccount.inl"
  };


#endif // __ZACCOUNT_H__VER2__