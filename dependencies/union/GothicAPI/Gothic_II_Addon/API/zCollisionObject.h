﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZCOLLISION_OBJECT_H__VER3__
#define __ZCOLLISION_OBJECT_H__VER3__


  // sizeof 0Ch
  class zCCollisionObjectDef {
  public:
    zCCollisionObject*( *m_createNewInstance )( void ); // sizeof 04h    offset 00h
    int m_bIsVolatile;                                  // sizeof 04h    offset 04h
    int m_iIndex;                                       // sizeof 04h    offset 08h

    zCCollisionObjectDef() {}
    void zCCollisionObjectDef_OnInit( int, zCCollisionObject*( __cdecl* )() ) zCall( 0x0054D250 );
    zCCollisionObjectDef( int a0, zCCollisionObject*( __cdecl* a1 )() )       zInit( zCCollisionObjectDef_OnInit( a0, a1 ));
    ~zCCollisionObjectDef()                                                   zCall( 0x0054D380 );

    // static properties
    static zCArray<zCCollisionObjectDef*>*& s_aoCollObjClassList;

    // user API
    #include "zCCollisionObjectDef.inl"
  };

  // sizeof 8Ch
  class zCCollisionObject {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollisionObject )

    zMAT4 m_oTrafoOld;                      // sizeof 40h    offset 04h
    zMAT4 m_oTrafoNew;                      // sizeof 40h    offset 44h
    void* m_pvClientData;                   // sizeof 04h    offset 84h
    group {
      unsigned char m_bHintTranslation : 1; // sizeof 01h    offset bit
      unsigned char m_bHintRotation    : 1; // sizeof 01h    offset bit
    };

    zDefineInheritableCtor( zCCollisionObject ) {}
    zCCollisionObject() {}
    void __fastcall CalcIntermediateTrafo( float, zMAT4& )                                                           zCall( 0x0054D400 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x0054D1A0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x0054D1E0 );
    virtual ~zCCollisionObject()                                                                                     zCall( 0x0054D230 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x0054D1F0 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x0054D200 );
    virtual float __fastcall GetAdaptiveStepSize()                                                                   zCall( 0x0054D210 );
    virtual int __fastcall SuppressCollisionResponse()                                                               zCall( 0x0054D220 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x0054D520 );

    // user API
    #include "zCCollisionObject.inl"
  };


#endif // __ZCOLLISION_OBJECT_H__VER3__