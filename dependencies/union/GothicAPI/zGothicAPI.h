// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZGOTHIC_API_H__
#define __ZGOTHIC_API_H__

#define Engine_G1  1
#define Engine_G1A 2
#define Engine_G2  3
#define Engine_G2A 4

// gothic api for Gothic I v1.08k_mod
#ifdef __G1
#undef ENGINE
#define ENGINE Engine_G1
#include "Gothic_I_Classic/G1.h"
#endif

#ifdef __G1A
// gothic api for Gothic Sequel v1.12f (bin)
#undef ENGINE
#define ENGINE Engine_G1A
#include "Gothic_I_Addon/G1A.h"
#endif

// gothic api for Gothic II classic v1.30
#ifdef __G2
#undef ENGINE
#define ENGINE Engine_G2
#include "Gothic_II_Classic/G2.h"
#endif

// gothic api for Gothic II NOTR v2.6 (fix)
#ifdef __G2A
#undef ENGINE
#define ENGINE Engine_G2A
#include "Gothic_II_Addon/G2A.h"
#endif

#endif // __ZGOTHIC_API_H__