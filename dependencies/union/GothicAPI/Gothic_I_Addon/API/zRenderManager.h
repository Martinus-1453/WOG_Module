﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZRENDER_MANAGER_H__VER1__
#define __ZRENDER_MANAGER_H__VER1__

  const int zRENDERMAN_NUM_SHADER        = 64;
  const int zRENDERMAN_NUM_SHADER_STAGES = zRENDERMAN_NUM_SHADER * 4;
  const int MAX_STAGES                   = 4;

  enum zTShaderWaveFunc {
    zSHD_FUNC_CONST,
    zSHD_FUNC_SIN,
    zSHD_FUNC_TRIANGLE,
    zSHD_FUNC_SQUARE,
    zSHD_FUNC_SAWTOOTH,
    zSHD_FUNC_INVERSESAWTOOTH,
    zSHD_FUNC_NOISE
  };

  enum zTShaderRGBGen {
    zSHD_RGBGEN_IDENTITY,
    zSHD_RGBGEN_VERTEX,
    zSHD_RGBGEN_FACTOR,
    zSHD_RGBGEN_WAVE
  };

  enum zTShaderAlphaGen {
    zSHD_ALPHAGEN_IDENTITY,
    zSHD_ALPHAGEN_VERTEX,
    zSHD_ALPHAGEN_FACTOR,
    zSHD_ALPHAGEN_DETAILFADE,
    zSHD_ALPHAGEN_FARFADE
  };

  enum zTShaderTCGen {
    zSHD_TCGEN_BASE,
    zSHD_TCGEN_LIGHTMAP,
    zSHD_TCGEN_ENVIRONMENT,
    zSHD_TCGEN_ENVIRONMENT_FLAT
  };

  enum zTShaderTCMod {
    zSHD_TCMOD_NONE,
    zSHD_TCMOD_SCROLL,
    zSHD_TCMOD_ENVIRONMENT,
    zSHD_TCMOD_ROTATE,
    zSHD_TCMOD_SCALE,
    zSHD_TCMOD_STRETCH,
    zSHD_TCMOD_TRANSFORM,
    zSHD_TCMOD_TURB
  };

  enum zTShaderDeformVertex {
    zSHD_DEFORMVERT_NONE,
    zSHD_DEFORMVERT_WAVE,
    zSHD_DEFORMVERT_NORMAL,
    zSHD_DEFORMVERT_BULGE,
    zSHD_DEFORMVERT_MOVE,
    zSHD_DEFORMVERT_AUTOSPRITE,
    zSHD_DEFORMVERT_AUTOSPRITE2
  };

  enum {
    LF_NOMIPMAP   = 0x01,
    LF_NOPICMIP   = 0x02,
    LF_CLAMP      = 0x04,
    LF_DETAIL     = 0x08,
    LF_LIGHTMAP   = 0x10,
    LF_HASTCMOD   = 0x20,
    LF_USENORMALS = 0x40,
    LF_MULTITEX   = 0x80
  };

  enum {
    SF_NOMIPMAP      = 0x01,
    SF_NOPICMIP      = 0x02,
    SF_POLYGONOFFSET = 0x04,
    SF_PORTAL        = 0x08,
    SF_HASLIGHTMAP   = 0x10,
    SF_HASCOLORS     = 0x20,
    SF_HASTCMOD      = 0x40,
    SF_USENORMALS    = 0x80,
    SF_MULTITEX      = 0x0100
  };

  enum zTShaderFXMode {
    zSHD_FX_NONE,
    zSHD_FX_BASETEX,
    zSHD_FX_LIGHTMAP,
    zSHD_FX_LIGHTMAP_DYN,
    zSHD_FX_DETAIL,
    zSHD_FX_MACRO,
    zSHD_FX_ENV,
    zSHD_FX_SPECULAR
  };

  // sizeof 1Ch
  class zCRenderManager {
  public:

    unsigned long frameCtr;                      // sizeof 04h    offset 00h
    zCArray<zCMaterial*> sceneMaterialList;      // sizeof 0Ch    offset 04h
    int overrideAlphaValue;                      // sizeof 04h    offset 10h
    zTRnd_AlphaBlendFunc overrideAlphaBlendFunc; // sizeof 04h    offset 14h
    int rendererMaterialModified;                // sizeof 04h    offset 18h

    void zCRenderManager_OnInit()                                                                              zCall( 0x005CE830 );
    zCRenderManager()                                                                                          zInit( zCRenderManager_OnInit() );
    ~zCRenderManager()                                                                                         zCall( 0x005CE860 );
    void InitRenderManager()                                                                                   zCall( 0x005CE910 );
    void CleanupRenderManager()                                                                                zCall( 0x005CEA20 );
    void __fastcall AddPoly( zCPolygon* )                                                                      zCall( 0x005CECA0 );
    void Flush()                                                                                               zCall( 0x005CEDD0 );
    void __fastcall SortMaterialPolys( zCMaterial* )                                                           zCall( 0x005CF090 );
    void __fastcall BuildShader( zCMaterial*, zCTexture*, unsigned long, int, zCShader*& )                     zCall( 0x005CF0B0 );
    zCVertexBufferDyn2* __fastcall GetFreeDynVertexBuffer( zCShader* )                                         zCall( 0x005CF540 );
    void __fastcall SetRGBA( zCShaderStage* )                                                                  zCall( 0x005CF680 );
    void __fastcall SetStageColorOp( unsigned long, zTRnd_AlphaBlendFunc )                                     zCall( 0x005CF760 );
    void __fastcall SetTextureStage0( zCShader*, unsigned long, zCVertexBuffer* )                              zCall( 0x005CF7E0 );
    void __fastcall SetTextureTransform( zCShader*, unsigned long, unsigned long )                             zCall( 0x005CF940 );
    void __fastcall SetAlphaFunc( zCShader*, unsigned long, unsigned long )                                    zCall( 0x005CFBE0 );
    void __fastcall DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long, zCMaterial* ) zCall( 0x005CFCC0 );
    void __fastcall DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long, zCShader* )   zCall( 0x005CFD10 );
    void __fastcall PackVB( zCArray<zCPolygon*> const&, zCShader* )                                            zCall( 0x005CFFD0 );
    static zCShader* GetFreeShader()                                                                           zCall( 0x005CEA90 );
    static zCShaderStage* GetFreeShaderStage()                                                                 zCall( 0x005CEB90 );

    // static properties
    static zCShader*& s_shaderList;
    static zCShaderStage*& s_shaderStageList;
    static int& s_currentShader;
    static int& s_currentShaderStage;
    static int& s_useRendererTNL;
    static int& s_detailTexturesEnabled;
    static zCVertexBufferDyn2*& s_vertBufferDynTex1;
    static zCVertexBufferDyn2*& s_vertBufferDynTex2;
    static zCVertexBufferDyn2*& s_vertBufferDynTex2Normal;

    // user API
    #include "zCRenderManager.inl"
  };

  // sizeof 30h
  class zCShaderStage {
  public:
    zTShaderFXMode shaderFXMode;    // sizeof 04h    offset 00h
    zCTexture* texture;             // sizeof 04h    offset 04h
    zTRnd_AlphaBlendFunc alphaFunc; // sizeof 04h    offset 08h
    zCOLOR colorFactor;             // sizeof 04h    offset 0Ch
    zCOLOR avgTextureColor;         // sizeof 04h    offset 10h
    zTShaderAlphaGen alphaGen;      // sizeof 04h    offset 14h
    zTShaderRGBGen rgbGen;          // sizeof 04h    offset 18h
    zTShaderTCGen tcGen;            // sizeof 04h    offset 1Ch
    zTShaderTCMod tcMod;            // sizeof 04h    offset 20h
    float tcModParams[2];           // sizeof 08h    offset 24h
    int multiTextureNext;           // sizeof 04h    offset 2Ch

    void zCShaderStage_OnInit() zCall( 0x005CE2F0 );
    zCShaderStage()             zInit( zCShaderStage_OnInit() );

    // user API
    #include "zCShaderStage.inl"
  };

  // sizeof 20h
  class zCShader {
  public:

    int numStages;                        // sizeof 04h    offset 00h
    zCShaderStage* stageList[MAX_STAGES]; // sizeof 10h    offset 04h
    int hasLightmap;                      // sizeof 04h    offset 14h
    int hasTcGenEnv;                      // sizeof 04h    offset 18h
    int baseTexCachedIn;                  // sizeof 04h    offset 1Ch

    void zCShader_OnInit()                  zCall( 0x005CE290 );
    zCShader()                              zInit( zCShader_OnInit() );
    ~zCShader()                             zCall( 0x005CE2B0 );
    void InsertStage( int, zCShaderStage* ) zCall( 0x005CE2C0 );

    // user API
    #include "zCShader.inl"
  };

  // sizeof 01h
  class zCMapDetailTexture {
  public:
    // sizeof 18h
    struct zTMapDetailTextureEntry {
      zSTRING detailTextureName; // sizeof 14h    offset 00h
      float detailTextureScale;  // sizeof 04h    offset 14h

      zTMapDetailTextureEntry() {}
      ~zTMapDetailTextureEntry() zCall( 0x005D1320 );

      // user API
      #include "zCMapDetailTexture_zTMapDetailTextureEntry.inl"
    };

    zCMapDetailTexture() {}
    static void S_Init()                                                           zCall( 0x005D0FA0 );
    static void S_Cleanup()                                                        zCall( 0x005D1410 );
    static zTMapDetailTextureEntry const* S_GetDetailTextureInfo( zSTRING const& ) zCall( 0x005D1420 );

    // user API
    #include "zCMapDetailTexture.inl"
  };


#endif // __ZRENDER_MANAGER_H__VER1__