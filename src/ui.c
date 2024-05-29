#include "ui.h"
#include "game.h"

void show_start_screen(WINDOW *win) {
    werase(win);
    box(win, 0, 0);
    int snake_y = GAME_HEIGHT / 3;
    int snake_x = (GAME_WIDTH - 5) / 2;
    wattron(win, A_BOLD);
    mvwprintw(win, snake_y, snake_x, "SNAKE");
    wattroff(win, A_BOLD);
    int message_y = GAME_HEIGHT / 2;
    int message_x = (GAME_WIDTH - 34) / 2;
    mvwprintw(win, message_y, message_x, "Pressione qualquer tecla para começar");
    wrefresh(win);
    wgetch(win); 
}

void update_screen(const Game *game, WINDOW *game_win, WINDOW *score_win) {
    werase(game_win);
    box(game_win, 0, 0);
    mvwprintw(game_win, game->food.y, game->food.x, "*");

    for (int i = 0; i < game->snake.length; i++) {
        char body_char = '#';  
        if (i == 0) {  
            switch (game->snake.direction) {
                case 'u': body_char = 'A'; break;
                case 'd': body_char = 'V'; break;
                case 'l': body_char = '<'; break;
                case 'r': body_char = '>'; break;
            }
        } else {  
            switch (game->snake.body[i].dir) {  
                case 'u': body_char = '^'; break;
                case 'd': body_char = 'v'; break;
                case 'l': body_char = '<'; break;
                case 'r': body_char = '>'; break;
            }
            
            if (i > 0 && game->snake.body[i].dir != game->snake.body[i-1].dir) {
                body_char = ' ';
            }
        }
        mvwprintw(game_win, game->snake.body[i].y, game->snake.body[i].x, "%c", body_char);
    }
    wrefresh(game_win);

    werase(score_win);
    box(score_win, 0, 0);
    mvwprintw(score_win, 1, 1, "Score: %d", game->score);
    wrefresh(score_win);
}
