﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZFILE_CSV_H__VER3__
#define __ZFILE_CSV_H__VER3__

#include "zDisk.h"


  // sizeof 228h
  class zCFileCSV : public zFILE_FILE {
  public:
    zCArray<zSTRING> columnList;  // sizeof 0Ch    offset 1C0h
    bool headerProcessed;         // sizeof 01h    offset 1CCh
    zSTRING current_set;          // sizeof 14h    offset 1D0h
    bool csvHasHeader;            // sizeof 01h    offset 1E4h
    zSTRING csvFieldDelimiter;    // sizeof 14h    offset 1E8h
    zSTRING csvFieldFrame;        // sizeof 14h    offset 1FCh
    zSTRING csvCompleteDelimiter; // sizeof 14h    offset 210h
    int column;                   // sizeof 04h    offset 224h

    void zCFileCSV_OnInit( zSTRING const& )                zCall( 0x0044E930 );
    void zCFileCSV_OnInit()                                zCall( 0x0044EAF0 );
    zCFileCSV( zSTRING const& a0 ) : zCtor( zFILE_FILE )   zInit( zCFileCSV_OnInit( a0 ));
    zCFileCSV() : zCtor( zFILE_FILE )                      zInit( zCFileCSV_OnInit() );
    void InitCSV()                                         zCall( 0x0044EDF0 );
    void SetFormat( bool, zSTRING const&, zSTRING const& ) zCall( 0x0044EF10 );
    void AddNextField( zSTRING const& )                    zCall( 0x0044F050 );
    void AddNextHeader( zSTRING const& )                   zCall( 0x0044F1E0 );
    int WriteSet()                                         zCall( 0x0044F390 );
    zSTRING GetNextField( zSTRING const& )                 zCall( 0x0044F550 );
    int ReadSet()                                          zCall( 0x0044F980 );
    int ReadHeader()                                       zCall( 0x0044F9D0 );
    int WriteHeader()                                      zCall( 0x0044FBB0 );
    virtual ~zCFileCSV()                                   zCall( 0x0044EC90 );

    // user API
    #include "zCFileCSV.inl"
  };


#endif // __ZFILE_CSV_H__VER3__