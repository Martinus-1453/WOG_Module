﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZSPY_TYPES_H__VER3__
#define __ZSPY_TYPES_H__VER3__


  // sizeof 18Ch
  struct zTErrorMessage {
    char username[20];  // sizeof 14h    offset 00h
    bool command;       // sizeof 01h    offset 14h
    int level;          // sizeof 04h    offset 18h
    char type[10];      // sizeof 0Ah    offset 1Ch
    char message[255];  // sizeof FFh    offset 26h
    char position[100]; // sizeof 64h    offset 125h

    zTErrorMessage() {}

    // user API
    //#include "zTErrorMessage.inl"
  };


#endif // __ZSPY_TYPES_H__VER3__