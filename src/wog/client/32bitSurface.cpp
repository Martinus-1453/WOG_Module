/*

	32 bit Textures Support

*/

#include "MemoryPatch.h"
#include "Hook.h"

#define	formatRGB555		0
#define	formatRGB1555		1			
#define	formatRGB565		2			
#define	formatRGB4444		3			
#define	formatRGB888		4
#define	formatBGR888		5
#define	formatRGBA8888		6
#define	formatBGRA8888		7
#define	formatRGB8			8
#define	formatPAL8			9
#define	formatARGB8888		10
#define	formatABGR8888		11
#define formatDXT1			12
#define formatDXT2			13
#define formatDXT3			14
#define formatDXT4			15
#define formatDXT5			16

// 1.List additional formats in pflist
// Limitations: sizeof(mapList) can't be greater than maximum of one byte (255)
// This can give us up to 5 additional new graphics formats

struct xMAPTYPE
{
	uint32_t pixeltype;
	uint32_t pixelsize;
	uint32_t Rmask;
	uint32_t Gmask;
	uint32_t Bmask;
	uint32_t Amask;

};

static xMAPTYPE	maplist[] =
{
	{ 0x0000,	8,	0x0000,0x0000,0x0000,0x0000 }, // zRND_TEX_FORMAT_PAL_8

	{ 0x4444,	16,	0x0f00,0x00f0,0x000f,0xf000 }, // zRND_TEX_FORMAT_ARGB_4444
	{ 0x5650,	16,	0xf800,0x07e0,0x001f,0x0000 }, // zRND_TEX_FORMAT_RGB_565
	{ 0x5551,	16,	0x7c00,0x03e0,0x001f,0x8000 }, // zRND_TEX_FORMAT_ARGB_1555
	{ 0x5550,	16,	0x7c00,0x03e0,0x001f,0x0000 }, // NOT USED!!!: zRND_TEX_FORMAT_ARGB_0555

	{ 0x8888,	32,	0x000000ff,0x0000ff00,0x00ff0000,0 }, // zRND_TEX_FORMAT_RGB_8888 (without alpha)
	{ 0x8888,	32,	0x00ff0000,0x0000ff00,0x000000ff,0xff000000 }, // zRND_TEX_FORMAT_BGRA_8888
	{ 0x8888,	32,	0x000000ff,0x0000ff00,0x00ff0000,0xff000000 }, // zRND_TEX_FORMAT_RGBA_8888
};

MemoryPatch patch_XD3D_EnumTextureCallback_pixelsize_cmp(0x00647876, (DWORD)&maplist + 0x4);
MemoryPatch patch_XD3D_EnumTextureCallback_Rmask_cmp(0x00647886, (DWORD)&maplist + 0x8);
MemoryPatch patch_XD3D_EnumTextureCallback_Gmask_cmp(0x00647896, (DWORD)&maplist + 0xC);
MemoryPatch patch_XD3D_EnumTextureCallback_Bmask_cmp(0x006478A6, (DWORD)&maplist + 0x10);
MemoryPatch patch_XD3D_EnumTextureCallback_Amask_cmp(0x006478B6, (DWORD)&maplist + 0x14);
MemoryPatch patch_XD3D_EnumTextureCallback_loop_cmp(0x0064793D, { 0x80, 0xFB, sizeof(maplist) });
MemoryPatch patch_XD3D_EnumTextureCallback_loop_jb(0x00647945, (BYTE)0x85);

// 2.Build DirectX Surface for appropriate type listed in pflist

DDPIXELFORMAT* pflist = (DDPIXELFORMAT*)0x009D1638;

MemoryPatch patch_zCTex_D3D__XTEX_BuildSurfaces_switch(0x0065559E, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 , 0x90 , 0x90 , 0x90 , 0x90 , 0x90 });
DWORD ret_zCTex_D3D__XTEX_BuildSurfaces_switch = 0x0065559C;

zTRnd_TextureFormat texFormat;
zBOOL xtex_alphaTex;
int pixelFormat;
DDPIXELFORMAT* ddpfPixelFormat;

void zCTex_D3D__XTEX_BuildSurfaces_switch();
HOOK Ivk_zCTex_D3D__XTEX_BuildSurfaces_switch AS(0x00655597, zCTex_D3D__XTEX_BuildSurfaces_switch);
__declspec(naked) void zCTex_D3D__XTEX_BuildSurfaces_switch()
{
	__asm /* prologue */ {
		mov esi, [ebp + 94h]
		mov texFormat, esi

		pushad
		pushfd
	}

	if (texFormat == zRND_TEX_FORMAT_BGRA_8888)
	{
		ddpfPixelFormat = &pflist[6];
		xtex_alphaTex = TRUE;
		pixelFormat = 2;
	}
	else if (texFormat == zRND_TEX_FORMAT_RGBA_8888)
	{
		ddpfPixelFormat = &pflist[7];
		xtex_alphaTex = TRUE;
		pixelFormat = 2;
	}
	else
	{
		ddpfPixelFormat = &pflist[2];
		xtex_alphaTex = FALSE;
		pixelFormat = 2;
	}

	__asm /* epilogue */ {
		popfd
		popad

		mov esi, xtex_alphaTex
		mov[ebp + 0D0h], esi

		mov esi, pixelFormat
		mov[ebp + 0B4h], esi

		mov esi, ddpfPixelFormat

		jmp ret_zCTex_D3D__XTEX_BuildSurfaces_switch
	}
}

// 3.Convert Texture to a new format
RGBPIXEL*& rgbbuff = *(RGBPIXEL**)0x009FCA54;

MemoryPatch patch_ConvertTexture2_switch(0x0065AE6A, { 0x90, 0x90, 0x90 });
DWORD ret_ConvertTexture2 = 0x0065AE6D;

DWORD dstfmt;
int pixelsCount;
RGBPIXEL* src;
char* dest;

void ConvertTexture2_switch();
HOOK Ivk_ConvertTexture2_switch AS(0x0065AE65, ConvertTexture2_switch);
__declspec(naked) void ConvertTexture2_switch()
{
	__asm /* prologue */ {
		mov eax, [esp + 288h]
		mov dstfmt, eax

		mov eax, [esp + 14h]
		mov pixelsCount, eax

		mov eax, [esp + 68h]
		mov dest, eax

		pushad
		pushfd
	}

	src = rgbbuff;

	if (dstfmt == formatBGRA8888)
	{
		while (pixelsCount > 0)
		{
			dest[0] = src->b;
			dest[1] = src->g;
			dest[2] = src->r;
			dest[3] = src->a;
			dest += 4;
			++src; --pixelsCount;
		}

		dest = (char*)((unsigned long)dest + pixelsCount * 4);
	}

	__asm /* epilogue */ {
		popfd
		popad

		mov eax, [esp + 2Ch]
		mov edi, [esp + 30h]

		jmp ret_ConvertTexture2
	}
}