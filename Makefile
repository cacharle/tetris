NAME = tetris
CC = gcc
CCFLAGS = -Wall -Wextra -std=c99
LDFLAGS = $(shell sdl2-config --libs --cflags) -lSDL2_ttf

HEADER = header.h
SRC = main.c graphics.c tetris.c
OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: CCFLAGS += -g
debug: re
	valgrind ./tetris

.PHONY: debug-sanitize
debug-sanitize: CCFLAGS += -g -fsanitize=address
debug-sanitize: re
	./tetris

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(LDFLAGS) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(LDFLAGS) $(CCFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
