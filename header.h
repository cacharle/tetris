#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <SDL2/SDL.h>

typedef struct
{
    int foo;
} Block;

typedef struct
{
    Block **grid;
    int score;
} Tetris;

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
    Tetris *tetris;
} GState;

// graphics.c
GState *graphics_init(int width, int height);
void graphics_quit(GState *state);
void graphics_run(GState *state);

// tetris.c
Tetris *tetris_init(void);
void tetris_destroy(Tetris *tetris);
void tetris_next(Tetris *tetris);

#endif
