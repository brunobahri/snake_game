#ifndef SNAKE_H
#define SNAKE_H

typedef struct {
    int x;
    int y;
    char dir;  // Direção do segmento para desenho Unicode
} Point;

typedef struct {
    Point *body;
    int length;
    int capacity;
    char direction;  // Direção geral da cobra
} Snake;

void init_snake(Snake *snake);
void move_snake(Snake *snake);
void grow_snake(Snake *snake);
void free_snake(Snake *snake);

#endif // SNAKE_H