#ifndef __ZMEMORY_H__VER2__
#define __ZMEMORY_H__VER2__

  inline void* operator new(unsigned int size)															zCall( 0x00560D30 );
  inline void  operator delete (void* ptr)																zCall( 0x00560D40 );
  inline void* operator new[](unsigned int size)														zCall( 0x00560D50 );
  inline void  operator delete[](void* ptr)																zCall( 0x00560D60 );
  inline void* operator new (unsigned int size, const char* className, const char* file, int line)		zCall( 0x00560D70 );
  inline void  operator delete(void* ptr, const char* className, const char* file, int line)			zCall( 0x00560D80 );
  inline void* operator new[](unsigned int size, const char* className, const char* file, int line)		zCall( 0x00560D90 );
  inline void  operator delete[](void* ptr, const char* className, const char* file, int line)			zCall( 0x00560DA0 );

#endif