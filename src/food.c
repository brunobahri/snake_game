#include "food.h"
#include "snake.h"  
#include <stdlib.h>
#include <stdbool.h>  

void place_food(Food *food, Snake *snake, int max_width, int max_height) {
    bool isOnSnake;
    do {
        isOnSnake = false;
        food->x = rand() % (max_width - 2) + 1;
        food->y = rand() % (max_height - 2) + 1;

        
        for (int i = 0; i < snake->length; i++) {
            if (food->x == snake->body[i].x && food->y == snake->body[i].y) {
                isOnSnake = true;
                break; 
            }
        }
    } while (isOnSnake); 
}
