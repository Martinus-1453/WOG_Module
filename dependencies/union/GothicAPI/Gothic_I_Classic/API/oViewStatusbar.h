﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OVIEW_STATUSBAR_H__VER0__
#define __OVIEW_STATUSBAR_H__VER0__

#include "zViewStatusbar.h"


  // sizeof 158h
  class oCViewStatusBar : public zCViewStatusBar {
  public:
    float scale;       // sizeof 04h    offset 110h
    zCView* range_bar; // sizeof 04h    offset 114h
    zCView* value_bar; // sizeof 04h    offset 118h
    zSTRING texView;   // sizeof 14h    offset 11Ch
    zSTRING texRange;  // sizeof 14h    offset 130h
    zSTRING texValue;  // sizeof 14h    offset 144h

    void oCViewStatusBar_OnInit()                                                             zCall( 0x00439990 );
    void oCViewStatusBar_OnInit( int, int, int, int, zTviewID )                               zCall( 0x00439AC0 );
    oCViewStatusBar() : zCtor( zCViewStatusBar )                                              zInit( oCViewStatusBar_OnInit() );
    oCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 ) : zCtor( zCViewStatusBar ) zInit( oCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init( int, int, float )                                                              zCall( 0x00439BA0 );
    void SetTextures( zSTRING const&, zSTRING const&, zSTRING const& )                        zCall( 0x00439D40 );
    /* for zCViewBase num : 14*/
    virtual ~oCViewStatusBar()                                                                zCall( 0x00439FE0 );
    virtual void SetMaxRange( float, float )                                                  zCall( 0x0043A130 );
    virtual void SetRange( float, float )                                                     zCall( 0x0043A240 );
    virtual void SetValue( float )                                                            zCall( 0x0043A300 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewStatusBar.inl"
  };


#endif // __OVIEW_STATUSBAR_H__VER0__