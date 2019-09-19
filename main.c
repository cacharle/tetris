#include <stdlib.h>
#include "header.h"

#define DEFAULT_WINDOW_W 400
#define DEFAULT_WINDOW_H 600

# define TETRININO_NB 7
# define TETRIMINO_ROTATIONS 4
# define TETRIMINO_CONTAINER_SIZE 4

int TETRIMINOES[TETRININO_NB][TETRIMINO_ROTATIONS]
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


int main(void)
{
    GState *gstate = graphics_init(DEFAULT_WINDOW_W, DEFAULT_WINDOW_H);
    graphics_run(gstate);
    graphics_quit(gstate);
    return EXIT_SUCCESS;
}
