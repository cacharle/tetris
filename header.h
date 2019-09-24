#ifndef __HEADER_H__
# define __HEADER_H__

# include <stdbool.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

# define TETRIMINO_NB 7
# define TETRIMINO_ROTATIONS 4
# define TETRIMINO_CONTAINER_SIZE 4

# define WELL_W 12
# define WELL_H 20
# define EMPTY_COLOR 0x000000
# define TETRIMINO_I_COLOR 0x3df4f4
# define TETRIMINO_L_COLOR 0xfaa022
# define TETRIMINO_J_COLOR 0x0923a5
# define TETRIMINO_S_COLOR 0x32bd11
# define TETRIMINO_Z_COLOR 0xbc1010
# define TETRIMINO_T_COLOR 0xb40fb4
# define TETRIMINO_O_COLOR 0xf0f019
# define LINE_CLEAR_SCORE 100
# define LINE_CLEAR_SCORE_FACTOR 2
# define SOFT_DROP_FACTOR 0.2
# define INIT_FALLING_TIME_STEP 500
# define PREDROP_BUF_SIZE 2
# define WELL_FULL_H (WELL_H + PREDROP_BUF_SIZE)

typedef unsigned char Byte;

typedef union
{
    int hexcode;
    struct
    {
        Byte b;
        Byte g;
        Byte r;
    } rgb;
} Color;

typedef enum
{
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} Direction;

typedef enum
{
    NEXT_STATUS_OK,
    NEXT_STATUS_END,
    NEXT_STATUS_ERROR
} NextStatus;

typedef struct
{
    int y;
    int x;
} Position;

typedef struct
{
    int index;
    int rotation_index;
    Color color;
    Position *pos;
    Position pivot;
} Tetrimino;

typedef struct
{
    Color **well;
    Tetrimino *falling;
    int next_falling_index;
    int score;
} Tetris;

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    Tetris *tetris;
    TTF_Font *font;
    bool running;
    int window_w;
    int window_h;
    int block_size;
    int block_padding;
    bool soft_drop;
} GState;

// graphics.c
GState *graphics_init(int width, int height);
void graphics_quit(GState *state);
void graphics_run(GState *state);

// tetris.c
Tetris *tetris_init(void);
void tetris_destroy(Tetris *tetris);
NextStatus tetris_next(Tetris *tetris);
bool tetris_move(Tetris *tetris, Direction direction);
void tetris_rotate(Tetris *tetris, Direction direction);
void tetris_hard_drop(Tetris *tetris);

static int TETRIMINOES[TETRIMINO_NB][TETRIMINO_ROTATIONS]
[TETRIMINO_CONTAINER_SIZE][TETRIMINO_CONTAINER_SIZE] = {
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
