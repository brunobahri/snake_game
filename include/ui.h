#ifndef UI_H
#define UI_H

#include "game.h"
#include <ncurses.h>

void show_start_screen(WINDOW *win);
void update_screen(const Game *game, WINDOW *game_win, WINDOW *score_win); 

#endif 
