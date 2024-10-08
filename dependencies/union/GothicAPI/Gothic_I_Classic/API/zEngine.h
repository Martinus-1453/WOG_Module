﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZENGINE_H__VER0__
#define __ZENGINE_H__VER0__

#pragma warning(push)
#pragma warning(disable:4731)
#pragma warning(disable:26495)
#pragma warning(disable:26812)

#ifdef PlaySound
#undef PlaySound
#endif

#ifdef Success
#undef Success
#endif

#ifdef EVENT_MAX
#undef EVENT_MAX
#endif

#if 1
  #define __ZPROTO_B_VER0__
  #include "zPrototypes.h"
  #include "oPrototypes.h"
#endif

// startup
#ifdef __G1
	#if 1
	  #ifdef __ZPROTO_B_VER0__
		#define __ZINIT_B_VER0__
		#include "zMacro.h"
		#include "zInput_Const.h"
		#include "zTypes.h"
		#include "zSpyTypes.h"
		#include "zMemPool.h"
	  #endif
	#endif
#endif

// data, containers, cache, factory
#if 1
  #ifdef __ZINIT_B_VER0__
    #define __ZCON_B_VER0__
    #include "zString.h"
    #include "zTools.h"
    #include "zError.h"
    #include "zContainer.h"
    #include "zList.h"
    #include "zAlgebra.h"
    #include "zTypes3d.h"
    #include "zBVolume.h"
    #include "zSparseArray.h"
    #include "zObject.h"
    #include "zThread.h"
    #include "zResource.h"
    #include "zFft.h"
  #endif
#endif

// input
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZI32_B_VER0__
    #include "zInput_Win32.h"
  #endif
#endif

// z2D views, fonts, fx, etc
#if 1
  #ifdef __ZCON_B_VER0__
    #define __Z2D_B_VER0__
    #include "zView.h"
    #include "zViewObject.h"
    #include "zViewDraw.h"
    #include "zViewFx.h"
    #include "zViewPrint_Font.h"
    #include "zViewPrint.h"
    #include "zViewDialog.h"
    #include "zViewDialogChoice.h"
    #include "zFonts.h"
    #include "zConsole.h"
    #include "zGrafix.h"
  #endif
#endif

// o2D inventories, dialogs, documents, menu, etc
#if 1
  #ifdef __Z2D_B_VER0__
    #define __O2D_B_VER0__
    #include "oViewDialogInventory.h"
    #include "oViewDialogItem.h"
    #include "oViewDialogItemContainer.h"
    #include "oViewDialogStealContainer.h"
    #include "oViewDialogTrade.h"
    #include "oViewStatusBar.h"
    #include "oDoc.h"
    #include "oDocumentManager.h"
    #include "oHelp.h"
    #include "oInfo.h"
    #include "oInformationManager.h"
    #include "oMenuSavegame.h"
    #include "oViewDocument.h"
    #include "oViewDocumentMap.h"
    #include "oViewProgressbar.h"
    #include "oMenu_Status.h"
    #include "oMenu_Help.h"
  #endif
#endif


// z3D mobs, npcs, zones, worlds, items, etc
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZWLD_B_VER0__
    #include "zScanDir.h"
    #include "zPluecker.h"
    #include "zRayCache.h"
    #include "zCollisionObject.h"
    #include "zCollisionObjectMisc.h"
    #include "zVisual.h"
    #include "oNpc.h"
    #include "zBsp.h"
    #include "oWorld.h"
    #include "oMobInter.h"
    #include "oSpawn.h"
    #include "oObjFactory.h"
  #endif
#endif

// sky
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZSKY_B_VER0__
    #include "zParticle.h"
    #include "zSky.h"
    #include "zSky_Outdoor.h"
    #include "oBarrier.h"
  #endif
#endif


// visual, model, pfx, magic
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZVIS_B_VER0__
    #include "zLensflare.h"
    #include "zMorphMesh.h"
    #include "zPolyStrip.h"
    #include "zFlash.h"
    #include "zProgMesh.h"
    #include "zVertexTransform.h"
    #include "zPolyPool.h"
    #include "oVisFX.h"
    #include "oVisFx_MultiTarget.h"
    #include "oMagic.h"
    #include "oMagFrontier.h"
    #include "oParticleControl.h"
  #endif
#endif

// ai, physic, portals
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZAI_B_VER0__
    #include "zAIPlayer.h"
    #include "zPhysics.h"
    #include "zMoving.h"
    #include "oAIShoot.h"
    #include "oDialog.h"
    #include "oItemReact.h"
    #include "oFocus.h"
    #include "oNpcMessages.h"
    #include "oPortals.h"
    #include "oWaynet.h"
  #endif
#endif

// data system, vdfs
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZFILE_B_VER0__
    #include "zDisk.h"
    #include "zArchiver.h"
    #include "zArchiverGeneric.h"
    #include "zArchiver2.h"
    #include "zDisk_Vdfs.h"
    #include "zFile3d.h"
    #include "zFileCsv.h"
  #endif
#endif


// scripts, gameplay
#if 1
  #ifdef __Z2D_B_VER0__
    #define __ZEXT_B_VER0__
    #include "zParser.h"
    #include "zParser_Const.h"
    #include "oSvm.h"
    #include "oText.h"
    #include "oMission.h"
    #include "oGuilds.h"
  #endif
#endif


// net
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZNET_B_VER0__
    #include "zQueue.h"
    #include "zNet.h"
    #include "zNetManager.h"
    #include "zNetEventMan.h"
    #include "zNetVobControl.h"
    #include "zNetVersion.h"
  #endif
#endif

// system, memory
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZHELP_B_VER0__
    #include "zMemory.h"
    #include "zMemory_Base.h"
    #include "zMemory_Win32.h"
    #include "zMemory_Generic.h"
    #include "oSysInfo.h"
  #endif
#endif


// session
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZSES_B_VER0__
    #include "zAccount.h"
    #include "oGameManager.h"
    #include "oGame.h"
    #include "oGameInfo.h"
    #include "oPlayerInfo.h"
    #include "zWorldInfo.h"
  #endif
#endif

// triggers, cutscenes
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZCS_B_VER0__
    #include "zCCsPool.h"
    #include "oCSPlayer.h"
    #include "oCSManager.h"
    #include "oCsProps.h"
    #include "oCsTrigger.h"
    #include "oTrigger.h"
  #endif
#endif

// render
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZRND_B_VER0__
    #include "zScanDir.h"
    #include "zTexture.h"
    #include "zTexConvert.h"
    //#include "zRndGlide.h"
    //#include "zRndGlide_Dib.h"
    #include "zMaterial.h"
    #include "zVertexBuffer.h"
    #include "zRndD3d.h"
    #include "zRndD3d_Init.h"
    #include "zRenderManager.h"
    #include "zRenderLightContainer.h"
  #endif
#endif

// sound, music
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZSND_B_VER0__
      #include "zVobMisc.h"
      #include "zMusicCtrl.h"
      #include "zSndMss.h"
  #endif
#endif

// video
#if 1
  #ifdef __ZCON_B_VER0__
    #define __ZVID_B_VER0__
    #include "zVideo_Win32.h"
    #include "oBinkPlayer.h"
  #endif
#endif


// collisions
#if 1
  #ifdef __ZWLD_B_VER0__
    #define __ZCOLL_B_VER0__
    #include "zPluecker.h"
    #include "zRayCache.h"
    #include "zCollisionObject.h"
    #include "zCollisionObjectMisc.h"
    #include "zConvexCollision.h"
    #include "oCollisionObjectMiscChar.h"
  #endif
#endif

// other
#if 1
  #ifdef __ZINIT_B_VER0__
    #define __ZOTHER_B_VER0__
    #include "zEigen.h"
    #include "zVobIdentifier.h"
    #include "zPrime.h"
  #endif
#endif

#include "zGlobal.h"

#pragma warning(pop)

#endif // __ZENGINE_H__VER0__