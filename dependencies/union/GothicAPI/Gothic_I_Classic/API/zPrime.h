﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZPRIME_H__VER0__
#define __ZPRIME_H__VER0__


  // sizeof 01h
  class zCPrime {
  public:

    zCPrime() {}
    static int IsPrime( unsigned long )             zCall( 0x0059DCF0 );
    static unsigned short PrimeNo( unsigned short ) zCall( 0x0059DDC0 );
    static unsigned long NextPrime( unsigned long ) zCall( 0x0059DED0 );

    // user API
    #include "zCPrime.inl"
  };


#endif // __ZPRIME_H__VER0__