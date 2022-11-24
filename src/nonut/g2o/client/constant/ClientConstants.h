#pragma once
#ifndef CLIENT_CONSTANTS_H
#define CLIENT_CONSTANTS_H
#include "pch.h"

namespace nonut::g2o
{
	class ClientConstants
	{
	public:
		static void init();

		static inline Int ATTACK_FRONT = 0;
		static inline Int ATTACK_SWORD_LEFT = 0;
		static inline Int ATTACK_SWORD_RIGHT = 0;
		static inline Int ATTACK_SWORD_FRONT = 0;

		static inline Int CONSOLE_COMMAND_NOT_FOUND = 0;
		static inline Int CONSOLE_COMMAND_FOUND = 0;

		static inline Int DAEDALUS_TYPE_VOID = 0;
		static inline Int DAEDALUS_TYPE_FLOAT = 0;
		static inline Int DAEDALUS_TYPE_INT = 0;
		static inline Int DAEDALUS_TYPE_STRING = 0;
		static inline Int DAEDALUS_TYPE_CLASS = 0;
		static inline Int DAEDALUS_TYPE_FUNC = 0;
		static inline Int DAEDALUS_TYPE_PROTOTYPE = 0;
		static inline Int DAEDALUS_TYPE_INSTANCE = 0;
		static inline Int DAEDALUS_FLAG_CONST = 0;
		static inline Int DAEDALUS_FLAG_RETURN = 0;
		static inline Int DAEDALUS_FLAG_EXTERNAL = 0;
		static inline Int DAEDALUS_FLAG_MERGED = 0;

		static inline Int heroId = 0;

		static inline Int HUD_HEALTH_BAR = 0;
		static inline Int HUD_MANA_BAR = 0;
		static inline Int HUD_SWIM_BAR = 0;
		static inline Int HUD_FOCUS_BAR = 0;
		static inline Int HUD_FOCUS_NAME = 0;
		static inline Int HUD_MODE_HIDDEN = 0;
		static inline Int HUD_MODE_DEFAULT = 0;
		static inline Int HUD_MODE_ALWAYS_VISIBLE = 0;

		static inline Int DEFAULT_INTERPOLATION = 0;
		static inline Int V2_INTERPOLATION = 0;
		static inline Int V1_INTERPOLATION = 0;
		static inline Int OLD_INTERPOLATION = 0;
		static inline Int NO_INTERPOLATION = 0;

		static inline Int KEY_LAYOUT_EN = 0;
		static inline Int KEY_LAYOUT_PL = 0;
		static inline Int KEY_LAYOUT_RU = 0;
		static inline Int KEY_LAYOUT_DE = 0;

		static inline Int KEY_ESCAPE = 0;
		static inline Int KEY_1 = 0;
		static inline Int KEY_2 = 0;
		static inline Int KEY_3 = 0;
		static inline Int KEY_4 = 0;
		static inline Int KEY_5 = 0;
		static inline Int KEY_6 = 0;
		static inline Int KEY_7 = 0;
		static inline Int KEY_8 = 0;
		static inline Int KEY_9 = 0;
		static inline Int KEY_0 = 0;
		static inline Int KEY_MINUS = 0;
		static inline Int KEY_EQUALS = 0;
		static inline Int KEY_BACK = 0;
		static inline Int KEY_TAB = 0;
		static inline Int KEY_Q = 0;
		static inline Int KEY_W = 0;
		static inline Int KEY_E = 0;
		static inline Int KEY_R = 0;
		static inline Int KEY_T = 0;
		static inline Int KEY_Y = 0;
		static inline Int KEY_U = 0;
		static inline Int KEY_I = 0;
		static inline Int KEY_O = 0;
		static inline Int KEY_P = 0;
		static inline Int KEY_LBRACKET = 0;
		static inline Int KEY_RBRACKET = 0;
		static inline Int KEY_RETURN = 0;
		static inline Int KEY_LCONTROL = 0;
		static inline Int KEY_A = 0;
		static inline Int KEY_S = 0;
		static inline Int KEY_D = 0;
		static inline Int KEY_F = 0;
		static inline Int KEY_G = 0;
		static inline Int KEY_H = 0;
		static inline Int KEY_J = 0;
		static inline Int KEY_K = 0;
		static inline Int KEY_L = 0;
		static inline Int KEY_SEMICOLON = 0;
		static inline Int KEY_APOSTROPHE = 0;
		static inline Int KEY_TILDE = 0;
		static inline Int KEY_LSHIFT = 0;
		static inline Int KEY_BACKSLASH = 0;
		static inline Int KEY_Z = 0;
		static inline Int KEY_X = 0;
		static inline Int KEY_C = 0;
		static inline Int KEY_V = 0;
		static inline Int KEY_B = 0;
		static inline Int KEY_N = 0;
		static inline Int KEY_M = 0;
		static inline Int KEY_COMMA = 0;
		static inline Int KEY_PERIOD = 0;
		static inline Int KEY_SLASH = 0;
		static inline Int KEY_RSHIFT = 0;
		static inline Int KEY_MULTIPLY = 0;
		static inline Int KEY_LMENU = 0;
		static inline Int KEY_SPACE = 0;
		static inline Int KEY_CAPITAL = 0;
		static inline Int KEY_F1 = 0;
		static inline Int KEY_F2 = 0;
		static inline Int KEY_F3 = 0;
		static inline Int KEY_F4 = 0;
		static inline Int KEY_F5 = 0;
		static inline Int KEY_F6 = 0;
		static inline Int KEY_F7 = 0;
		static inline Int KEY_F8 = 0;
		static inline Int KEY_F9 = 0;
		static inline Int KEY_F10 = 0;
		static inline Int KEY_NUMLOCK = 0;
		static inline Int KEY_SCROLL = 0;
		static inline Int KEY_NUMPAD7 = 0;
		static inline Int KEY_NUMPAD8 = 0;
		static inline Int KEY_NUMPAD9 = 0;
		static inline Int KEY_SUBTRACT = 0;
		static inline Int KEY_NUMPAD4 = 0;
		static inline Int KEY_NUMPAD5 = 0;
		static inline Int KEY_NUMPAD6 = 0;
		static inline Int KEY_ADD = 0;
		static inline Int KEY_NUMPAD1 = 0;
		static inline Int KEY_NUMPAD2 = 0;
		static inline Int KEY_NUMPAD3 = 0;
		static inline Int KEY_NUMPAD0 = 0;
		static inline Int KEY_DECIMAL = 0;
		static inline Int KEY_F11 = 0;
		static inline Int KEY_F12 = 0;
		static inline Int KEY_NUMPADENTER = 0;
		static inline Int KEY_RCONTROL = 0;
		static inline Int KEY_DIVIDE = 0;
		static inline Int KEY_RMENU = 0;
		static inline Int KEY_PAUSE = 0;
		static inline Int KEY_HOME = 0;
		static inline Int KEY_UP = 0;
		static inline Int KEY_PRIOR = 0;
		static inline Int KEY_LEFT = 0;
		static inline Int KEY_RIGHT = 0;
		static inline Int KEY_END = 0;
		static inline Int KEY_DOWN = 0;
		static inline Int KEY_NEXT = 0;
		static inline Int KEY_INSERT = 0;
		static inline Int KEY_DELETE = 0;
		static inline Int KEY_LWIN = 0;
		static inline Int KEY_RWIN = 0;
		static inline Int KEY_POWER = 0;
		static inline Int KEY_SLEEP = 0;
		static inline Int KEY_WAKE = 0;

		static inline Int GAME_LEFT = 0;
		static inline Int GAME_RIGHT = 0;
		static inline Int GAME_UP = 0;
		static inline Int GAME_DOWN = 0;
		static inline Int GAME_ACTION = 0;
		static inline Int GAME_ACTION2 = 0;
		static inline Int GAME_SLOW = 0;
		static inline Int GAME_WEAPON = 0;
		static inline Int GAME_SMOVE = 0;
		static inline Int GAME_SMOVE2 = 0;
		static inline Int GAME_SHIFT = 0;
		static inline Int GAME_END = 0;
		static inline Int GAME_INVENTORY = 0;
		static inline Int GAME_LOOK = 0;
		static inline Int GAME_SNEAK = 0;
		static inline Int GAME_STRAFELEFT = 0;
		static inline Int GAME_STRAFERIGHT = 0;
		static inline Int GAME_SCREEN_STATUS = 0;
		static inline Int GAME_SCREEN_LOG = 0;
		static inline Int GAME_SCREEN_MAP = 0;
		//TODO: MISSING FIRST PERSON KEY
		static inline Int GAME_LOCK_TARGET = 0;
		static inline Int GAME_PARADE = 0;
		static inline Int GAME_ACTIONLEFT = 0;
		static inline Int GAME_ACTIONRIGHT = 0;
		static inline Int GAME_LAME_POTION = 0;
		static inline Int GAME_LAME_HEAL = 0;

		static inline Int MOUSE_LMB = 0;
		static inline Int MOUSE_RMB = 0;
		static inline Int MOUSE_MMB = 0;

		static inline Int OBJ_BASENPC = 0;
		static inline Int OBJ_PED = 0;
		static inline Int OBJ_PLAYER = 0;
		static inline Int OBJ_LOCALPLAYER = 0;
		static inline Int OBJ_NPC = 0;
		static inline Int OBJ_LOCALNPC = 0;
		static inline Int OBJ_ITEM = 0;

		static inline Int PLANET_SUN = 0;
		static inline Int PLANET_MOON = 0;

		static inline Int TRACERAY_VOB_IGNORE = 0;
		static inline Int TRACERAY_VOB_IGNORE_NO_CD_DYN = 0;
		static inline Int TRACERAY_VOB_IGNORE_CHARACTER = 0;
		static inline Int TRACERAY_VOB_IGNORE_PROJECTILES = 0;
		static inline Int TRACERAY_VOB_BBOX = 0;
		static inline Int zTRACERAY_STAT_IGNORE = 0;
		static inline Int TRACERAY_STAT_POLY = 0;
		static inline Int TRACERAY_STAT_PORTALS = 0;
		static inline Int TRACERAY_POLY_NORMAL = 0;
		static inline Int TRACERAY_POLY_IGNORE_TRANSP = 0;
		static inline Int TRACERAY_POLY_TEST_WATER = 0;
		static inline Int TRACERAY_POLY_2SIDED = 0;

		static inline Int VOB_MOB = 0;
		static inline Int VOB_MOB_BED = 0;
		static inline Int VOB_MOB_CONTAINER = 0;
		static inline Int VOB_MOB_DOOR = 0;
		static inline Int VOB_MOB_FIRE = 0;
		static inline Int VOB_MOB_INTER = 0;
		static inline Int VOB_MOB_ITEMSLOT = 0;
		static inline Int VOB_MOB_LADDER = 0;
		static inline Int VOB_MOB_LOCKABLE = 0;
		static inline Int VOB_MOB_SWITCH = 0;
		static inline Int VOB_MOB_WHEEL = 0;
		static inline Int VOB_NPC = 0;
		static inline Int VOB_TRIGGER = 0;
		static inline Int VOB_TRIGGER_LIST = 0;
		static inline Int VOB_TRIGGER_TELEPORT = 0;
		static inline Int VOB_TRIGGER_UNTOUCH = 0;
		static inline Int VOB_TRIGGER_WORLD_START = 0;
		static inline Int VOB_GAME = 0;
		static inline Int VOB_ENGINE = 0;
		static inline Int VOB_LIGHT = 0;
		static inline Int VOB_SOUND = 0;
		static inline Int VOB_START_POINT = 0;
		static inline Int VOB_WAY_POINT = 0;
		static inline Int VOB_ERROR = 0;

		static inline Int WEATHER_SNOW = 0;
		static inline Int WEATHER_RAIN = 0;
	};
}
#endif
