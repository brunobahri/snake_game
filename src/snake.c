#include "snake.h"
#include <stdlib.h>

void init_snake(Snake *snake) {
    snake->length = 1;
    snake->capacity = 5;
    snake->body = malloc(sizeof(Point) * snake->capacity);
    snake->body[0].x = 10;
    snake->body[0].y = 10;
    snake->body[0].dir = 'r';  
    snake->direction = 'r';
}

void move_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
        snake->body[i].dir = snake->body[i - 1].dir;  
    }
    snake->body[0].dir = snake->direction;
    switch (snake->direction) {
        case 'u': snake->body[0].y -= 1; break;
        case 'd': snake->body[0].y += 1; break;
        case 'l': snake->body[0].x -= 1; break;
        case 'r': snake->body[0].x += 1; break;
    }
}

void grow_snake(Snake *snake) {
    if (snake->length == snake->capacity) {
        snake->capacity *= 2;
        snake->body = realloc(snake->body, sizeof(Point) * snake->capacity);
    }
    snake->body[snake->length] = snake->body[snake->length - 1];  
    snake->length++;
}

void free_snake(Snake *snake) {
    free(snake->body);
}
