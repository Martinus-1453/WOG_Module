﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZPLUECKER_H__VER0__
#define __ZPLUECKER_H__VER0__


  // sizeof 18h
  class zCPluecker {
  public:
    float dir[3]; // sizeof 0Ch    offset 00h
    float pos[3]; // sizeof 0Ch    offset 0Ch

    void zCPluecker_OnInit( zVEC3 const&, zVEC3 const& ) zCall( 0x005957B0 );
    void zCPluecker_OnInit()                             zCall( 0x00595800 );
    zCPluecker( zVEC3 const& a0, zVEC3 const& a1 )       zInit( zCPluecker_OnInit( a0, a1 ));
    zCPluecker()                                         zInit( zCPluecker_OnInit() );
    float Length2() const                                zCall( 0x00595820 );
    void Normalize()                                     zCall( 0x00595850 );

    // user API
    #include "zCPluecker.inl"
  };


#endif // __ZPLUECKER_H__VER0__