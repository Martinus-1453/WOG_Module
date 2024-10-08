﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OMENU__HELP_H__VER3__
#define __OMENU__HELP_H__VER3__

#include "zMenu.h"


  // sizeof 40h
  struct oSMenuKey {
    zSTRING name;         // sizeof 14h    offset 00h
    zSTRING internalName; // sizeof 14h    offset 14h
    zSTRING desc;         // sizeof 14h    offset 28h
    unsigned short key;   // sizeof 02h    offset 3Ch

    oSMenuKey() {}

    // user API
    #include "oSMenuKey.inl"
  };

  // sizeof CD0h
  class oCMenu_Help : public zCMenu {
  public:
    zCArray<oSMenuKey> keys; // sizeof 0Ch    offset CC4h

    oCMenu_Help() : zCtor( zCMenu ) {}

    // user API
    #include "oCMenu_Help.inl"
  };

  // sizeof 04h
  class oCHelpScreen {
  public:
    oCMenu_Help* help; // sizeof 04h    offset 00h

    oCHelpScreen() {}

    // user API
    #include "oCHelpScreen.inl"
  };


#endif // __OMENU__HELP_H__VER3__