#define GLOBALS_DEFINE
#include "globals.h"
#include <ncurses.h>
#include <unistd.h>
#include "game.h"
#include "ui.h"
#include "input.h"

int main() {
    initscr();  // Inicia o modo ncurses
    cbreak();
    noecho();
    curs_set(FALSE);

    WINDOW *game_window;
    WINDOW *score_window;

    while (true) {
        if (COLS < GAME_WIDTH || LINES < GAME_HEIGHT + 3) {
            endwin();
            printf("Por favor, redimensione o terminal para pelo menos %dx%d e tente novamente.\n", GAME_WIDTH, GAME_HEIGHT + 3);
            return 1;
        }

        game_window = newwin(GAME_HEIGHT, GAME_WIDTH, (LINES - GAME_HEIGHT) / 2, (COLS - GAME_WIDTH) / 2);
        score_window = newwin(3, GAME_WIDTH, (LINES - GAME_HEIGHT) / 2 - 3, (COLS - GAME_WIDTH) / 2);

        keypad(game_window, TRUE);
        nodelay(game_window, FALSE);
        show_start_screen(game_window);
        nodelay(game_window, TRUE);

        Game game;
        init_game(&game);

        unsigned int delay = HORIZONTAL_DELAY;
        bool continue_playing = true;

        while (continue_playing) {
            int ch = wgetch(game_window);
            if (ch == 'q' || ch == 'Q') {
                continue_playing = false;
                break;
            }

            handle_game_input(&game, ch, &delay);

            if (!update_game(&game)) {
                continue_playing = end_game(game_window);
                if (continue_playing) {
                    init_game(&game);
                }
            }

            update_screen(&game, game_window, score_window);
            usleep(delay);
        }

        free_snake(&game.snake);
        delwin(game_window);
        delwin(score_window);

        if (!continue_playing) break;
    }

    endwin();
    return 0;
}