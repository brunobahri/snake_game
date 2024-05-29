#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include <ncurses.h>
#include <stdbool.h>

#define GAME_WIDTH 60  // Largura do jogo
#define GAME_HEIGHT 20  // Altura do jogo
#define HORIZONTAL_DELAY 60000  // Delay horizontal em microssegundos
#define VERTICAL_DELAY 100000   // Delay vertical em microssegundos

typedef struct {
    Snake snake;
    Food food;
    int score;  
} Game;

void init_game(Game *game);
bool update_game(Game *game);  // Declarar como retornando bool.
bool end_game(WINDOW *win);  // Declarar como retornando bool e aceitando um argumento WINDOW*.
int check_collision(Snake *snake);
int check_food_collision(Snake *snake, Food *food);

#endif // GAME_H