// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZVOB_IDENTIFIER_H__VER1__
#define __ZVOB_IDENTIFIER_H__VER1__

  const unsigned long zVOB_ID_UNDEFINED = 0;

  // sizeof 04h
  class zCVobIdentifier {
  public:
    unsigned long id; // sizeof 04h    offset 00h

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };


#endif // __ZVOB_IDENTIFIER_H__VER1__