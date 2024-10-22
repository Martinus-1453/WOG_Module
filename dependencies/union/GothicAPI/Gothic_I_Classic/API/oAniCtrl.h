﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OANI_CTRL_H__VER0__
#define __OANI_CTRL_H__VER0__

#include "zModel.h"
#include "zAiPlayer.h"
#include "zArchiver.h"

  const int WMODE_NONE          = 1;
  const int WMODE_CHOOSE        = 2;
  const int WMODE_STAND         = 3;
  const int ANI_NUM             = 10;
  const int ANI_HITLIMB_MAX     = 4;
  const int ANI_TURN_LAYER      = 20;
  const int ANI_MAX_HIT         = 10;
  const float ANI_TIME_INFINITE = -1000000.0f;

  enum {
    ANI_WALKMODE_RUN,
    ANI_WALKMODE_WALK,
    ANI_WALKMODE_SNEAK,
    ANI_WALKMODE_WATER,
    ANI_WALKMODE_SWIM,
    ANI_WALKMODE_DIVE
  };

  enum {
    ANI_ACTION_STAND,
    ANI_ACTION_WALK,
    ANI_ACTION_SNEAK,
    ANI_ACTION_RUN,
    ANI_ACTION_WATERWALK,
    ANI_ACTION_SWIM,
    ANI_ACTION_DIVE,
    ANI_ACTION_CHOOSEWEAPON
  };

  enum {
    ANI_HITTYPE_NONE,
    ANI_HITTYPE_FORWARD
  };

  // sizeof 11F8h
  class oCAniCtrl_Human : public zCAIPlayer {
  public:
    zCLASS_DECLARATION( oCAniCtrl_Human )

    // sizeof 18h
    struct oTComboInfo {
    public:
      int hitAni;          // sizeof 04h    offset 00h
      int hitOptFrame;     // sizeof 04h    offset 04h
      int hitEndFrame;     // sizeof 04h    offset 08h
      int comboStartFrame; // sizeof 04h    offset 0Ch
      int comboEndFrame;   // sizeof 04h    offset 10h
      int comboDir;        // sizeof 04h    offset 14h

      // user API
      #include "oCAniCtrl_Human_oTComboInfo.inl"
    };

    float angle_slide1;                        // sizeof 04h    offset 118h
    float angle_slide2;                        // sizeof 04h    offset 11Ch
    float angle_heading;                       // sizeof 04h    offset 120h
    float angle_horiz;                         // sizeof 04h    offset 124h
    float angle_ground;                        // sizeof 04h    offset 128h
    oCNpc* npc;                                // sizeof 04h    offset 12Ch
    zCVob* targetVob;                          // sizeof 04h    offset 130h
    zCVob* stopTurnVob;                        // sizeof 04h    offset 134h
    int stopTurnVobSign;                       // sizeof 04h    offset 138h
    zCModelNodeInst* hitlimb[ANI_HITLIMB_MAX]; // sizeof 10h    offset 13Ch
    int actionMode;                            // sizeof 04h    offset 14Ch
    int wmode;                                 // sizeof 04h    offset 150h
    int wmode_last;                            // sizeof 04h    offset 154h
    int wmode_selected;                        // sizeof 04h    offset 158h
    int changeweapon;                          // sizeof 04h    offset 15Ch
    int walkmode;                              // sizeof 04h    offset 160h
    int nextwalkmode;                          // sizeof 04h    offset 164h
    int lastRunWalkSneak;                      // sizeof 04h    offset 168h
    int always_walk;                           // sizeof 04h    offset 16Ch
    int do_jump;                               // sizeof 04h    offset 170h
    int defaultSurfaceAlign;                   // sizeof 04h    offset 174h
    float autoRollDirection;                   // sizeof 04h    offset 178h
    float lookTargetx;                         // sizeof 04h    offset 17Ch
    float lookTargety;                         // sizeof 04h    offset 180h
    int distance;                              // sizeof 04h    offset 184h
    zVEC3 hitpos;                              // sizeof 0Ch    offset 188h
    zSTRING limbname;                          // sizeof 14h    offset 194h
    float paradeBeginFrame;                    // sizeof 04h    offset 1A8h
    float paradeEndFrame;                      // sizeof 04h    offset 1ACh
    group {
      unsigned char canEnableNextCombo : 1;    // sizeof 01h    offset bit
      unsigned char endCombo           : 1;    // sizeof 01h    offset bit
      unsigned char comboCanHit        : 1;    // sizeof 01h    offset bit
      unsigned char hitPosUsed         : 1;    // sizeof 01h    offset bit
      unsigned char hitGraphical       : 1;    // sizeof 01h    offset bit
    };
    int comboNr;                               // sizeof 04h    offset 1B4h
    int comboMax;                              // sizeof 04h    offset 1B8h
    float lastHitAniFrame;                     // sizeof 04h    offset 1BCh
    int hitAniID;                              // sizeof 04h    offset 1C0h
    zCVob* hitTarget;                          // sizeof 04h    offset 1C4h
    oTComboInfo comboInfo[ANI_MAX_HIT];        // sizeof F0h    offset 1C8h
    float anioffset_lastper;                   // sizeof 04h    offset 2B8h
    float anioffset_thisper;                   // sizeof 04h    offset 2BCh
    float anioffset;                           // sizeof 04h    offset 2C0h
    int anioffset_ani;                         // sizeof 04h    offset 2C4h
    int s_dead1;                               // sizeof 04h    offset 2C8h
    int s_dead2;                               // sizeof 04h    offset 2CCh
    int s_hang;                                // sizeof 04h    offset 2D0h
    int t_hang_2_stand;                        // sizeof 04h    offset 2D4h
    int s_run[ANI_NUM];                        // sizeof 28h    offset 2D8h
    int t_run_2_runl[ANI_NUM];                 // sizeof 28h    offset 300h
    int t_runl_2_run[ANI_NUM];                 // sizeof 28h    offset 328h
    int s_runl[ANI_NUM];                       // sizeof 28h    offset 350h
    int t_runl_2_runr[ANI_NUM];                // sizeof 28h    offset 378h
    int t_runr_2_runl[ANI_NUM];                // sizeof 28h    offset 3A0h
    int s_runr[ANI_NUM];                       // sizeof 28h    offset 3C8h
    int t_runr_2_run[ANI_NUM];                 // sizeof 28h    offset 3F0h
    int t_runturnl[ANI_NUM];                   // sizeof 28h    offset 418h
    int t_runturnr[ANI_NUM];                   // sizeof 28h    offset 440h
    int t_runstrafel[ANI_NUM];                 // sizeof 28h    offset 468h
    int t_runstrafer[ANI_NUM];                 // sizeof 28h    offset 490h
    int t_run_2_runbl[ANI_NUM];                // sizeof 28h    offset 4B8h
    int t_runbl_2_run[ANI_NUM];                // sizeof 28h    offset 4E0h
    int s_runbl[ANI_NUM];                      // sizeof 28h    offset 508h
    int t_runbl_2_runbr[ANI_NUM];              // sizeof 28h    offset 530h
    int t_runbr_2_runbl[ANI_NUM];              // sizeof 28h    offset 558h
    int s_runbr[ANI_NUM];                      // sizeof 28h    offset 580h
    int t_runbr_2_run[ANI_NUM];                // sizeof 28h    offset 5A8h
    int t_jumpb[ANI_NUM];                      // sizeof 28h    offset 5D0h
    int t_run_2_walk[ANI_NUM];                 // sizeof 28h    offset 5F8h
    int t_walk_2_run[ANI_NUM];                 // sizeof 28h    offset 620h
    int t_run_2_sneak[ANI_NUM];                // sizeof 28h    offset 648h
    int t_sneak_2_run[ANI_NUM];                // sizeof 28h    offset 670h
    int s_walk[ANI_NUM];                       // sizeof 28h    offset 698h
    int t_walk_2_walkl[ANI_NUM];               // sizeof 28h    offset 6C0h
    int t_walkl_2_walk[ANI_NUM];               // sizeof 28h    offset 6E8h
    int s_walkl[ANI_NUM];                      // sizeof 28h    offset 710h
    int t_walkl_2_walkr[ANI_NUM];              // sizeof 28h    offset 738h
    int t_walkr_2_walkl[ANI_NUM];              // sizeof 28h    offset 760h
    int s_walkr[ANI_NUM];                      // sizeof 28h    offset 788h
    int t_walkr_2_walk[ANI_NUM];               // sizeof 28h    offset 7B0h
    int t_walkturnl[ANI_NUM];                  // sizeof 28h    offset 7D8h
    int t_walkturnr[ANI_NUM];                  // sizeof 28h    offset 800h
    int t_walkstrafel[ANI_NUM];                // sizeof 28h    offset 828h
    int t_walkstrafer[ANI_NUM];                // sizeof 28h    offset 850h
    int t_walk_2_walkbl[ANI_NUM];              // sizeof 28h    offset 878h
    int t_walkbl_2_walk[ANI_NUM];              // sizeof 28h    offset 8A0h
    int s_walkbl[ANI_NUM];                     // sizeof 28h    offset 8C8h
    int t_walkbl_2_walkbr[ANI_NUM];            // sizeof 28h    offset 8F0h
    int t_walkbr_2_walkbl[ANI_NUM];            // sizeof 28h    offset 918h
    int s_walkbr[ANI_NUM];                     // sizeof 28h    offset 940h
    int t_walkbr_2_walk[ANI_NUM];              // sizeof 28h    offset 968h
    int t_runl_2_jump[ANI_NUM];                // sizeof 28h    offset 990h
    int t_runr_2_jump[ANI_NUM];                // sizeof 28h    offset 9B8h
    int t_jump_2_runl[ANI_NUM];                // sizeof 28h    offset 9E0h
    int t_stand_2_jumpuplow;                   // sizeof 04h    offset A08h
    int s_jumpuplow;                           // sizeof 04h    offset A0Ch
    int t_jumpuplow_2_stand;                   // sizeof 04h    offset A10h
    int t_stand_2_jumpupmid;                   // sizeof 04h    offset A14h
    int s_jumpupmid;                           // sizeof 04h    offset A18h
    int t_jumpupmid_2_stand;                   // sizeof 04h    offset A1Ch
    int s_sneak[ANI_NUM];                      // sizeof 28h    offset A20h
    int t_sneak_2_sneakl[ANI_NUM];             // sizeof 28h    offset A48h
    int t_sneakl_2_sneak[ANI_NUM];             // sizeof 28h    offset A70h
    int s_sneakl[ANI_NUM];                     // sizeof 28h    offset A98h
    int t_sneakl_2_sneakr[ANI_NUM];            // sizeof 28h    offset AC0h
    int t_sneakr_2_sneakl[ANI_NUM];            // sizeof 28h    offset AE8h
    int s_sneakr[ANI_NUM];                     // sizeof 28h    offset B10h
    int t_sneakr_2_sneak[ANI_NUM];             // sizeof 28h    offset B38h
    int t_sneakturnl[ANI_NUM];                 // sizeof 28h    offset B60h
    int t_sneakturnr[ANI_NUM];                 // sizeof 28h    offset B88h
    int t_sneakstrafel[ANI_NUM];               // sizeof 28h    offset BB0h
    int t_sneakstrafer[ANI_NUM];               // sizeof 28h    offset BD8h
    int t_sneak_2_sneakbl[ANI_NUM];            // sizeof 28h    offset C00h
    int t_sneakbl_2_sneak[ANI_NUM];            // sizeof 28h    offset C28h
    int s_sneakbl[ANI_NUM];                    // sizeof 28h    offset C50h
    int t_sneakbl_2_sneakbr[ANI_NUM];          // sizeof 28h    offset C78h
    int t_sneakbr_2_sneakbl[ANI_NUM];          // sizeof 28h    offset CA0h
    int s_sneakbr[ANI_NUM];                    // sizeof 28h    offset CC8h
    int t_sneakbr_2_sneak[ANI_NUM];            // sizeof 28h    offset CF0h
    int t_walkl_2_aim[ANI_NUM];                // sizeof 28h    offset D18h
    int t_walkr_2_aim[ANI_NUM];                // sizeof 28h    offset D40h
    int t_walk_2_aim[ANI_NUM];                 // sizeof 28h    offset D68h
    int s_aim[ANI_NUM];                        // sizeof 28h    offset D90h
    int t_aim_2_walk[ANI_NUM];                 // sizeof 28h    offset DB8h
    int t_hitl[ANI_NUM];                       // sizeof 28h    offset DE0h
    int t_hitr[ANI_NUM];                       // sizeof 28h    offset E08h
    int t_hitback[ANI_NUM];                    // sizeof 28h    offset E30h
    int t_hitf[ANI_NUM];                       // sizeof 28h    offset E58h
    int s_hitf[ANI_NUM];                       // sizeof 28h    offset E80h
    int t_aim_2_defend[ANI_NUM];               // sizeof 28h    offset EA8h
    int s_defend[ANI_NUM];                     // sizeof 28h    offset ED0h
    int t_defend_2_aim[ANI_NUM];               // sizeof 28h    offset EF8h
    int t_paradeL[ANI_NUM];                    // sizeof 28h    offset F20h
    int t_paradeM[ANI_NUM];                    // sizeof 28h    offset F48h
    int t_paradeS[ANI_NUM];                    // sizeof 28h    offset F70h
    int t_hitfrun[ANI_NUM];                    // sizeof 28h    offset F98h
    int t_stumble;                             // sizeof 04h    offset FC0h
    int t_stumbleb;                            // sizeof 04h    offset FC4h
    int t_fallen_2_stand;                      // sizeof 04h    offset FC8h
    int t_fallenb_2_stand;                     // sizeof 04h    offset FCCh
    int t_walk_2_walkwl;                       // sizeof 04h    offset FD0h
    int t_walkwl_2_walk;                       // sizeof 04h    offset FD4h
    int s_walkwl;                              // sizeof 04h    offset FD8h
    int t_walkwl_2_walkwr;                     // sizeof 04h    offset FDCh
    int t_walkwr_2_walkwl;                     // sizeof 04h    offset FE0h
    int s_walkwr;                              // sizeof 04h    offset FE4h
    int t_walkwr_2_walk;                       // sizeof 04h    offset FE8h
    int t_walk_2_walkwbl;                      // sizeof 04h    offset FECh
    int t_walkwbl_2_walk;                      // sizeof 04h    offset FF0h
    int s_walkwbl;                             // sizeof 04h    offset FF4h
    int t_walkwbl_2_walkwbr;                   // sizeof 04h    offset FF8h
    int t_walkwbr_2_walkwbl;                   // sizeof 04h    offset FFCh
    int s_walkwbr;                             // sizeof 04h    offset 1000h
    int t_walkwbr_2_walk;                      // sizeof 04h    offset 1004h
    int _s_walk;                               // sizeof 04h    offset 1008h
    int _t_walk_2_walkl;                       // sizeof 04h    offset 100Ch
    int _t_walkl_2_walk;                       // sizeof 04h    offset 1010h
    int _s_walkl;                              // sizeof 04h    offset 1014h
    int _t_walkl_2_walkr;                      // sizeof 04h    offset 1018h
    int _t_walkr_2_walkl;                      // sizeof 04h    offset 101Ch
    int _s_walkr;                              // sizeof 04h    offset 1020h
    int _t_walkr_2_walk;                       // sizeof 04h    offset 1024h
    int _t_turnl;                              // sizeof 04h    offset 1028h
    int _t_turnr;                              // sizeof 04h    offset 102Ch
    int _t_strafel;                            // sizeof 04h    offset 1030h
    int _t_strafer;                            // sizeof 04h    offset 1034h
    int _t_walk_2_walkbl;                      // sizeof 04h    offset 1038h
    int _t_walkbl_2_walk;                      // sizeof 04h    offset 103Ch
    int _s_walkbl;                             // sizeof 04h    offset 1040h
    int _t_walkbl_2_walkbr;                    // sizeof 04h    offset 1044h
    int _t_walkbr_2_walkbl;                    // sizeof 04h    offset 1048h
    int _s_walkbr;                             // sizeof 04h    offset 104Ch
    int _t_walkbr_2_walk;                      // sizeof 04h    offset 1050h
    int s_jumpstand;                           // sizeof 04h    offset 1054h
    int t_stand_2_jumpstand;                   // sizeof 04h    offset 1058h
    int t_jumpstand_2_stand;                   // sizeof 04h    offset 105Ch
    int _t_jumpb;                              // sizeof 04h    offset 1060h
    int _t_stand_2_jump;                       // sizeof 04h    offset 1064h
    int _s_jump;                               // sizeof 04h    offset 1068h
    int t_jump_2_stand;                        // sizeof 04h    offset 106Ch
    int _t_stand_2_jumpup;                     // sizeof 04h    offset 1070h
    int _s_jumpup;                             // sizeof 04h    offset 1074h
    int _t_jumpup_2_falldn;                    // sizeof 04h    offset 1078h
    int _t_jump_2_falldn;                      // sizeof 04h    offset 107Ch
    int t_walkwl_2_swimf;                      // sizeof 04h    offset 1080h
    int s_swimf;                               // sizeof 04h    offset 1084h
    int t_swimf_2_walkwl;                      // sizeof 04h    offset 1088h
    int t_walkwbl_2_swimb;                     // sizeof 04h    offset 108Ch
    int s_swimb;                               // sizeof 04h    offset 1090h
    int t_swimb_2_walkwbl;                     // sizeof 04h    offset 1094h
    int t_swimf_2_swim;                        // sizeof 04h    offset 1098h
    int s_swim;                                // sizeof 04h    offset 109Ch
    int t_swim_2_swimf;                        // sizeof 04h    offset 10A0h
    int t_swim_2_swimb;                        // sizeof 04h    offset 10A4h
    int t_swimb_2_swim;                        // sizeof 04h    offset 10A8h
    int t_warn;                                // sizeof 04h    offset 10ACh
    int t_swim_2_dive;                         // sizeof 04h    offset 10B0h
    int s_dive;                                // sizeof 04h    offset 10B4h
    int t_divef_2_swim;                        // sizeof 04h    offset 10B8h
    int t_dive_2_divef;                        // sizeof 04h    offset 10BCh
    int s_divef;                               // sizeof 04h    offset 10C0h
    int t_divef_2_dive;                        // sizeof 04h    offset 10C4h
    int t_dive_2_drowned;                      // sizeof 04h    offset 10C8h
    int s_drowned;                             // sizeof 04h    offset 10CCh
    int t_swimturnl;                           // sizeof 04h    offset 10D0h
    int t_swimturnr;                           // sizeof 04h    offset 10D4h
    int t_diveturnl;                           // sizeof 04h    offset 10D8h
    int t_diveturnr;                           // sizeof 04h    offset 10DCh
    int _t_walkl_2_aim;                        // sizeof 04h    offset 10E0h
    int _t_walkr_2_aim;                        // sizeof 04h    offset 10E4h
    int _t_walk_2_aim;                         // sizeof 04h    offset 10E8h
    int _s_aim;                                // sizeof 04h    offset 10ECh
    int _t_aim_2_walk;                         // sizeof 04h    offset 10F0h
    int _t_hitl;                               // sizeof 04h    offset 10F4h
    int _t_hitr;                               // sizeof 04h    offset 10F8h
    int _t_hitback;                            // sizeof 04h    offset 10FCh
    int _t_hitf;                               // sizeof 04h    offset 1100h
    int _t_hitfstep;                           // sizeof 04h    offset 1104h
    int _s_hitf;                               // sizeof 04h    offset 1108h
    int _t_aim_2_defend;                       // sizeof 04h    offset 110Ch
    int _s_defend;                             // sizeof 04h    offset 1110h
    int _t_defend_2_aim;                       // sizeof 04h    offset 1114h
    int _t_paradeL;                            // sizeof 04h    offset 1118h
    int _t_paradeM;                            // sizeof 04h    offset 111Ch
    int _t_paradeS;                            // sizeof 04h    offset 1120h
    int _t_hitfrun;                            // sizeof 04h    offset 1124h
    int t_stand_2_iaim;                        // sizeof 04h    offset 1128h
    int s_iaim;                                // sizeof 04h    offset 112Ch
    int t_iaim_2_stand;                        // sizeof 04h    offset 1130h
    int t_iaim_2_idrop;                        // sizeof 04h    offset 1134h
    int s_idrop;                               // sizeof 04h    offset 1138h
    int t_idrop_2_stand;                       // sizeof 04h    offset 113Ch
    int t_iaim_2_ithrow;                       // sizeof 04h    offset 1140h
    int s_ithrow;                              // sizeof 04h    offset 1144h
    int t_ithrow_2_stand;                      // sizeof 04h    offset 1148h
    int t_stand_2_iget;                        // sizeof 04h    offset 114Ch
    int s_iget;                                // sizeof 04h    offset 1150h
    int t_iget_2_stand;                        // sizeof 04h    offset 1154h
    int s_oget;                                // sizeof 04h    offset 1158h
    int _t_stand_2_torch;                      // sizeof 04h    offset 115Ch
    int _s_torch;                              // sizeof 04h    offset 1160h
    int _t_torch_2_stand;                      // sizeof 04h    offset 1164h
    int hitani;                                // sizeof 04h    offset 1168h
    int help;                                  // sizeof 04h    offset 116Ch
    int help1;                                 // sizeof 04h    offset 1170h
    int help2;                                 // sizeof 04h    offset 1174h
    int s_fall;                                // sizeof 04h    offset 1178h
    int s_fallb;                               // sizeof 04h    offset 117Ch
    int s_fallen;                              // sizeof 04h    offset 1180h
    int s_fallenb;                             // sizeof 04h    offset 1184h
    int s_falldn;                              // sizeof 04h    offset 1188h
    int _t_runl_2_jump;                        // sizeof 04h    offset 118Ch
    int _t_runr_2_jump;                        // sizeof 04h    offset 1190h
    int _t_jump_2_runl;                        // sizeof 04h    offset 1194h
    int s_look;                                // sizeof 04h    offset 1198h
    int s_point;                               // sizeof 04h    offset 119Ch
    int dummy1;                                // sizeof 04h    offset 11A0h
    int dummy2;                                // sizeof 04h    offset 11A4h
    int dummy3;                                // sizeof 04h    offset 11A8h
    int dummy4;                                // sizeof 04h    offset 11ACh
    int s_weapon[ANI_NUM];                     // sizeof 28h    offset 11B0h
    int togglewalk;                            // sizeof 04h    offset 11D8h
    int t_stand_2_cast;                        // sizeof 04h    offset 11DCh
    int s_cast;                                // sizeof 04h    offset 11E0h
    int t_cast_2_shoot;                        // sizeof 04h    offset 11E4h
    int t_cast_2_stand;                        // sizeof 04h    offset 11E8h
    int s_shoot;                               // sizeof 04h    offset 11ECh
    int t_shoot_2_stand;                       // sizeof 04h    offset 11F0h
    int dummyLastVar;                          // sizeof 04h    offset 11F4h

    zDefineInheritableCtor( oCAniCtrl_Human ) : zCtor( zCAIPlayer ) {}
    void oCAniCtrl_Human_OnInit()                                       zCall( 0x0061B530 );
    oCAniCtrl_Human() : zCtor( zCAIPlayer )                             zInit( oCAniCtrl_Human_OnInit() );
    int StartAni( int, int )                                            zCall( 0x0061B7A0 );
    void SetNextAni( int, int )                                         zCall( 0x0061B980 );
    void InitAnimations()                                               zCall( 0x0061B9F0 );
    void SearchStandAni( int )                                          zCall( 0x0061C700 );
    void Reset()                                                        zCall( 0x0061CA60 );
    void InitAngleValuesForConsole()                                    zCall( 0x0061CAA0 );
    void SetScriptValues()                                              zCall( 0x0061CAF0 );
    void SetInterruptFollowAni( int )                                   zCall( 0x0061D400 );
    void InitAllAnis()                                                  zCall( 0x0061D5B0 );
    void SetWalkMode( int )                                             zCall( 0x006211E0 );
    void InitFightAnis( int )                                           zCall( 0x00621A70 );
    void SetFightAnis( int )                                            zCall( 0x00622400 );
    void StartAniWithOffset( int, float )                               zCall( 0x00622520 );
    void DoAniWithOffset()                                              zCall( 0x00622530 );
    void CorrectFightPosition()                                         zCall( 0x00622540 );
    zSTRING GetWalkModeString()                                         zCall( 0x00622730 );
    void CorrectAniStates()                                             zCall( 0x00622890 );
    int CheckWaterLevel()                                               zCall( 0x00622A20 );
    void SetAlwaysWalk( int )                                           zCall( 0x006236E0 );
    int IsAlwaysWalk()                                                  zCall( 0x006238B0 );
    int CanToggleWalkModeTo( int )                                      zCall( 0x006238E0 );
    int CanToggleWalkMode()                                             zCall( 0x00624540 );
    void ToggleWalkMode( int )                                          zCall( 0x00624E30 );
    int IsDead()                                                        zCall( 0x00624E70 );
    int IsFallen()                                                      zCall( 0x00625330 );
    int IsAiming()                                                      zCall( 0x00625440 );
    int IsStateAniActive( int )                                         zCall( 0x00625510 );
    int IsStateAniActive( zCModelAni* )                                 zCall( 0x00625590 );
    int IsStanding()                                                    zCall( 0x006255E0 );
    int IsJumpStanding()                                                zCall( 0x00625780 );
    int IsWalking()                                                     zCall( 0x006257E0 );
    int IsWalkingBackward()                                             zCall( 0x00625900 );
    void StopTurnAnis()                                                 zCall( 0x00625A20 );
    float Turn( float, int )                                            zCall( 0x00625A30 );
    void DoAutoRoll()                                                   zCall( 0x00625EE0 );
    void TurnDegrees( float, int )                                      zCall( 0x00625FB0 );
    int WallInFront( float )                                            zCall( 0x00626090 );
    int IsDefending()                                                   zCall( 0x00626620 );
    void GetFightLimbs()                                                zCall( 0x00626680 );
    void DoSparks( zVEC3&, zSTRING const& )                             zCall( 0x006270F0 );
    zCModelAniActive* GetLayerAni( int )                                zCall( 0x00627240 );
    int CheckLayerAni( int, zSTRING const& )                            zCall( 0x00627270 );
    int CheckLimbHit( zSTRING const&, zCList<zCModelNodeInst>& )        zCall( 0x006272B0 );
    void ShowWeaponTrail()                                              zCall( 0x00627330 );
    void StartHitCombo( int, zCVob* )                                   zCall( 0x00627560 );
    void StartHitGraphical( int, zCVob* )                               zCall( 0x006275C0 );
    int GetStopTurnVobSign()                                            zCall( 0x00627690 );
    int HitCombo( int )                                                 zCall( 0x006276F0 );
    zCVob* CheckHitTarget()                                             zCall( 0x00627A10 );
    void CreateHit( zCVob* )                                            zCall( 0x00627C80 );
    void HitInterrupt()                                                 zCall( 0x006280C0 );
    int HitGraphical()                                                  zCall( 0x00628100 );
    int IsInPreHit()                                                    zCall( 0x00628270 );
    int IsInPostHit()                                                   zCall( 0x006282C0 );
    int IsInCombo()                                                     zCall( 0x00628350 );
    zSTRING GetHitDirection()                                           zCall( 0x006283A0 );
    zCModelAniActive* IsParadeRunning()                                 zCall( 0x00628470 );
    int CanParade( oCNpc* )                                             zCall( 0x006284C0 );
    void StartParadeEffects( oCNpc* )                                   zCall( 0x00628580 );
    void StrafeLeft()                                                   zCall( 0x006289D0 );
    void StrafeRight()                                                  zCall( 0x00628A10 );
    int GetFootPos()                                                    zCall( 0x00628A50 );
    void PC_GoForward()                                                 zCall( 0x00628C00 );
    void PC_GoBackward()                                                zCall( 0x00628C50 );
    void PC_JumpForward()                                               zCall( 0x00628C90 );
    int CanJump( int )                                                  zCall( 0x00628E70 );
    int CanJumpLedge()                                                  zCall( 0x00628EE0 );
    int JumpForward()                                                   zCall( 0x00629070 );
    int Swim_CanClimbLedge()                                            zCall( 0x00629290 );
    void Swim_ClimbLedge()                                              zCall( 0x006292D0 );
    int CanWalkOnPoly( zVEC3 const& )                                   zCall( 0x00629430 );
    int DrawWeapon1( int, int, int )                                    zCall( 0x006294A0 );
    int ChooseNextWeapon2( int )                                        zCall( 0x00629740 );
    int DrawWeapon2()                                                   zCall( 0x00629B70 );
    int RemoveWeapon1()                                                 zCall( 0x00629E50 );
    int RemoveWeapon2()                                                 zCall( 0x0062A050 );
    void StartUp( zCVob* )                                              zCall( 0x0062A300 );
    void LerpFeetToTarget( int, int, zVEC3 const& )                     zCall( 0x0062A310 );
    void RelaxHandToTarget( zVEC3 const&, zVEC3 const&, int, float )    zCall( 0x0062A650 );
    void CheckSpecialStates()                                           zCall( 0x0062AF60 );
    void CheckJump()                                                    zCall( 0x0062BCD0 );
    void CheckFallStates()                                              zCall( 0x0062C1F0 );
    float CombineAniLerp( float, float, float, float )                  zCall( 0x0062CAF0 );
    int InterpolateCombineAni( float, float, int )                      zCall( 0x0062CB50 );
    void LookAtTarget()                                                 zCall( 0x0062CCD0 );
    void SetLookAtTarget( float, float )                                zCall( 0x0062CCF0 );
    void SetLookAtTarget( zVEC3& )                                      zCall( 0x0062CD10 );
    void SetLookAtTarget( zCVob* )                                      zCall( 0x0062CE10 );
    void StopLookAtTarget()                                             zCall( 0x0062CF70 );
    void StartCombineAni( zVEC3&, int, float, float )                   zCall( 0x0062D050 );
    void StartCombineAni( zCVob*, int, float, float )                   zCall( 0x0062D190 );
    void StopCombineAni( int )                                          zCall( 0x0062D2E0 );
    int DetectChasm( zVEC3 const&, zVEC3 const&, float&, zVEC3& )       zCall( 0x0062D2F0 );
    int IsInCriticalAni()                                               zCall( 0x0062D470 );
    void SetActionMode( int )                                           zCall( 0x0062DC70 );
    void _Stand()                                                       zCall( 0x0062DCF0 );
    void _Forward()                                                     zCall( 0x0062E160 );
    void _Backward()                                                    zCall( 0x0062E420 );
    void SetAnimations( int, zSTRING const& )                           zCall( 0x0062E700 );
    int TransitionToInvest()                                            zCall( 0x0062EBB0 );
    int TransitionToCast()                                              zCall( 0x0062ECA0 );
    int TransitionToStand()                                             zCall( 0x0062EEA0 );
    int IsInCastAni()                                                   zCall( 0x0062F060 );
    int IsInWeaponChoose()                                              zCall( 0x0062F130 );
    int GetWaterLevel()                                                 zCall( 0x0062F1D0 );
    int IsInWater()                                                     zCall( 0x0062F240 );
    int GetActionMode() const                                           zCall( 0x00746650 );
    static zSTRING GetWeaponString( int )                               zCall( 0x00626100 );
    static zSTRING GetWeaponHitString( int )                            zCall( 0x00626390 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0062F4C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0061B680 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0062DAD0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0062DB80 );
    virtual ~oCAniCtrl_Human()                                          zCall( 0x0061B6C0 );
    virtual void StartStandAni()                                        zCall( 0x0061CA40 );
    virtual void StartFallDownAni()                                     zCall( 0x0062BF10 );
    virtual void Init( oCNpc* )                                         zCall( 0x0061B740 );

    // user API
    #include "oCAniCtrl_Human.inl"
  };


#endif // __OANI_CTRL_H__VER0__