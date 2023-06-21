#ifndef __ZMEMORY_H__VER3__
#define __ZMEMORY_H__VER3__

  inline void* operator new(unsigned int size)															zCall( 0x00565F50 );
  inline void  operator delete (void* ptr)																zCall( 0x00565F60 );
  inline void* operator new[](unsigned int size)														zCall( 0x00565F70 );
  inline void  operator delete[](void* ptr)																zCall( 0x00565F80 );
  inline void* operator new (unsigned int size, const char* className, const char* file, int line)		zCall( 0x00565F90 );
  inline void  operator delete(void* ptr, const char* className, const char* file, int line)			zCall( 0x00565FA0 );
  inline void* operator new[](unsigned int size, const char* className, const char* file, int line)		zCall( 0x00565FB0 );
  inline void  operator delete[](void* ptr, const char* className, const char* file, int line)			zCall( 0x00565FC0 );

#endif