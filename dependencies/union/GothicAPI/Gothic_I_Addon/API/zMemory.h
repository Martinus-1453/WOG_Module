#ifndef __ZMEMORY_H__VER1__
#define __ZMEMORY_H__VER1__

  inline void* operator new(unsigned int size)															zCall( 0x005670A0 );
  inline void  operator delete (void* ptr)																zCall( 0x005670B0 );
  inline void* operator new[](unsigned int size)														zCall( 0x005670C0 );
  inline void  operator delete[](void* ptr)																zCall( 0x005670D0 );
  inline void* operator new (unsigned int size, const char* className, const char* file, int line)		zCall( 0x005670E0 );
  inline void  operator delete(void* ptr, const char* className, const char* file, int line)			zCall( 0x005670F0 );
  inline void* operator new[](unsigned int size, const char* className, const char* file, int line)		zCall( 0x00567100 );
  inline void  operator delete[](void* ptr, const char* className, const char* file, int line)			zCall( 0x00567110 );

#endif