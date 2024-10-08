﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ONEWS_H__VER1__
#define __ONEWS_H__VER1__

  const int MAX_ENTRY = 20;

  typedef enum oENewsSpreadType {
    NEWS_DONT_SPREAD,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_VICTIM,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_WITNESS,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_OFFENDER,
    NEWS_SPREAD_NPC_SAME_GUILD_VICTIM
  } oTNewsSpreadType;

  // sizeof 64h
  class oCNews {
  public:
    int told;                    // sizeof 04h    offset 04h
    float spread_time;           // sizeof 04h    offset 08h
    oTNewsSpreadType spreadType; // sizeof 04h    offset 0Ch
    int news_id;                 // sizeof 04h    offset 10h
    int gossip;                  // sizeof 04h    offset 14h
    oCNpc* mNpcWitness;          // sizeof 04h    offset 18h
    oCNpc* mNpcOffender;         // sizeof 04h    offset 1Ch
    oCNpc* mNpcVictim;           // sizeof 04h    offset 20h
    zSTRING witnessName;         // sizeof 14h    offset 24h
    zSTRING offenderName;        // sizeof 14h    offset 38h
    zSTRING victimName;          // sizeof 14h    offset 4Ch
    int guildvictim;             // sizeof 04h    offset 60h

    void oCNews_OnInit()                                              zCall( 0x006B8850 );
    void oCNews_OnInit( int, int, oCNpc*, oCNpc*, oCNpc*, int )       zCall( 0x006B8A10 );
    oCNews()                                                          zInit( oCNews_OnInit() );
    oCNews( int a0, int a1, oCNpc* a2, oCNpc* a3, oCNpc* a4, int a5 ) zInit( oCNews_OnInit( a0, a1, a2, a3, a4, a5 ));
    ~oCNews()                                                         zCall( 0x006B8C30 );
    int GetID()                                                       zCall( 0x006B8DE0 );
    int IsIdentical( int, oCNpc*, oCNpc* )                            zCall( 0x006B8DF0 );
    void SetSpreadTime( float )                                       zCall( 0x006B8E20 );
    float GetSpreadTime()                                             zCall( 0x006B8E50 );
    void SetGossip( int )                                             zCall( 0x006B8E60 );
    int IsGossip()                                                    zCall( 0x006B8E80 );
    int IsGuildVictim()                                               zCall( 0x006B8E90 );
    void GetNewsData( int&, int&, oCNpc*&, oCNpc*&, oCNpc*& )         zCall( 0x006B8EA0 );
    static int GetRemainingNews()                                     zCall( 0x006B8360 );
    static void CheckRemainingNews()                                  zCall( 0x006B8370 );
    virtual void Archive( zCArchiver& )                               zCall( 0x006B8FB0 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x006B9260 );

    // static properties
    static int& news_counter;

    // user API
    #include "oCNews.inl"
  };

  // sizeof 0Ch
  class oCNewsMemory {
  public:
    zCList<oCNews> iknow; // sizeof 08h    offset 04h

    void oCNewsMemory_OnInit()             zCall( 0x006B7560 );
    oCNewsMemory()                         zInit( oCNewsMemory_OnInit() );
    ~oCNewsMemory()                        zCall( 0x006B7580 );
    void Insert( oCNews* )                 zCall( 0x006B7690 );
    void Remove( oCNews* )                 zCall( 0x006B7770 );
    oCNews* GetNews( int, oCNpc*, oCNpc* ) zCall( 0x006B77F0 );
    void CheckSpreadNews()                 zCall( 0x006B7830 );
    int SearchNews( int, oCNpc*, oCNpc* )  zCall( 0x006B78C0 );
    void ShowDebugInfos()                  zCall( 0x006B7940 );
    oCNews* GetNewsByNumber( int )         zCall( 0x006B7F40 );
    void ClearNews()                       zCall( 0x006B7F70 );
    int DeleteNewsByNumber( int )          zCall( 0x006B8070 );
    virtual void Archive( zCArchiver& )    zCall( 0x006B8110 );
    virtual void Unarchive( zCArchiver& )  zCall( 0x006B8190 );

    // user API
    #include "oCNewsMemory.inl"
  };

  // sizeof 58h
  class oCNewsManager {
  public:
    int called_BAssessAndMem;  // sizeof 04h    offset 00h
    int sentry;                // sizeof 04h    offset 04h
    int spreadList[MAX_ENTRY]; // sizeof 50h    offset 08h

    void oCNewsManager_OnInit()                              zCall( 0x006B6BC0 );
    oCNewsManager()                                          zInit( oCNewsManager_OnInit() );
    ~oCNewsManager()                                         zCall( 0x006B6BE0 );
    void CreateNews( int, int, oCNpc*, oCNpc*, oCNpc*, int ) zCall( 0x006B6BF0 );
    void SpreadToGuild( int )                                zCall( 0x006B6F40 );
    int IsInSpreadList( int )                                zCall( 0x006B6F60 );
    void SpreadNews( oCNews* )                               zCall( 0x006B6F90 );

    // user API
    #include "oCNewsManager.inl"
  };


#endif // __ONEWS_H__VER1__