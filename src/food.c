#include "food.h"
#include "snake.h"  // Inclua o cabeçalho que contém a definição da estrutura Snake
#include <stdlib.h>
#include <stdbool.h>  // Para usar o tipo bool

void place_food(Food *food, Snake *snake, int max_width, int max_height) {
    bool isOnSnake;
    do {
        isOnSnake = false;
        // Gera posições aleatórias dentro dos limites do campo de jogo
        food->x = rand() % (max_width - 2) + 1;
        food->y = rand() % (max_height - 2) + 1;

        // Verifica se a posição da comida coincide com alguma parte do corpo da serpente
        for (int i = 0; i < snake->length; i++) {
            if (food->x == snake->body[i].x && food->y == snake->body[i].y) {
                isOnSnake = true;
                break; // Sai do loop se a comida está sobre o corpo da serpente
            }
        }
    } while (isOnSnake); // Repete enquanto a comida estiver sobre o corpo da serpente
}