﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZSYS_INFO_H__VER2__
#define __ZSYS_INFO_H__VER2__


  // sizeof 6Ch
  class zCSystemInfo {
  public:
    enum zTOperatingSystem {
      OS_UNKNOWN,
      OS_WINDOWS_3_1,
      OS_WINDOWS_95,
      OS_WINDOWS_98,
      OS_WINDOWS_98ME,
      OS_WINDOWS_NT,
      OS_WINDOWS_2000,
      OS_OTHER
    };

    enum zTCpuType {
      CPU_UNKNOWN,
      CPU_INTEL_PENTIUM_I,
      CPU_INTEL_PENTIUM_II,
      CPU_INTEL_PENTIUM_III,
      CPU_INTEL_PENTIUM_IV,
      CPU_AMD_K6,
      CPU_AMD_ATHLON,
      CPU_OTHER
    };

    zTOperatingSystem osType;   // sizeof 04h    offset 04h
    zSTRING osName;             // sizeof 14h    offset 08h
    zSTRING osServicePack;      // sizeof 14h    offset 1Ch
    zTCpuType cpuType;          // sizeof 04h    offset 30h
    zSTRING cpuID;              // sizeof 14h    offset 34h
    unsigned long cpuSpeed;     // sizeof 04h    offset 48h
    unsigned long memSize;      // sizeof 04h    offset 4Ch
    unsigned long memAvailable; // sizeof 04h    offset 50h
    zSTRING graName;            // sizeof 14h    offset 54h
    unsigned long graMemSize;   // sizeof 04h    offset 68h

    zDefineInheritableCtor( zCSystemInfo ) {}
    void zCSystemInfo_OnInit() zCall( 0x0046C580 );
    zCSystemInfo()             zInit( zCSystemInfo_OnInit() );
    void AnalyseMemory()       zCall( 0x0046C820 );
    void AnalyseCpu()          zCall( 0x0046C850 );
    void AnalyseOs()           zCall( 0x0046CA20 );
    void AnalyseGcard()        zCall( 0x0046CE50 );
    zSTRING GetOsName()        zCall( 0x0046D7D0 );
    virtual ~zCSystemInfo()    zCall( 0x0046C740 );
    virtual void AnalyseNow()  zCall( 0x0046CE70 );

    // user API
    #include "zCSystemInfo.inl"
  };


#endif // __ZSYS_INFO_H__VER2__