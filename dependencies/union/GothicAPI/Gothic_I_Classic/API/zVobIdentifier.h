// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZVOB_IDENTIFIER_H__VER0__
#define __ZVOB_IDENTIFIER_H__VER0__

  const unsigned long zVOB_ID_UNDEFINED = 0;

  // sizeof 04h
  class zCVobIdentifier {
  public:
    unsigned long id; // sizeof 04h    offset 00h

    zCVobIdentifier() {}

    // user API
    #include "zCVobIdentifier.inl"
  };


#endif // __ZVOB_IDENTIFIER_H__VER0__