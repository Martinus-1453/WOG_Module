#ifndef __ZMEMORY_H__VER0__
#define __ZMEMORY_H__VER0__

  inline void* operator new(unsigned int size)															zCall( 0x0054EBA0 );
  inline void  operator delete (void* ptr)																zCall( 0x0054EBB0 );
  inline void* operator new[](unsigned int size)														zCall( 0x0054EBC0 );
  inline void  operator delete[](void* ptr)																zCall( 0x0054EBD0 );
  inline void* operator new (unsigned int size, const char* className, const char* file, int line)		zCall( 0x0054EBE0 );
  inline void  operator delete(void* ptr, const char* className, const char* file, int line)			zCall( 0x0054EBF0 );
  inline void* operator new[](unsigned int size, const char* className, const char* file, int line)		zCall( 0x0054EC00 );
  inline void  operator delete[](void* ptr, const char* className, const char* file, int line)			zCall( 0x0054EC10 );

#endif