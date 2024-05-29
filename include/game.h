#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include <ncurses.h>
#include <stdbool.h>

#define GAME_WIDTH 60 
#define GAME_HEIGHT 20  
#define HORIZONTAL_DELAY 60000  
#define VERTICAL_DELAY 100000   

typedef struct {
    Snake snake;
    Food food;
    int score;  
} Game;

void init_game(Game *game);
bool update_game(Game *game);  
bool end_game(WINDOW *win);  
int check_collision(Snake *snake);
int check_food_collision(Snake *snake, Food *food);

#endif // GAME_H
