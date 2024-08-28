#ifndef FOOD_H
#define FOOD_H

#include "snake.h"  

typedef struct {
    int x;
    int y;
} Food;

void place_food(Food *food, Snake *snake, int max_width, int max_height);

#endif 

