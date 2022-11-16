#pragma once
#ifndef CLIENT_CONSTANTS_H
#define CLIENT_CONSTANTS_H

namespace nonut::g2o
{
	class ClientConstants
	{
	public:
		static void init();

		static inline int ATTACK_FRONT = 0;
		static inline int ATTACK_SWORD_LEFT = 0;
		static inline int ATTACK_SWORD_RIGHT = 0;
		static inline int ATTACK_SWORD_FRONT = 0;

		static inline int CONSOLE_COMMAND_NOT_FOUND = 0;
		static inline int CONSOLE_COMMAND_FOUND = 0;

		static inline int DAEDALUS_TYPE_VOID = 0;
		static inline int DAEDALUS_TYPE_FLOAT = 0;
		static inline int DAEDALUS_TYPE_INT = 0;
		static inline int DAEDALUS_TYPE_STRING = 0;
		static inline int DAEDALUS_TYPE_CLASS = 0;
		static inline int DAEDALUS_TYPE_FUNC = 0;
		static inline int DAEDALUS_TYPE_PROTOTYPE = 0;
		static inline int DAEDALUS_TYPE_INSTANCE = 0;
		static inline int DAEDALUS_FLAG_CONST = 0;
		static inline int DAEDALUS_FLAG_RETURN = 0;
		static inline int DAEDALUS_FLAG_EXTERNAL = 0;
		static inline int DAEDALUS_FLAG_MERGED = 0;

		static inline int heroId = 0;

		static inline int HUD_HEALTH_BAR = 0;
		static inline int HUD_MANA_BAR = 0;
		static inline int HUD_SWIM_BAR = 0;
		static inline int HUD_FOCUS_BAR = 0;
		static inline int HUD_FOCUS_NAME = 0;
		static inline int HUD_MODE_HIDDEN = 0;
		static inline int HUD_MODE_DEFAULT = 0;
		static inline int HUD_MODE_ALWAYS_VISIBLE = 0;

		static inline int DEFAULT_INTERPOLATION = 0;
		static inline int V2_INTERPOLATION = 0;
		static inline int V1_INTERPOLATION = 0;
		static inline int OLD_INTERPOLATION = 0;
		static inline int NO_INTERPOLATION = 0;

		static inline int KEY_LAYOUT_EN = 0;
		static inline int KEY_LAYOUT_PL = 0;
		static inline int KEY_LAYOUT_RU = 0;
		static inline int KEY_LAYOUT_DE = 0;

		static inline int KEY_ESCAPE = 0;
		static inline int KEY_1 = 0;
		static inline int KEY_2 = 0;
		static inline int KEY_3 = 0;
		static inline int KEY_4 = 0;
		static inline int KEY_5 = 0;
		static inline int KEY_6 = 0;
		static inline int KEY_7 = 0;
		static inline int KEY_8 = 0;
		static inline int KEY_9 = 0;
		static inline int KEY_0 = 0;
		static inline int KEY_MINUS = 0;
		static inline int KEY_EQUALS = 0;
		static inline int KEY_BACK = 0;
		static inline int KEY_TAB = 0;
		static inline int KEY_Q = 0;
		static inline int KEY_W = 0;
		static inline int KEY_E = 0;
		static inline int KEY_R = 0;
		static inline int KEY_T = 0;
		static inline int KEY_Y = 0;
		static inline int KEY_U = 0;
		static inline int KEY_I = 0;
		static inline int KEY_O = 0;
		static inline int KEY_P = 0;
		static inline int KEY_LBRACKET = 0;
		static inline int KEY_RBRACKET = 0;
		static inline int KEY_RETURN = 0;
		static inline int KEY_LCONTROL = 0;
		static inline int KEY_A = 0;
		static inline int KEY_S = 0;
		static inline int KEY_D = 0;
		static inline int KEY_F = 0;
		static inline int KEY_G = 0;
		static inline int KEY_H = 0;
		static inline int KEY_J = 0;
		static inline int KEY_K = 0;
		static inline int KEY_L = 0;
		static inline int KEY_SEMICOLON = 0;
		static inline int KEY_APOSTROPHE = 0;
		static inline int KEY_TILDE = 0;
		static inline int KEY_LSHIFT = 0;
		static inline int KEY_BACKSLASH = 0;
		static inline int KEY_Z = 0;
		static inline int KEY_X = 0;
		static inline int KEY_C = 0;
		static inline int KEY_V = 0;
		static inline int KEY_B = 0;
		static inline int KEY_N = 0;
		static inline int KEY_M = 0;
		static inline int KEY_COMMA = 0;
		static inline int KEY_PERIOD = 0;
		static inline int KEY_SLASH = 0;
		static inline int KEY_RSHIFT = 0;
		static inline int KEY_MULTIPLY = 0;
		static inline int KEY_LMENU = 0;
		static inline int KEY_SPACE = 0;
		static inline int KEY_CAPITAL = 0;
		static inline int KEY_F1 = 0;
		static inline int KEY_F2 = 0;
		static inline int KEY_F3 = 0;
		static inline int KEY_F4 = 0;
		static inline int KEY_F5 = 0;
		static inline int KEY_F6 = 0;
		static inline int KEY_F7 = 0;
		static inline int KEY_F8 = 0;
		static inline int KEY_F9 = 0;
		static inline int KEY_F10 = 0;
		static inline int KEY_NUMLOCK = 0;
		static inline int KEY_SCROLL = 0;
		static inline int KEY_NUMPAD7 = 0;
		static inline int KEY_NUMPAD8 = 0;
		static inline int KEY_NUMPAD9 = 0;
		static inline int KEY_SUBTRACT = 0;
		static inline int KEY_NUMPAD4 = 0;
		static inline int KEY_NUMPAD5 = 0;
		static inline int KEY_NUMPAD6 = 0;
		static inline int KEY_ADD = 0;
		static inline int KEY_NUMPAD1 = 0;
		static inline int KEY_NUMPAD2 = 0;
		static inline int KEY_NUMPAD3 = 0;
		static inline int KEY_NUMPAD0 = 0;
		static inline int KEY_DECIMAL = 0;
		static inline int KEY_F11 = 0;
		static inline int KEY_F12 = 0;
		static inline int KEY_NUMPADENTER = 0;
		static inline int KEY_RCONTROL = 0;
		static inline int KEY_DIVIDE = 0;
		static inline int KEY_RMENU = 0;
		static inline int KEY_PAUSE = 0;
		static inline int KEY_HOME = 0;
		static inline int KEY_UP = 0;
		static inline int KEY_PRIOR = 0;
		static inline int KEY_LEFT = 0;
		static inline int KEY_RIGHT = 0;
		static inline int KEY_END = 0;
		static inline int KEY_DOWN = 0;
		static inline int KEY_NEXT = 0;
		static inline int KEY_INSERT = 0;
		static inline int KEY_DELETE = 0;
		static inline int KEY_LWIN = 0;
		static inline int KEY_RWIN = 0;
		static inline int KEY_POWER = 0;
		static inline int KEY_SLEEP = 0;
		static inline int KEY_WAKE = 0;

		static inline int GAME_LEFT = 0;
		static inline int GAME_RIGHT = 0;
		static inline int GAME_UP = 0;
		static inline int GAME_DOWN = 0;
		static inline int GAME_ACTION = 0;
		static inline int GAME_ACTION2 = 0;
		static inline int GAME_SLOW = 0;
		static inline int GAME_WEAPON = 0;
		static inline int GAME_SMOVE = 0;
		static inline int GAME_SMOVE2 = 0;
		static inline int GAME_SHIFT = 0;
		static inline int GAME_END = 0;
		static inline int GAME_INVENTORY = 0;
		static inline int GAME_LOOK = 0;
		static inline int GAME_SNEAK = 0;
		static inline int GAME_STRAFELEFT = 0;
		static inline int GAME_STRAFERIGHT = 0;
		static inline int GAME_SCREEN_STATUS = 0;
		static inline int GAME_SCREEN_LOG = 0;
		static inline int GAME_SCREEN_MAP = 0;
		//TODO: MISSING FIRST PERSON KEY
		static inline int GAME_LOCK_TARGET = 0;
		static inline int GAME_PARADE = 0;
		static inline int GAME_ACTIONLEFT = 0;
		static inline int GAME_ACTIONRIGHT = 0;
		static inline int GAME_LAME_POTION = 0;
		static inline int GAME_LAME_HEAL = 0;

		static inline int MOUSE_LMB = 0;
		static inline int MOUSE_RMB = 0;
		static inline int MOUSE_MMB = 0;

		static inline int OBJ_BASENPC = 0;
		static inline int OBJ_PED = 0;
		static inline int OBJ_PLAYER = 0;
		static inline int OBJ_LOCALPLAYER = 0;
		static inline int OBJ_NPC = 0;
		static inline int OBJ_LOCALNPC = 0;
		static inline int OBJ_ITEM = 0;

		static inline int PLANET_SUN = 0;
		static inline int PLANET_MOON = 0;

		static inline int TRACERAY_VOB_IGNORE = 0;
		static inline int TRACERAY_VOB_IGNORE_NO_CD_DYN = 0;
		static inline int TRACERAY_VOB_IGNORE_CHARACTER = 0;
		static inline int TRACERAY_VOB_IGNORE_PROJECTILES = 0;
		static inline int TRACERAY_VOB_BBOX = 0;
		static inline int zTRACERAY_STAT_IGNORE = 0;
		static inline int TRACERAY_STAT_POLY = 0;
		static inline int TRACERAY_STAT_PORTALS = 0;
		static inline int TRACERAY_POLY_NORMAL = 0;
		static inline int TRACERAY_POLY_IGNORE_TRANSP = 0;
		static inline int TRACERAY_POLY_TEST_WATER = 0;
		static inline int TRACERAY_POLY_2SIDED = 0;

		static inline int VOB_MOB = 0;
		static inline int VOB_MOB_BED = 0;
		static inline int VOB_MOB_CONTAINER = 0;
		static inline int VOB_MOB_DOOR = 0;
		static inline int VOB_MOB_FIRE = 0;
		static inline int VOB_MOB_INTER = 0;
		static inline int VOB_MOB_ITEMSLOT = 0;
		static inline int VOB_MOB_LADDER = 0;
		static inline int VOB_MOB_LOCKABLE = 0;
		static inline int VOB_MOB_SWITCH = 0;
		static inline int VOB_MOB_WHEEL = 0;
		static inline int VOB_NPC = 0;
		static inline int VOB_TRIGGER = 0;
		static inline int VOB_TRIGGER_LIST = 0;
		static inline int VOB_TRIGGER_TELEPORT = 0;
		static inline int VOB_TRIGGER_UNTOUCH = 0;
		static inline int VOB_TRIGGER_WORLD_START = 0;
		static inline int VOB_GAME = 0;
		static inline int VOB_ENGINE = 0;
		static inline int VOB_LIGHT = 0;
		static inline int VOB_SOUND = 0;
		static inline int VOB_START_POINT = 0;
		static inline int VOB_WAY_POINT = 0;
		static inline int VOB_ERROR = 0;

		static inline int WEATHER_SNOW = 0;
		static inline int WEATHER_RAIN = 0;
	};
}
#endif
