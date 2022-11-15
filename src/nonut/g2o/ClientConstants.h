#pragma once
#ifndef CLIENT_CONSTANTS_H
#define CLIENT_CONSTANTS_H

namespace nonut::g2o
{
	class ClientConstants
	{
	public:
		static void Init();

		static int ATTACK_FRONT;
		static int ATTACK_SWORD_LEFT;
		static int ATTACK_SWORD_RIGHT;
		static int ATTACK_SWORD_FRONT;

		static int CONSOLE_COMMAND_NOT_FOUND;
		static int CONSOLE_COMMAND_FOUND;

		static int DAEDALUS_TYPE_VOID;
		static int DAEDALUS_TYPE_FLOAT;
		static int DAEDALUS_TYPE_INT;
		static int DAEDALUS_TYPE_STRING;
		static int DAEDALUS_TYPE_CLASS;
		static int DAEDALUS_TYPE_FUNC;
		static int DAEDALUS_TYPE_PROTOTYPE;
		static int DAEDALUS_TYPE_INSTANCE;
		static int DAEDALUS_FLAG_CONST;
		static int DAEDALUS_FLAG_RETURN;
		static int DAEDALUS_FLAG_EXTERNAL;
		static int DAEDALUS_FLAG_MERGED;

		static int heroId;

		static int HUD_HEALTH_BAR;
		static int HUD_MANA_BAR;
		static int HUD_SWIM_BAR;
		static int HUD_FOCUS_BAR;
		static int HUD_FOCUS_NAME;
		static int HUD_MODE_HIDDEN;
		static int HUD_MODE_DEFAULT;
		static int HUD_MODE_ALWAYS_VISIBLE;

		static int DEFAULT_INTERPOLATION;
		static int V2_INTERPOLATION;
		static int V1_INTERPOLATION;
		static int OLD_INTERPOLATION;
		static int NO_INTERPOLATION;

		static int KEY_LAYOUT_EN;
		static int KEY_LAYOUT_PL;
		static int KEY_LAYOUT_RU;
		static int KEY_LAYOUT_DE;

		static int KEY_ESCAPE;
		static int KEY_1;
		static int KEY_2;
		static int KEY_3;
		static int KEY_4;
		static int KEY_5;
		static int KEY_6;
		static int KEY_7;
		static int KEY_8;
		static int KEY_9;
		static int KEY_0;
		static int KEY_MINUS;
		static int KEY_EQUALS;
		static int KEY_BACK;
		static int KEY_TAB;
		static int KEY_Q;
		static int KEY_W;
		static int KEY_E;
		static int KEY_R;
		static int KEY_T;
		static int KEY_Y;
		static int KEY_U;
		static int KEY_I;
		static int KEY_O;
		static int KEY_P;
		static int KEY_LBRACKET;
		static int KEY_RBRACKET;
		static int KEY_RETURN;
		static int KEY_LCONTROL;
		static int KEY_A;
		static int KEY_S;
		static int KEY_D;
		static int KEY_F;
		static int KEY_G;
		static int KEY_H;
		static int KEY_J;
		static int KEY_K;
		static int KEY_L;
		static int KEY_SEMICOLON;
		static int KEY_APOSTROPHE;
		static int KEY_TILDE;
		static int KEY_LSHIFT;
		static int KEY_BACKSLASH;
		static int KEY_Z;
		static int KEY_X;
		static int KEY_C;
		static int KEY_V;
		static int KEY_B;
		static int KEY_N;
		static int KEY_M;
		static int KEY_COMMA;
		static int KEY_PERIOD;
		static int KEY_SLASH;
		static int KEY_RSHIFT;
		static int KEY_MULTIPLY;
		static int KEY_LMENU;
		static int KEY_SPACE;
		static int KEY_CAPITAL;
		static int KEY_F1;
		static int KEY_F2;
		static int KEY_F3;
		static int KEY_F4;
		static int KEY_F5;
		static int KEY_F6;
		static int KEY_F7;
		static int KEY_F8;
		static int KEY_F9;
		static int KEY_F10;
		static int KEY_NUMLOCK;
		static int KEY_SCROLL;
		static int KEY_NUMPAD7;
		static int KEY_NUMPAD8;
		static int KEY_NUMPAD9;
		static int KEY_SUBTRACT;
		static int KEY_NUMPAD4;
		static int KEY_NUMPAD5;
		static int KEY_NUMPAD6;
		static int KEY_ADD;
		static int KEY_NUMPAD1;
		static int KEY_NUMPAD2;
		static int KEY_NUMPAD3;
		static int KEY_NUMPAD0;
		static int KEY_DECIMAL;
		static int KEY_F11;
		static int KEY_F12;
		static int KEY_NUMPADENTER;
		static int KEY_RCONTROL;
		static int KEY_DIVIDE;
		static int KEY_RMENU;
		static int KEY_PAUSE;
		static int KEY_HOME;
		static int KEY_UP;
		static int KEY_PRIOR;
		static int KEY_LEFT;
		static int KEY_RIGHT;
		static int KEY_END;
		static int KEY_DOWN;
		static int KEY_NEXT;
		static int KEY_INSERT;
		static int KEY_DELETE;
		static int KEY_LWIN;
		static int KEY_RWIN;
		static int KEY_POWER;
		static int KEY_SLEEP;
		static int KEY_WAKE;

		static int GAME_LEFT;
		static int GAME_RIGHT;
		static int GAME_UP;
		static int GAME_DOWN;
		static int GAME_ACTION;
		static int GAME_ACTION2;
		static int GAME_SLOW;
		static int GAME_WEAPON;
		static int GAME_SMOVE;
		static int GAME_SMOVE2;
		static int GAME_SHIFT;
		static int GAME_END;
		static int GAME_INVENTORY;
		static int GAME_LOOK;
		static int GAME_SNEAK;
		static int GAME_STRAFELEFT;
		static int GAME_STRAFERIGHT;
		static int GAME_SCREEN_STATUS;
		static int GAME_SCREEN_LOG;
		static int GAME_SCREEN_MAP;
		//TODO: MISSING FIRST PERSON KEY
		static int GAME_LOCK_TARGET;
		static int GAME_PARADE;
		static int GAME_ACTIONLEFT;
		static int GAME_ACTIONRIGHT;
		static int GAME_LAME_POTION;
		static int GAME_LAME_HEAL;

		static int MOUSE_LMB;
		static int MOUSE_RMB;
		static int MOUSE_MMB;

		static int OBJ_BASENPC;
		static int OBJ_PED;
		static int OBJ_PLAYER;
		static int OBJ_LOCALPLAYER;
		static int OBJ_NPC;
		static int OBJ_LOCALNPC;
		static int OBJ_ITEM;

		static int PLANET_SUN;
		static int PLANET_MOON;

		static int TRACERAY_VOB_IGNORE;
		static int TRACERAY_VOB_IGNORE_NO_CD_DYN;
		static int TRACERAY_VOB_IGNORE_CHARACTER;
		static int TRACERAY_VOB_IGNORE_PROJECTILES;
		static int TRACERAY_VOB_BBOX;
		static int zTRACERAY_STAT_IGNORE;
		static int TRACERAY_STAT_POLY;
		static int TRACERAY_STAT_PORTALS;
		static int TRACERAY_POLY_NORMAL;
		static int TRACERAY_POLY_IGNORE_TRANSP;
		static int TRACERAY_POLY_TEST_WATER;
		static int TRACERAY_POLY_2SIDED;

		static int VOB_MOB;
		static int VOB_MOB_BED;
		static int VOB_MOB_CONTAINER;
		static int VOB_MOB_DOOR;
		static int VOB_MOB_FIRE;
		static int VOB_MOB_INTER;
		static int VOB_MOB_ITEMSLOT;
		static int VOB_MOB_LADDER;
		static int VOB_MOB_LOCKABLE;
		static int VOB_MOB_SWITCH;
		static int VOB_MOB_WHEEL;
		static int VOB_NPC;
		static int VOB_TRIGGER;
		static int VOB_TRIGGER_LIST;
		static int VOB_TRIGGER_TELEPORT;
		static int VOB_TRIGGER_UNTOUCH;
		static int VOB_TRIGGER_WORLD_START;
		static int VOB_GAME;
		static int VOB_ENGINE;
		static int VOB_LIGHT;
		static int VOB_SOUND;
		static int VOB_START_POINT;
		static int VOB_WAY_POINT;
		static int VOB_ERROR;

		static int WEATHER_SNOW;
		static int WEATHER_RAIN;
	};
}
#endif
