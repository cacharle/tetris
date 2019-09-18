NAME = tetris
CC = gcc
CCFLAGS = -Wall -Wextra
LDFLAGS = $(shell sdl2-config --libs --cflags)

HEADER = header.h
SRC = main.c graphics.c
OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all
all: $(NAME)

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
