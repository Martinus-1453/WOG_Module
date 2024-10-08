﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZVIEW_DIALOG_H__VER0__
#define __ZVIEW_DIALOG_H__VER0__


  // sizeof F8h
  class zCViewDialog : public zCViewPrint, public zCInputCallback {
  public:
    zCLASS_DECLARATION( zCViewDialog )

    int IsDone;      // sizeof 04h    offset F0h
    int IsActivated; // sizeof 04h    offset F4h

    zDefineInheritableCtor( zCViewDialog ) : zCtor( zCViewPrint ), zCtor( zCInputCallback ) {}
    void zCViewDialog_OnInit()                                          zCall( 0x00758450 );
    zCViewDialog() : zCtor( zCViewPrint ), zCtor( zCInputCallback )     zInit( zCViewDialog_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x007582C0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007250D0 );
    virtual ~zCViewDialog()                                             zCall( 0x00758590 );
    virtual int __fastcall IsActive()                                   zCall( 0x007250E0 );
    virtual void __fastcall Activate( int )                             zCall( 0x007250F0 );
    virtual int __fastcall HasFinished()                                zCall( 0x00725100 );
    virtual void __fastcall StartSelection()                            zCall( 0x00725110 );
    virtual void __fastcall StopSelection()                             zCall( 0x00725120 );
    /* for zCViewBase num : 8*/
    /* for zCViewDialog num : 1*/

    // user API
    #include "zCViewDialog.inl"
  };


#endif // __ZVIEW_DIALOG_H__VER0__