﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OVIEW_DIALOG_ITEM_H__VER1__
#define __OVIEW_DIALOG_ITEM_H__VER1__


  // sizeof FCh
  class oCViewDialogItem : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItem )

    oCItem* Item; // sizeof 04h    offset F8h

    void oCViewDialogItem_OnInit()                                      zCall( 0x007648B0 );
    oCViewDialogItem() : zCtor( zCViewDialog )                          zInit( oCViewDialogItem_OnInit() );
    void __fastcall SetItem( oCItem* )                                  zCall( 0x007649B0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x007647E0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007648A0 );
    virtual ~oCViewDialogItem()                                         zCall( 0x00764910 );
    virtual void __fastcall Blit()                                      zCall( 0x00764A00 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogItem num : 1*/

    // user API
    #include "oCViewDialogItem.inl"
  };


#endif // __OVIEW_DIALOG_ITEM_H__VER1__