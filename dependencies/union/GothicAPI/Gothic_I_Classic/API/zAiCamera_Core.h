﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZAI_CAMERA__CORE_H__VER0__
#define __ZAI_CAMERA__CORE_H__VER0__

#include "zKbSplines.h"

  const int AZI   = 0;
  const int ELEV  = 1;
  const int RANGE = 2;

  enum zTPoseFailReason {
    zFAILREASON_NONE                    = 0,
    zFAILREASON_PLAYER_INVISIBLE        = 1 << 0,
    zFAILREASON_CAM_INVISIBLE           = 1 << 1,
    zFAILREASON_PLAYER_TARGET_INVISIBLE = 1 << 2,
    zFAILREASON_CAM_HIT_WALL            = 1 << 3,
    zFAILREASON_NO_EVASION_FOUND        = 1 << 4,
    zFAILREASON_BADSCENE_STAND          = 1 << 5,
    zFAILREASON_BADSCENE_MELEE          = 1 << 6,
    zFAILREASON_BADSCENE_RANGED         = 1 << 7,
    zFAILREASON_BADSCENE_MAGIC          = 1 << 8,
    zFAILREASON_BADSCENE_CINEMA         = 1 << 9,
    zFAILREASON_VOB_CROSS_LINEOFSIGHT   = 1 << 10,
    zFAILREASON_NPC_CROSS_LINEOFSIGHT   = 1 << 11,
    zFAILREASON_VOB_HIT_CAM             = 1 << 12,
    zFAILREASON_NPC_HIT_CAM             = 1 << 13,
    zFAILREASON_AZIBOUND_LEFT           = 1 << 14,
    zFAILREASON_ELEVBOUND_LEFT          = 1 << 15,
    zFAILREASON_RANGEBOUND_LEFT         = 1 << 16,
    zFAILREASON_TARGET_NOT_IN_FRUSTUM   = 1 << 17,
    zFAILREASON_PLAYER_BEAMED           = 1 << 18
  };

  enum zTPathLerpMode {
    zPATH_LERP_NONE        = 0,
    zPATH_LERP_CUSTOM_JUMP = 1 << 0,
    zPATH_LERP_JUMP        = 1 << 1,
    zPATH_LERP_CUSTOM      = 1 << 2,
    zPATH_LERP_SPLINE      = 1 << 3,
    zPATH_LERP_LINE        = 1 << 4,
    zPATH_LERP_ARC         = 1 << 5,
    zPATH_LERP_MAX         = 1 << 6
  };

  enum zTPathSearchFlags {
    zPATHSEARCH_INCLUDE_NONE                = 0,
    zPATHSEARCH_INCLUDE_CAM_CHECK           = 1 << 1,
    zPATHSEARCH_INCLUDE_PLAYER_CHECK        = 1 << 2,
    zPATHSEARCH_INCLUDE_PLAYER_TARGET_CHECK = 1 << 3,
    zPATHSEARCH_INCLUDE_NEARWALL_CHECK      = 1 << 4,
    zPATHSEARCH_INCLUDE_VOB_CHECK           = 1 << 5,
    zPATHSEARCH_INCLUDE_NPC_CHECK           = 1 << 6,
    zPATHSEARCH_INCLUDE_INFRUSTUM_CHECK     = 1 << 7,
    zPATHSEARCH_INCLUDE_BOUNDS_CHECK        = 1 << 8,
    zPATHSEARCH_USE_PLAYER_FUTURE_POS       = 1 << 9,
    zPATHSEARCH_USE_PLAYER_MESH             = 1 << 10,
    zPATHSEARCH_USE_DYNCOLLISION            = 1 << 11
  };

  // sizeof 24h
  struct zSEvasionSearchDesc {
    // sizeof 58h
    struct zSEvasionSearchOptions {
      zVEC3 scSign;       // sizeof 0Ch    offset 00h
      zVEC3 scQuality;    // sizeof 0Ch    offset 0Ch
      zVEC3 scStart;      // sizeof 0Ch    offset 18h
      zVEC3 scEnd;        // sizeof 0Ch    offset 24h
      zSTRING scSequence; // sizeof 14h    offset 30h
      zSTRING scName;     // sizeof 14h    offset 44h

      void zSEvasionSearchOptions_OnInit()                                zCall( 0x004A9350 );
      ~zSEvasionSearchOptions()                                           zCall( 0x0049FBC0 );
      zSEvasionSearchOptions& operator =( zSEvasionSearchOptions const& ) zCall( 0x004A8BF0 );
      zSEvasionSearchOptions()                                            zInit( zSEvasionSearchOptions_OnInit() );

      // user API
      #include "zSEvasionSearchDesc_zSEvasionSearchOptions.inl"
    };

    int(* searchFunc )( const zSEvasionSearchDesc& ); // sizeof 04h    offset 00h
    zSTRING searchName;                               // sizeof 14h    offset 04h
    zCArray<zSEvasionSearchOptions> sphereSearchList; // sizeof 0Ch    offset 18h

    void zSEvasionSearchDesc_OnInit()                             zCall( 0x004A13E0 );
    zSEvasionSearchDesc()                                         zInit( zSEvasionSearchDesc_OnInit() );
    ~zSEvasionSearchDesc()                                        zCall( 0x004A1410 );
    zSEvasionSearchDesc& operator =( zSEvasionSearchDesc const& ) zCall( 0x004A8EE0 );

    // user API
    #include "zSEvasionSearchDesc.inl"
  };

  // sizeof 60h
  struct zSPathSearchResult {
    int foundEvasion;                // sizeof 04h    offset 00h
    zVEC3 p1;                        // sizeof 0Ch    offset 04h
    zVEC3 p2;                        // sizeof 0Ch    offset 10h
    zCQuat r1;                       // sizeof 10h    offset 1Ch
    zCQuat r2;                       // sizeof 10h    offset 2Ch
    zTPathLerpMode bestLerpMode;     // sizeof 04h    offset 3Ch
    int lerpModes;                   // sizeof 04h    offset 40h
    zCArray<zCPositionKey*> resPath; // sizeof 0Ch    offset 44h
    float avgScore;                  // sizeof 04h    offset 50h
    float bestScore;                 // sizeof 04h    offset 54h
    float veloTrans;                 // sizeof 04h    offset 58h
    float veloRot;                   // sizeof 04h    offset 5Ch

    void zSPathSearchResult_OnInit() zCall( 0x0049F3E0 );
    ~zSPathSearchResult()            zCall( 0x0049C8E0 );
    zSPathSearchResult()             zInit( zSPathSearchResult_OnInit() );

    // user API
    #include "zSPathSearchResult.inl"
  };

  // sizeof 98h
  struct zSPathSearchState {
    float startAzi;              // sizeof 04h    offset 00h
    float startElev;             // sizeof 04h    offset 04h
    float startRange;            // sizeof 04h    offset 08h
    float endAzi;                // sizeof 04h    offset 0Ch
    float endElev;               // sizeof 04h    offset 10h
    float endRange;              // sizeof 04h    offset 14h
    float bestAzi;               // sizeof 04h    offset 18h
    float bestElev;              // sizeof 04h    offset 1Ch
    float bestRange;             // sizeof 04h    offset 20h
    zMAT4 trafoCamToWorld;       // sizeof 40h    offset 24h
    zTPathLerpMode bestLerpMode; // sizeof 04h    offset 64h
    int lerpModes;               // sizeof 04h    offset 68h
    float totalScore;            // sizeof 04h    offset 6Ch
    zSTRING sphereSearchName;    // sizeof 14h    offset 70h
    zSTRING sphereSearchSegment; // sizeof 14h    offset 84h

    zSPathSearchState() {}
    ~zSPathSearchState() zCall( 0x0049E170 );

    // user API
    #include "zSPathSearchState.inl"
  };

  // sizeof 74h
  struct zSPathSearchState_Internal {
    float maxRange;               // sizeof 04h    offset 00h
    zVEC3 foundPos;               // sizeof 0Ch    offset 04h
    zMAT4 trafoCamToWorld;        // sizeof 40h    offset 10h
    zTPathLerpMode bestLerpMode;  // sizeof 04h    offset 50h
    float scoreLerpMode;          // sizeof 04h    offset 54h
    float scoreDistToIdealPos;    // sizeof 04h    offset 58h
    float scoreFoundNumNpcs;      // sizeof 04h    offset 5Ch
    float scoreFoundNumBBoxes;    // sizeof 04h    offset 60h
    float scoreFoundNumTargets;   // sizeof 04h    offset 64h
    float scorePlayerVisibility;  // sizeof 04h    offset 68h
    float scoreDistToLastEvasion; // sizeof 04h    offset 6Ch
    float totalScore;             // sizeof 04h    offset 70h

    void zSPathSearchState_Internal_OnInit() zCall( 0x0049F0B0 );
    zSPathSearchState_Internal()             zInit( zSPathSearchState_Internal_OnInit() );

    // user API
    #include "zSPathSearchState_Internal.inl"
  };

  // sizeof 10h
  class zCSphereCoordsCache {
  public:
    // sizeof 78h
    struct zSRangeSphereCoord {
      float range;                            // sizeof 04h    offset 00h
      zSPathSearchState_Internal searchState; // sizeof 74h    offset 04h

      zSRangeSphereCoord() {}

      // user API
      #include "zCSphereCoordsCache_zSRangeSphereCoord.inl"
    };

    // sizeof 18h
    struct zSElevSphereCoord {
      float elev;                                   // sizeof 04h    offset 00h
      float maxRange;                               // sizeof 04h    offset 04h
      zCArraySort<zSRangeSphereCoord*> rangeCoords; // sizeof 10h    offset 08h

      zSElevSphereCoord() {}
      ~zSElevSphereCoord() zCall( 0x0049F090 );

      // user API
      #include "zCSphereCoordsCache_zSElevSphereCoord.inl"
    };

    // sizeof 14h
    struct zSAziSphereCoord {
      float azi;                                  // sizeof 04h    offset 00h
      zCArraySort<zSElevSphereCoord*> elevCoords; // sizeof 10h    offset 04h

      zSAziSphereCoord() {}
      ~zSAziSphereCoord() zCall( 0x0049F070 );

      // user API
      #include "zCSphereCoordsCache_zSAziSphereCoord.inl"
    };

    zCArraySort<zSAziSphereCoord*> aziCoords; // sizeof 10h    offset 00h

    void zCSphereCoordsCache_OnInit()                                                                zCall( 0x0049F210 );
    int GetSphereCoordLazy( float const&, float const&, float const&, zSPathSearchState_Internal*& ) zCall( 0x0049E370 );
    void GetBestScoredSearch( float&, float&, float&, zSPathSearchState_Internal*& )                 zCall( 0x0049F0C0 );
    zCSphereCoordsCache()                                                                            zInit( zCSphereCoordsCache_OnInit() );
    ~zCSphereCoordsCache()                                                                           zCall( 0x0049F230 );
    void DeleteList()                                                                                zCall( 0x0049F290 );

    // user API
    #include "zCSphereCoordsCache.inl"
  };

  // sizeof 214h
  class zCPathSearch {
  public:
    // sizeof 30h
    struct zSPathSearchOptions {
      int searchFlags;                 // sizeof 04h    offset 00h
      zTPoseFailReason poseFailReason; // sizeof 04h    offset 04h
      zTPathLerpMode minLerpMode;      // sizeof 04h    offset 08h
      float bestScore;                 // sizeof 04h    offset 0Ch
      float minScore;                  // sizeof 04h    offset 10h
      float startAzi;                  // sizeof 04h    offset 14h
      float startElev;                 // sizeof 04h    offset 18h
      float startRange;                // sizeof 04h    offset 1Ch
      float endAzi;                    // sizeof 04h    offset 20h
      float endElev;                   // sizeof 04h    offset 24h
      float endRange;                  // sizeof 04h    offset 28h
      float quality;                   // sizeof 04h    offset 2Ch

      zSPathSearchOptions() {}
      void SetDefaults() zCall( 0x0049DB50 );

      // user API
      #include "zCPathSearch_zSPathSearchOptions.inl"
    };

    zSPathSearchState bestSearchState;                               // sizeof 98h    offset 00h
    zSPathSearchState lastSearchState;                               // sizeof 98h    offset 98h
    int ignoreSearchFlags;                                           // sizeof 04h    offset 130h
    zCAICamera* camai;                                               // sizeof 04h    offset 134h
    zCVob* camVob;                                                   // sizeof 04h    offset 138h
    zCVob* target;                                                   // sizeof 04h    offset 13Ch
    zCWorld* world;                                                  // sizeof 04h    offset 140h
    int collisionEnabled;                                            // sizeof 04h    offset 144h
    zSPathSearchOptions searchOptions;                               // sizeof 30h    offset 148h
    zSPathSearchResult evasionSearchReport;                          // sizeof 60h    offset 178h
    zCMovementTracker* moveTracker;                                  // sizeof 04h    offset 1D8h
    zCSphereCoordsCache searchCache;                                 // sizeof 10h    offset 1DCh
    zVEC3 lastTriedPosition;                                         // sizeof 0Ch    offset 1ECh
    zTBSphere3D POISphere;                                           // sizeof 10h    offset 1F8h
    zCArray<int(* * )( const zSEvasionSearchDesc& )> searchFuncs;    // sizeof 0Ch    offset 208h

    void zCPathSearch_OnInit()                                                       zCall( 0x0049DF90 );

  private:
    zCPathSearch()                                                                   zInit( zCPathSearch_OnInit() );

  public:
    void CamVobChanged()                                                             zCall( 0x0049E240 );
    void TargetChanged()                                                             zCall( 0x0049E340 );
    void SetAICamera( zCAICamera* )                                                  zCall( 0x0049E360 );
    ~zCPathSearch()                                                                  zCall( 0x0049F450 );
    int SphereSearch( zSEvasionSearchDesc const& )                                   zCall( 0x0049F5E0 );
    int SwitchSearch( zSEvasionSearchDesc const& )                                   zCall( 0x0049FC40 );
    int ShoulderSearch( zSEvasionSearchDesc const& )                                 zCall( 0x0049FC50 );
    int PanicSearch( zSEvasionSearchDesc const& )                                    zCall( 0x0049FFC0 );
    void CalcStateScores( zSPathSearchState& )                                       zCall( 0x004A0460 );
    zTPathLerpMode GetBestLerpMode( zSPathSearchState const& )                       zCall( 0x004A07B0 );
    zTPathLerpMode GetBestLerpMode( zVEC3 const&, zVEC3 const& )                     zCall( 0x004A08F0 );
    zVEC3 DoSlerpRotQuat( zCQuat const&, zCQuat const&, float const&, float const& ) zCall( 0x004A09A0 );
    int FindBestEvasion( zSPathSearchOptions& )                                      zCall( 0x004A0B50 );
    int CanEvadeTo( zSPathSearchState& )                                             zCall( 0x004A1020 );
    int FindEvasionSequence( zCArray<zSEvasionSearchDesc>& )                         zCall( 0x004A1080 );
    int FES_PlayerInvisible_Moved( zCArray<zSEvasionSearchDesc>& )                   zCall( 0x004A14B0 );
    int FES_PlayerInvisible_Moved_BW( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004A34C0 );
    int FES_PlayerInvisible_Moved_FW( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004A3E00 );
    int FES_IdealCone( zCArray<zSEvasionSearchDesc>& )                               zCall( 0x004A4760 );
    int FES_PlayerInvisible_Standing( zCArray<zSEvasionSearchDesc>& )                zCall( 0x004A6620 );
    int FES_PlayerInvisible_Rotated( zCArray<zSEvasionSearchDesc>& )                 zCall( 0x004A6670 );
    int FES_PlayerTargetInvisible( zCArray<zSEvasionSearchDesc>& )                   zCall( 0x004A6EF0 );
    int FES_CamHitWall( zCArray<zSEvasionSearchDesc>& )                              zCall( 0x004A6F30 );
    int FES_NoEvasionFound( zCArray<zSEvasionSearchDesc>& )                          zCall( 0x004A6F40 );
    int EvasionPossible()                                                            zCall( 0x004A7120 );
    int IsPointValid( zVEC3 const&, int, zTPoseFailReason& )                         zCall( 0x004A7130 );
    int IsPointNearWall( zVEC3 const& )                                              zCall( 0x004A7A00 );
    int LineOfSight( zVEC3 const&, zVEC3 const& )                                    zCall( 0x004A7BF0 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                            zCall( 0x004A7C50 );
    zVEC3& GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                     zCall( 0x004A7ED0 );
    static zSPathSearchResult* GetReport()                                           zCall( 0x0049F3A0 );
    static zCPathSearch* GetSearch()                                                 zCall( 0x0049F400 );

    // user API
    #include "zCPathSearch.inl"
  };


#endif // __ZAI_CAMERA__CORE_H__VER0__