﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZMEMORY__GENERIC_H__VER2__
#define __ZMEMORY__GENERIC_H__VER2__

#include "zMemory_Base.h"


  // sizeof 04h
  class zCMallocGeneric : public zCMalloc {
  public:

    void zCMallocGeneric_OnInit()                                       zCall( 0x00560D00 );
    zCMallocGeneric() : zCtor( zCMalloc )                               zInit( zCMallocGeneric_OnInit() );
    virtual ~zCMallocGeneric()                                          zCall( 0x00560C80 );
    virtual void* Malloc( unsigned int )                                zCall( 0x00560DB0 );
    virtual void* Malloc( unsigned int, char const*, char const*, int ) zCall( 0x00560DC0 );
    virtual void* Realloc( void*, unsigned int )                        zCall( 0x00560DD0 );
    virtual void Free( void* )                                          zCall( 0x00560DF0 );
    virtual int GetStats( zTMallocStats& )                              zCall( 0x00560E00 );
    virtual int Init( int )                                             zCall( 0x00560E20 );
    virtual int Shutdown()                                              zCall( 0x00560E30 );

    // user API
    #include "zCMallocGeneric.inl"
  };


#endif // __ZMEMORY__GENERIC_H__VER2__