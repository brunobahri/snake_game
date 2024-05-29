#include "input.h"
#include "game.h"

void handle_game_input(Game *game, int ch, unsigned int *delay) {
    switch (ch) {
        case KEY_UP:
            if (game->snake.direction != 'd') {
                game->snake.direction = 'u';
                *delay = VERTICAL_DELAY;
            }
            break;
        case KEY_DOWN:
            if (game->snake.direction != 'u') {
                game->snake.direction = 'd';
                *delay = VERTICAL_DELAY;
            }
            break;
        case KEY_LEFT:
            if (game->snake.direction != 'r') {
                game->snake.direction = 'l';
                *delay = HORIZONTAL_DELAY;
            }
            break;
        case KEY_RIGHT:
            if (game->snake.direction != 'l') {
                game->snake.direction = 'r';
                *delay = HORIZONTAL_DELAY;
            }
            break;
    }
}