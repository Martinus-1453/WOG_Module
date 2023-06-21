﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OHELP_H__VER2__
#define __OHELP_H__VER2__


  // sizeof 5Ch
  class oCHelp {
  public:
    zCView* win;  // sizeof 04h    offset 00h
    int dx;       // sizeof 04h    offset 04h
    int dy;       // sizeof 04h    offset 08h
    int sx;       // sizeof 04h    offset 0Ch
    int sy;       // sizeof 04h    offset 10h
    int x[4];     // sizeof 10h    offset 14h
    int y[4];     // sizeof 10h    offset 24h
    int index[4]; // sizeof 10h    offset 34h
    int led[2];   // sizeof 08h    offset 44h
    int ledx[2];  // sizeof 08h    offset 4Ch
    int ledy[2];  // sizeof 08h    offset 54h

    void oCHelp_OnInit()  zCall( 0x006A3B40 );
    oCHelp()              zInit( oCHelp_OnInit() );
    ~oCHelp()             zCall( 0x006A42E0 );
    void CalcPos()        zCall( 0x006A4310 );
    void Toggle()         zCall( 0x006A43C0 );
    void Update()         zCall( 0x006A4570 );
    void Redraw( zCVob* ) zCall( 0x006A4580 );

    // user API
    #include "oCHelp.inl"
  };


#endif // __OHELP_H__VER2__