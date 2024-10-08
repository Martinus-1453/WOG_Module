﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OVIS_FX_H__VER1__
#define __OVIS_FX_H__VER1__

#include "z3d.h"
#include "zAi.h"
#include "zParticle.h"
#include "zParser.h"
#include "zKbSplines.h"
#include "zSound.h"
#include "zVobMisc.h"

  const int MAX_SPL_LEVEL          = 20;
  const int VFX_MAX_POS_SAMPLES    = 10;
  const int VFX_NUM_USERSTRINGS    = 3;
  const float VFX_LIFESPAN_FOREVER = -1;

  enum zTVFXState {
    zVFXSTATE_UNDEF,
    zVFXSTATE_OPEN,
    zVFXSTATE_INIT,
    zVFXSTATE_INVESTNEXT,
    zVFXSTATE_CAST,
    zVFXSTATE_STOP,
    zVFXSTATE_COLLIDE
  };

  enum TEmTrajectoryMode {
    EM_TRJ_UNDEF,
    EM_TRJ_FIXED,
    EM_TRJ_TARGET,
    EM_TRJ_LINE   = 4,
    EM_TRJ_SPLINE = 8,
    EM_TRJ_RANDOM = 16,
    EM_TRJ_CIRCLE = 32,
    EM_TRJ_FOLLOW = 64
  };

  enum TTrjLoopMode {
    TRJ_LOOP_NONE,
    TRJ_LOOP_RESTART,
    TRJ_LOOP_PINGPONG,
    TRJ_LOOP_HALT
  };

  enum TEaseFunc {
    TEASEFUNC_LINEAR,
    TEASEFUNC_SINE,
    TEASEFUNC_EXP
  };

  enum TActionColl {
    TACTION_COLL_NONE,
    TACTION_COLL_COLLIDE,
    TACTION_COLL_BOUNCE,
    TACTION_COLL_CREATE      = 4,
    TACTION_COLL_CREATE_ONCE = 8,
    TACTION_COLL_NORESP      = 16,
    TACTION_COLL_CREATE_QUAD = 32
  };

  // sizeof 5Ch
  class oCTrajectory {
  public:
    zCArray<zCPositionKey*> keyList; // sizeof 0Ch    offset 00h
    zCKBSpline* spl;                 // sizeof 04h    offset 0Ch
    int mode;                        // sizeof 04h    offset 10h
    float length;                    // sizeof 04h    offset 14h
    zMAT4 res;                       // sizeof 40h    offset 18h
    int lastKey;                     // sizeof 04h    offset 58h

    oCTrajectory() {}
    void Calc()                                                         zCall( 0x0048AE10 );
    void Changed()                                                      zCall( 0x0048B180 );
    zMAT4 Interpolate( float )                                          zCall( 0x0048B190 );
    zMAT4 InterpolateN( float )                                         zCall( 0x0048B600 );
    void Draw()                                                         zCall( 0x0048B710 );
    void Clear()                                                        zCall( 0x0048B990 );
    zVEC3 RecalcByColl( zVEC3 const&, zVEC3 const&, zVEC3 const&, int ) zCall( 0x0048BA50 );
    void ApplyGrav( float const& )                                      zCall( 0x0048BF00 );
    void SetByList( zCArray<zCVob*> )                                   zCall( 0x0048BF80 );
    int VobCross( zCVob const* )                                        zCall( 0x0048C120 );
    ~oCTrajectory()                                                     zCall( 0x0048D580 );
    void InsertKey( zMAT4& )                                            zCall( 0x004942C0 );
    zMAT4 GetKey( int )                                                 zCall( 0x004943F0 );
    void SetKey( int, zMAT4 )                                           zCall( 0x004944E0 );
    int GetNumKeys()                                                    zCall( 0x00494510 );

    // user API
    #include "oCTrajectory.inl"
  };

  // sizeof 1D4h
  class oCEmitterKey {
  public:
    zSTRING visName_S;                     // sizeof 14h    offset 00h
    float visSizeScale;                    // sizeof 04h    offset 14h
    float scaleDuration;                   // sizeof 04h    offset 18h
    float pfx_ppsValue;                    // sizeof 04h    offset 1Ch
    int pfx_ppsIsSmoothChg;                // sizeof 04h    offset 20h
    int pfx_ppsIsLoopingChg;               // sizeof 04h    offset 24h
    float pfx_scTime;                      // sizeof 04h    offset 28h
    zSTRING pfx_flyGravity_S;              // sizeof 14h    offset 2Ch
    zSTRING pfx_shpDim_S;                  // sizeof 14h    offset 40h
    int pfx_shpIsVolumeChg;                // sizeof 04h    offset 54h
    float pfx_shpScaleFPS;                 // sizeof 04h    offset 58h
    float pfx_shpDistribWalkSpeed;         // sizeof 04h    offset 5Ch
    zSTRING pfx_shpOffsetVec_S;            // sizeof 14h    offset 60h
    zSTRING pfx_shpDistribType_S;          // sizeof 14h    offset 74h
    zSTRING pfx_dirMode_S;                 // sizeof 14h    offset 88h
    zSTRING pfx_dirFOR_S;                  // sizeof 14h    offset 9Ch
    zSTRING pfx_dirModeTargetFOR_S;        // sizeof 14h    offset B0h
    zSTRING pfx_dirModeTargetPos_S;        // sizeof 14h    offset C4h
    float pfx_velAvg;                      // sizeof 04h    offset D8h
    float pfx_lspPartAvg;                  // sizeof 04h    offset DCh
    float pfx_visAlphaStart;               // sizeof 04h    offset E0h
    zSTRING lightPresetName;               // sizeof 14h    offset E4h
    float lightRange;                      // sizeof 04h    offset F8h
    zSTRING sfxID;                         // sizeof 14h    offset FCh
    int sfxIsAmbient;                      // sizeof 04h    offset 110h
    zSTRING emCreateFXID;                  // sizeof 14h    offset 114h
    float emFlyGravity;                    // sizeof 04h    offset 128h
    zSTRING emSelfRotVel_S;                // sizeof 14h    offset 12Ch
    zSTRING emTrjMode_S;                   // sizeof 14h    offset 140h
    float emTrjEaseVel;                    // sizeof 04h    offset 154h
    int emCheckCollision;                  // sizeof 04h    offset 158h
    float emFXLifeSpan;                    // sizeof 04h    offset 15Ch
    unsigned char dScriptEnd;              // sizeof 01h    offset 160h
    zVEC3 pfx_flyGravity;                  // sizeof 0Ch    offset 164h
    zVEC3 pfx_shpOffsetVec;                // sizeof 0Ch    offset 170h
    zTPFX_DistribType pfx_shpDistribType;  // sizeof 04h    offset 17Ch
    zTPFX_EmitterDirMode pfx_dirMode;      // sizeof 04h    offset 180h
    zTPFX_EmitterFOR pfx_dirFOR;           // sizeof 04h    offset 184h
    zTPFX_EmitterFOR pfx_dirModeTargetFOR; // sizeof 04h    offset 188h
    zVEC3 pfx_dirModeTargetPos;            // sizeof 0Ch    offset 18Ch
    zVEC3 emSelfRotVel;                    // sizeof 0Ch    offset 198h
    int emTrjMode;                         // sizeof 04h    offset 1A4h
    zSTRING name;                          // sizeof 14h    offset 1A8h
    zCVob* vob;                            // sizeof 04h    offset 1BCh
    zVEC3 targetPos;                       // sizeof 0Ch    offset 1C0h
    zCSoundFX* sfx;                        // sizeof 04h    offset 1CCh
    int sfxHnd;                            // sizeof 04h    offset 1D0h

    void oCEmitterKey_OnInit()                       zCall( 0x0048C1C0 );
    oCEmitterKey()                                   zInit( oCEmitterKey_OnInit() );
    ~oCEmitterKey()                                  zCall( 0x0048C4B0 );
    void SetByScript( zSTRING const& )               zCall( 0x0048C770 );
    void ParseStrings()                              zCall( 0x0048C9B0 );
    void Edit()                                      zCall( 0x0049CD50 );
    void SetDefaultByFX( oCVisualFX* )               zCall( 0x004A09C0 );
    static void CreateNewScriptKey( zSTRING const& ) zCall( 0x0049D1C0 );

    // user API
    #include "oCEmitterKey.inl"
  };

  // sizeof 1Ch
  struct zSVisualFXColl {
    zCVob* foundVob;         // sizeof 04h    offset 00h
    zVEC3 foundContactPoint; // sizeof 0Ch    offset 04h
    zVEC3 foundNormal;       // sizeof 0Ch    offset 10h

    zSVisualFXColl() {}

    // user API
    #include "zSVisualFXColl.inl"
  };

  // sizeof 5C8h
  class oCVisualFX : public zCEffect {
  public:
    zCLASS_DECLARATION( oCVisualFX )

    zSTRING visName_S;                       // sizeof 14h    offset 100h
    zSTRING visSize_S;                       // sizeof 14h    offset 114h
    float visAlpha;                          // sizeof 04h    offset 128h
    zSTRING visAlphaBlendFunc_S;             // sizeof 14h    offset 12Ch
    float visTexAniFPS;                      // sizeof 04h    offset 140h
    int visTexAniIsLooping;                  // sizeof 04h    offset 144h
    zSTRING emTrjMode_S;                     // sizeof 14h    offset 148h
    zSTRING emTrjOriginNode_S;               // sizeof 14h    offset 15Ch
    zSTRING emTrjTargetNode_S;               // sizeof 14h    offset 170h
    float emTrjTargetRange;                  // sizeof 04h    offset 184h
    float emTrjTargetAzi;                    // sizeof 04h    offset 188h
    float emTrjTargetElev;                   // sizeof 04h    offset 18Ch
    int emTrjNumKeys;                        // sizeof 04h    offset 190h
    int emTrjNumKeysVar;                     // sizeof 04h    offset 194h
    float emTrjAngleElevVar;                 // sizeof 04h    offset 198h
    float emTrjAngleHeadVar;                 // sizeof 04h    offset 19Ch
    float emTrjKeyDistVar;                   // sizeof 04h    offset 1A0h
    zSTRING emTrjLoopMode_S;                 // sizeof 14h    offset 1A4h
    zSTRING emTrjEaseFunc_S;                 // sizeof 14h    offset 1B8h
    float emTrjEaseVel;                      // sizeof 04h    offset 1CCh
    float emTrjDynUpdateDelay;               // sizeof 04h    offset 1D0h
    int emTrjDynUpdateTargetOnly;            // sizeof 04h    offset 1D4h
    zSTRING emFXCreate_S;                    // sizeof 14h    offset 1D8h
    zSTRING emFXInvestOrigin_S;              // sizeof 14h    offset 1ECh
    zSTRING emFXInvestTarget_S;              // sizeof 14h    offset 200h
    float emFXTriggerDelay;                  // sizeof 04h    offset 214h
    int emFXCreatedOwnTrj;                   // sizeof 04h    offset 218h
    zSTRING emActionCollDyn_S;               // sizeof 14h    offset 21Ch
    zSTRING emActionCollStat_S;              // sizeof 14h    offset 230h
    zSTRING emFXCollStat_S;                  // sizeof 14h    offset 244h
    zSTRING emFXCollDyn_S;                   // sizeof 14h    offset 258h
    zSTRING emFXCollStatAlign_S;             // sizeof 14h    offset 26Ch
    zSTRING emFXCollDynAlign_S;              // sizeof 14h    offset 280h
    float emFXLifeSpan;                      // sizeof 04h    offset 294h
    int emCheckCollision;                    // sizeof 04h    offset 298h
    int emAdjustShpToOrigin;                 // sizeof 04h    offset 29Ch
    float emInvestNextKeyDuration;           // sizeof 04h    offset 2A0h
    float emFlyGravity;                      // sizeof 04h    offset 2A4h
    zSTRING emSelfRotVel_S;                  // sizeof 14h    offset 2A8h
    zSTRING userString[VFX_NUM_USERSTRINGS]; // sizeof 3Ch    offset 2BCh
    zSTRING lightPresetName;                 // sizeof 14h    offset 2F8h
    zSTRING sfxID;                           // sizeof 14h    offset 30Ch
    int sfxIsAmbient;                        // sizeof 04h    offset 320h
    int sendAssessMagic;                     // sizeof 04h    offset 324h
    float secsPerDamage;                     // sizeof 04h    offset 328h
    unsigned char dScriptEnd;                // sizeof 01h    offset 32Ch
    zVEC3 visSize;                           // sizeof 0Ch    offset 330h
    int emTrjMode;                           // sizeof 04h    offset 33Ch
    int emActionCollDyn;                     // sizeof 04h    offset 340h
    int emActionCollStat;                    // sizeof 04h    offset 344h
    zVEC3 emSelfRotVel;                      // sizeof 0Ch    offset 348h
    TEaseFunc emTrjEaseFunc;                 // sizeof 04h    offset 354h
    TTrjLoopMode emTrjLoopMode;              // sizeof 04h    offset 358h
    zTVFXState fxState;                      // sizeof 04h    offset 35Ch
    oCVisualFX* root;                        // sizeof 04h    offset 360h
    oCVisualFX* parent;                      // sizeof 04h    offset 364h
    oCVisualFX* fxInvestOrigin;              // sizeof 04h    offset 368h
    oCVisualFX* fxInvestTarget;              // sizeof 04h    offset 36Ch
    oCVisualFXAI* ai;                        // sizeof 04h    offset 370h
    int fxInvestOriginInitialized;           // sizeof 04h    offset 374h
    int fxInvestTargetInitialized;           // sizeof 04h    offset 378h
    int fxInvestStopped;                     // sizeof 04h    offset 37Ch
    zCArray<oCVisualFX*> fxList;             // sizeof 0Ch    offset 380h
    zCArray<oCVisualFX*> childList;          // sizeof 0Ch    offset 38Ch
    zCArray<oCEmitterKey*> emKeyList;        // sizeof 0Ch    offset 398h
    zCArray<zCVob*> vobList;                 // sizeof 0Ch    offset 3A4h
    zCArray<zCVob*> ignoreVobList;           // sizeof 0Ch    offset 3B0h
    zCArray<zCVob*> allowedCollisionVobList; // sizeof 0Ch    offset 3BCh
    zCArray<zCVob*> collidedVobs;            // sizeof 0Ch    offset 3C8h
    zCArray<zSVisualFXColl>queuedCollisions; // sizeof 0Ch    offset 3D4h
    oCTrajectory trajectory;                 // sizeof 5Ch    offset 3E0h
    zCEarthquake* earthQuake;                // sizeof 04h    offset 43Ch
    zCVobScreenFX* screenFX;                 // sizeof 04h    offset 440h
    float screenFXTime;                      // sizeof 04h    offset 444h
    int screenFXDir;                         // sizeof 04h    offset 448h
    zCModelNodeInst* orgNode;                // sizeof 04h    offset 44Ch
    zCModelNodeInst* targetNode;             // sizeof 04h    offset 450h
    zCVisual* lastSetVisual;                 // sizeof 04h    offset 454h
    zCVob* origin;                           // sizeof 04h    offset 458h
    zCVob* inflictor;                        // sizeof 04h    offset 45Ch
    zCVob* target;                           // sizeof 04h    offset 460h
    zCVobLight* light;                       // sizeof 04h    offset 464h
    float lightRange;                        // sizeof 04h    offset 468h
    zCSoundFX* sfx;                          // sizeof 04h    offset 46Ch
    int sfxHnd;                              // sizeof 04h    offset 470h
    zSTRING fxName;                          // sizeof 14h    offset 474h
    oCEmitterKey* fxBackup;                  // sizeof 04h    offset 488h
    oCEmitterKey* lastSetKey;                // sizeof 04h    offset 48Ch
    oCEmitterKey* actKey;                    // sizeof 04h    offset 490h
    int level;                               // sizeof 04h    offset 494h
    int collisionOccured;                    // sizeof 04h    offset 498h
    int collisionCtr;                        // sizeof 04h    offset 49Ch
    int showVisual;                          // sizeof 04h    offset 4A0h
    int isChild;                             // sizeof 04h    offset 4A4h
    int isDeleted;                           // sizeof 04h    offset 4A8h
    int initialized;                         // sizeof 04h    offset 4ACh
    int shouldDelete;                        // sizeof 04h    offset 4B0h
    int lightning;                           // sizeof 04h    offset 4B4h
    int queueSetLevel;                       // sizeof 04h    offset 4B8h
    float frameTime;                         // sizeof 04h    offset 4BCh
    float collisionTime;                     // sizeof 04h    offset 4C0h
    float deleteTime;                        // sizeof 04h    offset 4C4h
    float damageTime;                        // sizeof 04h    offset 4C8h
    zVEC3 targetPos;                         // sizeof 0Ch    offset 4CCh
    zVEC3 lastTrjDir;                        // sizeof 0Ch    offset 4D8h
    zVEC3 keySize;                           // sizeof 0Ch    offset 4E4h
    zVEC3 actSize;                           // sizeof 0Ch    offset 4F0h
    zVEC3 castEndSize;                       // sizeof 0Ch    offset 4FCh
    float nextLevelTime;                     // sizeof 04h    offset 508h
    float easeTime;                          // sizeof 04h    offset 50Ch
    float age;                               // sizeof 04h    offset 510h
    float trjUpdateTime;                     // sizeof 04h    offset 514h
    float emTrjDist;                         // sizeof 04h    offset 518h
    float trjSign;                           // sizeof 04h    offset 51Ch
    float levelTime;                         // sizeof 04h    offset 520h
    float lifeSpanTimer;                     // sizeof 04h    offset 524h
    float damage;                            // sizeof 04h    offset 528h
    int damageType;                          // sizeof 04h    offset 52Ch
    int spellType;                           // sizeof 04h    offset 530h
    int spellTargetTypes;                    // sizeof 04h    offset 534h
    float savePpsValue;                      // sizeof 04h    offset 538h
    zVEC2 saveVisSizeStart;                  // sizeof 08h    offset 53Ch
    zVEC3 transRing[VFX_MAX_POS_SAMPLES];    // sizeof 78h    offset 544h
    int ringPos;                             // sizeof 04h    offset 5BCh
    int emTrjFollowHitLastCheck;             // sizeof 04h    offset 5C0h
    int bIsProjectile;                       // sizeof 04h    offset 5C4h

    zDefineInheritableCtor( oCVisualFX ) : zCtor( zCEffect ) {}
    void oCVisualFX_OnInit()                                                                             zCall( 0x0048D120 );
    oCVisualFX() : zCtor( zCEffect )                                                                     zInit( oCVisualFX_OnInit() );
    void CreateHierachy()                                                                                zCall( 0x0048E490 );
    void DisposeHierachy()                                                                               zCall( 0x0048E760 );
    void InitValues()                                                                                    zCall( 0x0048ECB0 );
    void ParseStrings()                                                                                  zCall( 0x0048F320 );
    void UpdateFXByEmitterKey( oCEmitterKey* )                                                           zCall( 0x00491380 );
    void CreateBackup()                                                                                  zCall( 0x00491BD0 );
    int FindKey( zSTRING const& )                                                                        zCall( 0x00491BE0 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zCVob const*, zCVob const* )                            zCall( 0x00492530 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zMAT4 const& )                                          zCall( 0x00492890 );
    void CreateInvestFX()                                                                                zCall( 0x00494BF0 );
    void InitInvestFX()                                                                                  zCall( 0x00494DB0 );
    void StopInvestFX()                                                                                  zCall( 0x00494F10 );
    void SetShowVisual( int )                                                                            zCall( 0x00497260 );
    void InitEffect()                                                                                    zCall( 0x00497B80 );
    void EndEffect( int )                                                                                zCall( 0x00498050 );
    int ProcessQueuedCollisions()                                                                        zCall( 0x00498AA0 );
    int ProcessCollision( zSVisualFXColl& )                                                              zCall( 0x00498B50 );
    int CheckDeletion()                                                                                  zCall( 0x00499CC0 );
    void UpdateActKey()                                                                                  zCall( 0x0049A110 );
    void DoMovements()                                                                                   zCall( 0x0049A390 );
    int CheckDelayedTrigger()                                                                            zCall( 0x0049AEE0 );
    void AdjustShapeToOrigin()                                                                           zCall( 0x0049B170 );
    void UpdateEffects()                                                                                 zCall( 0x0049B630 );
    void Edit()                                                                                          zCall( 0x0049C480 );
    void SetupEmitterKeysByVisual()                                                                      zCall( 0x004A0E40 );
    zSTRING const& GetName() const                                                                       zCall( 0x0077F620 );
    static void RemoveInstancesOfClass( zCClassDef&, int )                                               zCall( 0x0048CF00 );
    static void PreSaveGameProcessing( int )                                                             zCall( 0x0048D100 );
    static void PostSaveGameProcessing()                                                                 zCall( 0x0048D110 );
    static void InitParser()                                                                             zCall( 0x0048E980 );
    static void ExitParser()                                                                             zCall( 0x0048EC80 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zCVob const*, zCVob const*, int, float, int, int ) zCall( 0x00491D60 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zVEC3 const&, zCVob const*, int, float, int, int ) zCall( 0x004920B0 );
    static zCObject* _CreateNewInstance()                                                                zCall( 0x0049BCE0 );
    static void CreateNewScriptFX( zSTRING const& )                                                      zCall( 0x0049CAC0 );
    static void FxConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049D450 );
    static void EmConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049E2D0 );
    static int FxConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049E5D0 );
    static int EmConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049F400 );
    virtual zCClassDef* _GetClassDef() const                                                             zCall( 0x0048D640 );
    virtual void Archive( zCArchiver& )                                                                  zCall( 0x0049BAA0 );
    virtual void Unarchive( zCArchiver& )                                                                zCall( 0x0049BAB0 );
    virtual ~oCVisualFX()                                                                                zCall( 0x0048D880 );
    virtual void OnTick()                                                                                zCall( 0x0049B9C0 );
    virtual int CanThisCollideWith( zCVob* )                                                             zCall( 0x00499A80 );
    virtual void Open()                                                                                  zCall( 0x00494FC0 );
    virtual void SetOrigin( zCVob* )                                                                     zCall( 0x00494950 );
    virtual void SetTarget( zCVob* )                                                                     zCall( 0x00494A20 );
    virtual void SetTarget( zVEC3& )                                                                     zCall( 0x00494B80 );
    virtual void SetInflictor( zCVob* )                                                                  zCall( 0x004949C0 );
    virtual zCVob* GetOrigin()                                                                           zCall( 0x0048D650 );
    virtual zCVob* GetTarget()                                                                           zCall( 0x0048D660 );
    virtual zCVob* GetInflictor()                                                                        zCall( 0x0048D670 );
    virtual void Init( zCVob const*, zVEC3 const& )                                                      zCall( 0x00495520 );
    virtual void Init( zCVob const*, zCVob const*, zCVob const* )                                        zCall( 0x00495640 );
    virtual void Init( zCArray<zCVob*> const& )                                                          zCall( 0x00495DA0 );
    virtual void InvestNext()                                                                            zCall( 0x00495F30 );
    virtual void SetLevel( int )                                                                         zCall( 0x00496310 );
    virtual int GetLevel() const                                                                         zCall( 0x00496710 );
    virtual void Cast( int )                                                                             zCall( 0x00496720 );
    virtual void Stop( int )                                                                             zCall( 0x004973B0 );
    virtual void Kill()                                                                                  zCall( 0x004977A0 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* )                                               zCall( 0x0048D680 );
    virtual int CanBeDeleted()                                                                           zCall( 0x00497A40 );
    virtual int IsFinished()                                                                             zCall( 0x00497A80 );
    virtual int IsLooping()                                                                              zCall( 0x00497B10 );
    virtual void SetByScript( zSTRING const& )                                                           zCall( 0x00490910 );
    virtual void SetDuration( float )                                                                    zCall( 0x0048D690 );
    virtual void Reset()                                                                                 zCall( 0x00495330 );
    virtual void ReportCollision( zCCollisionReport const& )                                             zCall( 0x004980A0 );
    virtual void SetCollisionEnabled( int )                                                              zCall( 0x004907F0 );
    virtual void SetCollisionCandidates( zCArray<zCVob*> )                                               zCall( 0x004998A0 );
    virtual void GetCollisionCandidates( zCArray<zCVob*>& )                                              zCall( 0x0048D6A0 );
    virtual int GetNumCollisionCandidates()                                                              zCall( 0x0048D750 );
    virtual int GetCollidedCandidates( zCArray<zCVob*>& )                                                zCall( 0x004999B0 );
    virtual void SetDamage( float )                                                                      zCall( 0x0048D760 );
    virtual void SetDamageType( int )                                                                    zCall( 0x0048D770 );
    virtual float GetDamage() const                                                                      zCall( 0x0048D780 );
    virtual int GetDamageType() const                                                                    zCall( 0x0048D790 );
    virtual int IsASpell()                                                                               zCall( 0x0048D7A0 );
    virtual void SetSpellType( int )                                                                     zCall( 0x0048D7B0 );
    virtual int GetSpellType() const                                                                     zCall( 0x0048D7C0 );
    virtual int GetSpellTargetTypes() const                                                              zCall( 0x0048D7D0 );
    virtual void SetSpellTargetTypes( int )                                                              zCall( 0x0048D7E0 );
    virtual int GetIsProjectile()                                                                        zCall( 0x0048D7F0 );
    virtual void SetIsProjectile( int )                                                                  zCall( 0x0048D800 );
    virtual void SetVisualByString( zSTRING const& )                                                     zCall( 0x0048F6A0 );
    virtual void CalcTrajectory( int const& )                                                            zCall( 0x00492CF0 );
    virtual void Collide( int )                                                                          zCall( 0x00496FC0 );
    virtual void CollisionResponse( zVEC3 const&, int )                                                  zCall( 0x00499300 );


    // static properties
    static zCParser*& fxParser;
    static oCVisualFX*& actFX;

    // user API
    #include "oCVisualFX.inl"
  };

  // sizeof 2Ch
  class oCVisualFXAI : public zCAIBase {
  public:
    zCVob* vob;    // sizeof 04h    offset 24h
    int delete_it; // sizeof 04h    offset 28h

    oCVisualFXAI() : zCtor( zCAIBase ) {}
    virtual ~oCVisualFXAI()                                      zCall( 0x0048F2B0 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x0049BAC0 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x0048F250 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )         zCall( 0x0048F270 );

    // user API
    #include "oCVisualFXAI.inl"
  };


#endif // __OVIS_FX_H__VER1__