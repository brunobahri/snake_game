#ifndef GLOBALS_H
#define GLOBALS_H

#include <ncurses.h>

#ifdef GLOBALS_DEFINE
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN WINDOW *game_window; 

#endif
