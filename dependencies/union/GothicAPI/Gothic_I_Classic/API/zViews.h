﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZVIEWS_H__VER0__
#define __ZVIEWS_H__VER0__

#include "zView.h"


  // sizeof FCh
  class zCViewWindow : public zCView {
  public:

    zCViewWindow() : zCtor( zCView ) {}
    void zCViewWindow_OnInit( int, int, int, int, zTviewID )                      zCall( 0x004F2FC0 );
    zCViewWindow( int a0, int a1, int a2, int a3, zTviewID a4 ) : zCtor( zCView ) zInit( zCViewWindow_OnInit( a0, a1, a2, a3, a4 ));
    /* for zCViewBase num : 11*/
    virtual ~zCViewWindow()                                                       zCall( 0x004F3060 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewWindow.inl"
  };


#endif // __ZVIEWS_H__VER0__