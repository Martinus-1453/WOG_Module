﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZNET_VERSION_H__VER2__
#define __ZNET_VERSION_H__VER2__

  const short zNET_VERSION = 1;

  // sizeof 0Ch
  class zCNetVersion {
  public:
    long checksum; // sizeof 04h    offset 04h
    long version;  // sizeof 04h    offset 08h

    void zCNetVersion_OnInit()               zCall( 0x0045CB40 );
    zCNetVersion()                           zInit( zCNetVersion_OnInit() );
    virtual ~zCNetVersion()                  zCall( 0x0045CB80 );
    virtual zSTRING GetVersionString() const zCall( 0x0045CBC0 );
    virtual long GetVersionNumber() const    zCall( 0x0045CB90 );
    virtual long GetChecksum() const         zCall( 0x0045CBA0 );
    virtual long CreateChecksum()            zCall( 0x0045CBB0 );
    virtual void Pack( zCBuffer& ) const     zCall( 0x0045CCC0 );
    virtual void Unpack( zCBuffer& )         zCall( 0x0045CCF0 );

    // user API
    #include "zCNetVersion.inl"
  };


#endif // __ZNET_VERSION_H__VER2__