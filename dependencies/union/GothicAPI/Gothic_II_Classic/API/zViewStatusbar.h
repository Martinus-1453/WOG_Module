﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZVIEW_STATUSBAR_H__VER2__
#define __ZVIEW_STATUSBAR_H__VER2__


  // sizeof 118h
  class zCViewStatusBar : public zCView {
  public:
    float minLow;       // sizeof 04h    offset 100h
    float maxHigh;      // sizeof 04h    offset 104h
    float low;          // sizeof 04h    offset 108h
    float high;         // sizeof 04h    offset 10Ch
    float previewValue; // sizeof 04h    offset 110h
    float currentValue; // sizeof 04h    offset 114h

    zDefineInheritableCtor( zCViewStatusBar ) : zCtor( zCView ) {}
    void zCViewStatusBar_OnInit()                                                    zCall( 0x0046E970 );
    void zCViewStatusBar_OnInit( int, int, int, int, zTviewID )                      zCall( 0x0046E9E0 );
    zCViewStatusBar() : zCtor( zCView )                                              zInit( zCViewStatusBar_OnInit() );
    zCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 ) : zCtor( zCView ) zInit( zCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                                      zCall( 0x0046EA50 );
    /* for zCViewBase num : 16*/
    virtual ~zCViewStatusBar()                                                       zCall( 0x0046EA80 );
    virtual void SetMaxRange( float, float )                                         zCall( 0x0046EAA0 );
    virtual void SetRange( float, float )                                            zCall( 0x0046EB40 );
    virtual void SetPreview( float )                                                 zCall( 0x0046EBE0 );
    virtual void SetValue( float )                                                   zCall( 0x0046EC30 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewStatusBar.inl"
  };


#endif // __ZVIEW_STATUSBAR_H__VER2__