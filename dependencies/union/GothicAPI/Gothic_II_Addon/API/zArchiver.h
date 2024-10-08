﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZARCHIVER_H__VER3__
#define __ZARCHIVER_H__VER3__


  enum zTArchiveMode {
    zARC_MODE_BINARY,
    zARC_MODE_ASCII,
    zARC_MODE_ASCII_PROPS,
    zARC_MODE_BINARY_SAFE,
    zARC_MODE_COUNT
  };

  enum zTArchiveFlags {
    zARC_FLAG_WRITE_BRIEF_HEADER = 1,
    zARC_FLAG_NO_SPY_MESSAGES    = 2
  };

  // sizeof 04h
  class zCArchiverFactory {
  public:

    zCArchiverFactory() {}
    int EndOfArchive( zCBuffer*, zFILE* )                                              zCall( 0x00519650 );
    void ReadLine( zSTRING&, zCBuffer*, zFILE* )                                       zCall( 0x005196C0 );
    void ReadLineArg( zSTRING&, zSTRING&, zCBuffer*, zFILE* )                          zCall( 0x005198D0 );
    void ReadHeader( int, zCBuffer*, zFILE*, zCArchiver*&, zTArchiveMode&, int& )      zCall( 0x00519B50 );
    void WriteLine( zSTRING const&, zCBuffer*, zFILE* )                                zCall( 0x0051A290 );
    void WriteLine( char const* const, zCBuffer*, zFILE* )                             zCall( 0x0051A390 );
    void WriteHeader( zCArchiver*, zTArchiveMode, int, int, zCBuffer*, zFILE* )        zCall( 0x0051A490 );
    zCArchiver* CreateArchiverFromMode( zTArchiveMode )                                zCall( 0x0051ACD0 );
    virtual zCArchiver* CreateArchiverRead( zCBuffer*, int )                           zCall( 0x0051A020 );
    virtual zCArchiver* CreateArchiverRead( zFILE*, int )                              zCall( 0x0051A0B0 );
    virtual zCArchiver* CreateArchiverRead( zSTRING const&, int )                      zCall( 0x0051A120 );
    virtual zCArchiver* CreateArchiverWrite( zCBuffer*, zTArchiveMode, int, int )      zCall( 0x0051ADB0 );
    virtual zCArchiver* CreateArchiverWrite( zTArchiveMode, int, int )                 zCall( 0x0051AF00 );
    virtual zCArchiver* CreateArchiverWrite( zFILE*, zTArchiveMode, int, int )         zCall( 0x0051AFA0 );
    virtual zCArchiver* CreateArchiverWrite( zSTRING const&, zTArchiveMode, int, int ) zCall( 0x0051AF20 );

    // user API
    #include "zCArchiverFactory.inl"
  };

  // sizeof 2Ch
  class zCArchiver : public zCObject {
  public:
    zCLASS_DECLARATION( zCArchiver )

    enum zTArchiveMedium {
      zARC_MEDIUM_FILE,
      zARC_MEDIUM_BUFFER
    };

    enum zTAccessMode {
      zARC_CLOSED,
      zARC_READ,
      zARC_WRITE
    };

    // sizeof 38h
    struct zTChunkRecord {
      unsigned long startPos;    // sizeof 04h    offset 00h
      unsigned long size;        // sizeof 04h    offset 04h
      unsigned short version;    // sizeof 02h    offset 08h
      unsigned long objectIndex; // sizeof 04h    offset 0Ch
      zSTRING name;              // sizeof 14h    offset 10h
      zSTRING className;         // sizeof 14h    offset 24h

      void zTChunkRecord_OnInit()                       zCall( 0x005213C0 );
      ~zTChunkRecord()                                  zCall( 0x0051E280 );
      zTChunkRecord& operator =( zTChunkRecord const& ) zCall( 0x0051F770 );
      zTChunkRecord()                                   zInit( zTChunkRecord_OnInit() );

      // user API
      #include "zCArchiver_zTChunkRecord.inl"
    };

    zTArchiveMedium medium; // sizeof 04h    offset 24h
    zTArchiveMode mode;     // sizeof 04h    offset 28h

    zDefineInheritableCtor( zCArchiver ) : zCtor( zCObject ) {}
    zCArchiver() : zCtor( zCObject ) {}
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0051BFF0 );
    virtual ~zCArchiver()                                                                              zCall( 0x0051C000 );
    virtual void __fastcall WriteInt( char const*, int )                                               zPureCall;
    virtual void __fastcall WriteByte( char const*, unsigned char )                                    zPureCall;
    virtual void __fastcall WriteWord( char const*, unsigned short )                                   zPureCall;
    virtual void __fastcall WriteFloat( char const*, float )                                           zPureCall;
    virtual void __fastcall WriteBool( char const*, int )                                              zPureCall;
    virtual void __fastcall WriteString( char const*, zSTRING const& )                                 zPureCall;
    virtual void __fastcall WriteVec3( char const*, zVEC3 const& )                                     zPureCall;
    virtual void __fastcall WriteColor( char const*, zCOLOR const& )                                   zPureCall;
    virtual void __fastcall WriteRaw( char const*, void*, unsigned long )                              zPureCall;
    virtual void __fastcall WriteRawFloat( char const*, void*, unsigned long )                         zPureCall;
    virtual void __fastcall WriteEnum( char const*, char const*, int )                                 zPureCall;
    virtual void __fastcall WriteObject( zCObject* )                                                   zPureCall;
    virtual void __fastcall WriteObject( char const*, zCObject* )                                      zPureCall;
    virtual void __fastcall WriteObject( char const*, zCObject& )                                      zPureCall;
    virtual void __fastcall WriteChunkStart( char const*, unsigned short )                             zPureCall;
    virtual void __fastcall WriteChunkStart( char const*, char const*, unsigned short, unsigned long ) zPureCall;
    virtual void __fastcall WriteChunkEnd()                                                            zPureCall;
    virtual void __fastcall WriteGroupBegin( char const* )                                             zPureCall;
    virtual void __fastcall WriteGroupEnd( char const* )                                               zPureCall;
    virtual void __fastcall ReadInt( char const*, int& )                                               zPureCall;
    virtual int __fastcall ReadInt( char const* )                                                      zPureCall;
    virtual void __fastcall ReadByte( char const*, unsigned char& )                                    zPureCall;
    virtual unsigned char __fastcall ReadByte( char const* )                                           zPureCall;
    virtual void __fastcall ReadWord( char const*, unsigned short& )                                   zPureCall;
    virtual unsigned short __fastcall ReadWord( char const* )                                          zPureCall;
    virtual void __fastcall ReadFloat( char const*, float& )                                           zPureCall;
    virtual float __fastcall ReadFloat( char const* )                                                  zPureCall;
    virtual void __fastcall ReadBool( char const*, int& )                                              zPureCall;
    virtual int __fastcall ReadBool( char const* )                                                     zPureCall;
    virtual void __fastcall ReadString( char const*, zSTRING& )                                        zPureCall;
    virtual zSTRING __fastcall ReadString( char const* )                                               zPureCall;
    virtual void __fastcall ReadVec3( char const*, zVEC3& )                                            zPureCall;
    virtual zVEC3 __fastcall ReadVec3( char const* )                                                   zPureCall;
    virtual void __fastcall ReadColor( char const*, zCOLOR& )                                          zPureCall;
    virtual zCOLOR __fastcall ReadColor( char const* )                                                 zPureCall;
    virtual void __fastcall ReadEnum( char const*, int& )                                              zPureCall;
    virtual int __fastcall ReadEnum( char const* )                                                     zPureCall;
    virtual void __fastcall ReadRaw( char const*, void*, unsigned long )                               zPureCall;
    virtual void __fastcall ReadRawFloat( char const*, void*, unsigned long )                          zPureCall;
    virtual zCObject* __fastcall ReadObject( zCObject* )                                               zPureCall;
    virtual zCObject* __fastcall ReadObject( char const*, zCObject* )                                  zPureCall;
    virtual zCObject* __fastcall ReadObjectAccount( char const*, int, zCObject* )                      zCall( 0x0051AFF0 );
    virtual zCObject* __fastcall ReadObjectAccount( char const*, int, char const*, zCObject* )         zCall( 0x0051B020 );
    virtual int __fastcall ReadChunkStart( zSTRING&, unsigned short& )                                 zPureCall;
    virtual int __fastcall ReadChunkStart( char const* )                                               zPureCall;
    virtual int __fastcall ReadChunkStartNamed( char const*, unsigned short& )                         zPureCall;
    virtual void __fastcall SkipOpenChunk()                                                            zPureCall;
    virtual unsigned short __fastcall GetCurrentChunkVersion()                                         zPureCall;
    virtual zFILE* GetFile() const                                                                     zPureCall;
    virtual void __fastcall GetBufferString( zSTRING& )                                                zPureCall;
    virtual zCBuffer* __fastcall GetBuffer()                                                           zPureCall;
    virtual int __fastcall EndOfArchive()                                                              zPureCall;
    virtual void Close()                                                                               zPureCall;
    virtual void SetStringEOL( zSTRING const& )                                                        zPureCall;
    virtual zSTRING GetStringEOL() const                                                               zPureCall;
    virtual int IsStringValid( char const* )                                                           zPureCall;
    virtual int GetChecksumEnabled() const                                                             zPureCall;
    virtual void SetChecksumEnabled( int )                                                             zPureCall;
    virtual void SetNoReadSearchCycles( int )                                                          zPureCall;
    virtual int InProperties() const                                                                   zPureCall;
    virtual int InSaveGame() const                                                                     zPureCall;
    virtual int InBinaryMode() const                                                                   zPureCall;
    virtual zCObject* __fastcall GetParentObject()                                                     zPureCall;
    virtual int OpenWriteBuffer( zCBuffer*, zTArchiveMode, int, int, int )                             zPureCall;
    virtual void OpenWriteFile( zFILE*, zTArchiveMode, int, int, int )                                 zPureCall;
    virtual void __fastcall WriteHeader( int )                                                         zPureCall;
    virtual void __fastcall WriteHeaderNumObj()                                                        zPureCall;
    virtual void __fastcall WriteASCIILine( char const*, char const*, zSTRING const& )                 zPureCall;
    virtual void __fastcall StoreBuffer( void*, unsigned long )                                        zPureCall;
    virtual void __fastcall StoreString( char const* )                                                 zPureCall;
    virtual void __fastcall StoreStringEOL( char const* )                                              zPureCall;
    virtual unsigned long __fastcall StoreGetPos()                                                     zPureCall;
    virtual void __fastcall StoreSeek( unsigned long )                                                 zPureCall;
    virtual int OpenReadBuffer( zCBuffer&, zTArchiveMode, int, int )                                   zPureCall;
    virtual void OpenReadFile( zFILE*, zTArchiveMode, int, int, int )                                  zPureCall;
    virtual zCClassDef* __fastcall GetClassDefByString( zSTRING const& )                               zPureCall;
    virtual zCObject* __fastcall CreateObject( zSTRING const& )                                        zPureCall;
    virtual void __fastcall SkipChunk( int )                                                           zPureCall;
    virtual void __fastcall ReadChunkStartASCII( char const*, zSTRING& )                               zPureCall;
    virtual void __fastcall ReadChunkEnd()                                                             zPureCall;
    virtual int __fastcall ReadEntryASCII( char const*, zSTRING& )                                     zPureCall;
    virtual void __fastcall ReadHeader()                                                               zPureCall;
    virtual void __fastcall RestoreBuffer( void*, unsigned long )                                      zPureCall;
    virtual void __fastcall RestoreStringEOL( zSTRING& )                                               zPureCall;
    virtual void __fastcall RestoreString0( zSTRING& )                                                 zPureCall;
    virtual unsigned long __fastcall RestoreGetPos()                                                   zPureCall;
    virtual void __fastcall RestoreSeek( unsigned long )                                               zPureCall;
    virtual void __fastcall DeleteBuffer()                                                             zPureCall;

    // static properties
    static zSTRING& stringEOL;

    // user API
    #include "zCArchiver.inl"
  };


#endif // __ZARCHIVER_H__VER3__