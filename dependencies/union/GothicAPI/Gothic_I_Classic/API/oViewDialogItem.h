﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OVIEW_DIALOG_ITEM_H__VER0__
#define __OVIEW_DIALOG_ITEM_H__VER0__


  // sizeof FCh
  class oCViewDialogItem : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItem )

    oCItem* Item; // sizeof 04h    offset F8h

    void oCViewDialogItem_OnInit()                                      zCall( 0x00727050 );
    oCViewDialogItem() : zCtor( zCViewDialog )                          zInit( oCViewDialogItem_OnInit() );
    void __fastcall SetItem( oCItem* )                                  zCall( 0x00727140 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00726F80 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00727040 );
    virtual ~oCViewDialogItem()                                         zCall( 0x007270B0 );
    virtual void __fastcall Blit()                                      zCall( 0x00727180 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogItem num : 1*/

    // user API
    #include "oCViewDialogItem.inl"
  };


#endif // __OVIEW_DIALOG_ITEM_H__VER0__