CC=gcc
CFLAGS=-Iinclude
LDFLAGS=-lncurses
DEPS = include/snake.h include/food.h include/game.h include/ui.h include/input.h
OBJ = src/main.o src/snake.o src/food.o src/game.o src/ui.o src/input.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake_game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) && rm -f $(OBJ)

clean:
	rm -f src/*.o snake_game

.PHONY: clean