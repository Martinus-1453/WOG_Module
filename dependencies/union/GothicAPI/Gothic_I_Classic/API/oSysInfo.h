﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OSYS_INFO_H__VER0__
#define __OSYS_INFO_H__VER0__

#include "zSysInfo.h"


  // sizeof A0h
  class oCSystemInfo : public zCSystemInfo {
  public:
    int scored;        // sizeof 04h    offset 6Ch
    float cpuLow;      // sizeof 04h    offset 70h
    float cpuHigh;     // sizeof 04h    offset 74h
    float memLow;      // sizeof 04h    offset 78h
    float memHigh;     // sizeof 04h    offset 7Ch
    float graMemLow;   // sizeof 04h    offset 80h
    float graMemHigh;  // sizeof 04h    offset 84h
    float scoreCpu;    // sizeof 04h    offset 88h
    float scoreMem;    // sizeof 04h    offset 8Ch
    float scoreGraMem; // sizeof 04h    offset 90h
    float scoreGra;    // sizeof 04h    offset 94h
    float scoreSnd;    // sizeof 04h    offset 98h
    float score;       // sizeof 04h    offset 9Ch

    void oCSystemInfo_OnInit()             zCall( 0x00436470 );
    oCSystemInfo() : zCtor( zCSystemInfo ) zInit( oCSystemInfo_OnInit() );
    float GetGraphicsBonus()               zCall( 0x004379D0 );
    float GetSoundBonus()                  zCall( 0x00437A30 );
    zSTRING GetScoreDescr( float )         zCall( 0x00437A40 );
    virtual ~oCSystemInfo()                zCall( 0x00436500 );
    virtual void AnalyseNow()              zCall( 0x00436510 );
    virtual void ScoreNow()                zCall( 0x00436D70 );
    virtual void ResetSettings( float )    zCall( 0x00436520 );

    // user API
    #include "oCSystemInfo.inl"
  };


#endif // __OSYS_INFO_H__VER0__