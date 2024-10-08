﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZPRIME_H__VER3__
#define __ZPRIME_H__VER3__


  // sizeof 01h
  class zCPrime {
  public:

    zCPrime() {}
    static int IsPrime( unsigned long )             zCall( 0x005BFBB0 );
    static unsigned short PrimeNo( unsigned short ) zCall( 0x005BFC80 );
    static unsigned long NextPrime( unsigned long ) zCall( 0x005BFD90 );

    // user API
    #include "zCPrime.inl"
  };


#endif // __ZPRIME_H__VER3__