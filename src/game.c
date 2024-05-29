#include "game.h"
#include "globals.h"
#include <stdlib.h>
#include <stdbool.h>

void init_game(Game *game) {
    init_snake(&game->snake);

    place_food(&game->food, &game->snake, GAME_WIDTH - 2, GAME_HEIGHT - 2);
    game->score = 0;
}

bool update_game(Game *game) {
    move_snake(&game->snake);

    if (check_collision(&game->snake)) {
        return false;  
    }

    if (check_food_collision(&game->snake, &game->food)) {
        grow_snake(&game->snake);

        place_food(&game->food, &game->snake, GAME_WIDTH - 2, GAME_HEIGHT - 2);
        game->score += 10;
    }

    return true;  
}

int check_collision(Snake *snake) {
    Point head = snake->body[0];
    if (head.x < 1 || head.x >= GAME_WIDTH - 1 || head.y < 1 || head.y >= GAME_HEIGHT - 1) {
        return 1;
    }
    for (int i = 1; i < snake->length; i++) {
        if (head.x == snake->body[i].x && head.y == snake->body[i].y) {
            return 1;
        }
    }
    return 0;
}

int check_food_collision(Snake *snake, Food *food) {
    Point head = snake->body[0];
    if (head.x == food->x && head.y == food->y) {
        return 1;
    }
    return 0;
}

bool end_game(WINDOW *win) {
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, GAME_HEIGHT / 2 - 1, (GAME_WIDTH - 10) / 2, "Game Over!");
    mvwprintw(win, GAME_HEIGHT / 2, (GAME_WIDTH - 20) / 2, "Pressione R para jogar novamente");
    mvwprintw(win, GAME_HEIGHT / 2 + 1, (GAME_WIDTH - 19) / 2, "Pressione Q para sair");
    wrefresh(win);

    char choice;
    nodelay(win, FALSE);
    do {
        choice = wgetch(win);
        if (choice == 'Q' || choice == 'q') {
            endwin();  
            exit(0);  
        }
    } while (choice != 'R' && choice != 'r');

    nodelay(win, TRUE);
    return true; 
}
