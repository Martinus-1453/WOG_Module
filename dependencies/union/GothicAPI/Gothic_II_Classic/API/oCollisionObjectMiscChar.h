﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OCOLLISION_OBJECT_MISC_CHAR_H__VER2__
#define __OCOLLISION_OBJECT_MISC_CHAR_H__VER2__


  // sizeof 144h
  class oCCollObjectCharacter : public zCCollObjectCharacter {
  public:
    int comeNearerCounter;          // sizeof 04h    offset 13Ch
    const zCVob* mustNotComeNearer; // sizeof 04h    offset 140h

    void oCCollObjectCharacter_OnInit()                      zCall( 0x007A7CE0 );
    oCCollObjectCharacter() : zCtor( zCCollObjectCharacter ) zInit( oCCollObjectCharacter_OnInit() );
    static zCCollisionObject* _CreateNewInstance()           zCall( 0x007A7C50 );
    static void S_RegisterCollisionTestFuncs()               zCall( 0x007A7E50 );
    virtual zCCollisionObjectDef* GetCollObjClass() const    zCall( 0x007A7CD0 );
    virtual ~oCCollObjectCharacter()                         zCall( 0x007A7D30 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const        zCall( 0x007A7E10 );
    virtual int IsDead() const                               zCall( 0x007A7D80 );
    virtual int DontLetHimComeNearer( zCVob const* ) const   zCall( 0x007A7DE0 );
    virtual float TurnSpeed() const                          zCall( 0x007A7D40 );
    virtual void PushAround( zVEC3 const& )                  zCall( 0x007A7DB0 );

    // static properties
    static zCCollisionObjectDef& s_oCollObjClass;

    // user API
    #include "oCCollObjectCharacter.inl"
  };


#endif // __OCOLLISION_OBJECT_MISC_CHAR_H__VER2__