#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <SDL2/SDL.h>

# define WELL_W 12
# define WELL_H 30
# define TETRIMINO_I_COLOR 0x3df4f4
# define TETRIMINO_L_COLOR 0xfaa022
# define TETRIMINO_J_COLOR 0x0923a5
# define TETRIMINO_S_COLOR 0x32bd11
# define TETRIMINO_Z_COLOR 0xbc1010
# define TETRIMINO_T_COLOR 0xb40fb4
# define TETRIMINO_O_COLOR 0xf0f019
# define LINE_CLEAR_SCORE 100
# define LINE_CLEAR_SCORE_FACTOR 2
# define SOFT_DROP_FACTOR 0.5
# define HARD_DROP_TIME_STEP 100
# define INIT_FALLING_TIME_STEP 1000
# define PRE_FALLING_BUFFER_SIZE 2

# define TERMINO_I {{1, 1, 1, 1}}
# define TERMINO_L {{1, 0, 0}, \
                    {1, 1, 1}}
# define TERMINO_J {{0, 0, 1}, \
                    {1, 1, 1}}
# define TERMINO_S {{0, 1, 1}, \
                    {1, 1, 0}}
# define TERMINO_Z {{1, 1, 0}, \
                    {0, 1, 1}}
# define TERMINO_T {{0, 1, 0}, \
                    {1, 1, 1}}
# define TERMINO_O {{1, 1}, \
                    {1, 1}}

typedef union
{
    int hexcode;
    struct
    {
        unsigned char b;
        unsigned char g;
        unsigned char r;
    } rgb;
} Color;

typedef struct
{
    int** shape;
    Color color;
} Tetrimino;

typedef struct
{
    Color **well;
    int score;
} Tetris;

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    Tetris *tetris;
    bool running;
    int window_w;
    int window_h;
    int block_size;
    int block_padding;
    bool drop_soft;
} GState;

// graphics.c
GState *graphics_init(int width, int height);
void graphics_quit(GState *state);
void graphics_run(GState *state);

// tetris.c
Tetris *tetris_init(void);
void tetris_destroy(Tetris *tetris);
void tetris_next(Tetris *tetris);
void tetris_hard_drop(Tetris *tetris);
void tetris_shift_right(Tetris *tetris);
void tetris_shift_left(Tetris *tetris);
void tetris_rotate_right(Tetris *tetris);
void tetris_rotate_left(Tetris *tetris);

#endif
