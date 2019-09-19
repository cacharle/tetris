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

const int NB_KINDS = 7; // Le nombre de types de pièces qu'on a
const int NB_ROTATIONS = 4; // Le nombre de rotations de chaque pièce
const int SIZE = 4; // La taille de la matrice de chaque rotation
 
int PIECES[NB_KINDS][NB_ROTATIONS][SIZE][SIZE] =
{
    { // O
        {
            {0, 0, 0, 0},
            {0, 1, 2, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 2, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 2, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 2, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // I
        {
            {0, 0, 0, 0},
            {1, 1, 2, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        },
 
        {
            {0, 0, 0, 0},
            {1, 1, 2, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        }
    },
 
    { // S
        {
            {0, 0, 0, 0},
            {0, 0, 2, 1},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 0, 2, 1},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0}
        }
    },
 
    { // Z
        {
            {0, 0, 0, 0},
            {0, 1, 2, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 1},
            {0, 0, 2, 1},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 0},
            {0, 1, 2, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 1},
            {0, 0, 2, 1},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // L
        {
            {0, 0, 0, 0},
            {0, 1, 2, 1},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 0, 1},
            {0, 1, 2, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 1, 1, 0},
            {0, 0, 2, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // J
        {
            {0, 0, 0, 0},
            {0, 1, 2, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 1},
            {0, 0, 2, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 1, 0, 0},
            {0, 1, 2, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    },
 
    { // T
        {
            {0, 0, 0, 0},
            {0, 1, 2, 1},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 0, 2, 1},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 1, 2, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
 
        {
            {0, 0, 1, 0},
            {0, 1, 2, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    }
};
 
#endif

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
