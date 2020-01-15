#pragma once

const char* const CLEAR = "\x1b[2J\x1b[H";
const char* const CSI = "\x1b[";
const char* const TITLE = "\x1b[5;20H";
const char* const INDENT = "\x1b[5C";
const char* const RED = "\x1b[91m";
const char* const GREEN = "\x1b[92m";
const char* const YELLOW = "\x1b[93m";
const char* const BLUE = "\x1b[94m";
const char* const MAGENTA = "\x1b[95m";
const char* const CYAN = "\x1b[96m";
const char* const WHITE = "\x1b[97m";
const char* const RESET_COLOR = "\x1b[0m";

const int EMPTY = 0;
const int ENEMY = 1;
const int TREASURE = 2;
const int FOOD = 3;
const int ENTRANCE = 4;
const int EXIT = 5;

const int MAX_RANDOM_TYPE = FOOD + 1;

const char* const ICON_PLAYER = "@";
const char* const ICON_EMPTY = "\xb0";
const char* const ICON_ENEMY = "\x94";
const char* const ICON_TREASURE = "$";
const char* const ICON_FOOD = "\xed";
const char* const ICON_ENTRANCE = "\xe9";
const char* const ICON_EXIT = "\xfe";

const int MAZE_WIDTH = 10;
const int MAZE_HEIGHT = 6;

const int INDENT_X = 5;
const int ROOM_DESC_Y = 8;
const int MOVEMENT_DESC_Y = 9;
const int MAP_Y = 13;

const char* const EXTRA_OUTPUT_POS = "\x1b[25;6H";

const int PLAYER_INPUT_X = 30;
const int PLAYER_INPUT_Y = 20;

const int WEST = 4;
const int EAST = 6;
const int NORTH = 8;
const int SOUTH = 2;

const int LOOK = 9;
const int FIGHT = 10;