#include <stdlib.h>
#include "header.h"

Tetris *tetris_init(void)
{
    Tetris *tetris = (Tetris*)malloc(sizeof(Tetris));
    if (tetris == NULL)
        return NULL;
    tetris->well = (Color**)malloc(sizeof(Color*) * WELL_H);
    /* if (tetris->well == NULL) */
    /* { */
    /*     tetris_destroy(tetris); */
    /*     return NULL; */
    /* } */
    for (int i = 0; i < WELL_H; i++)
    {
        tetris->well[i] = (Color*)malloc(sizeof(Color) * WELL_W);
        /* if (tetris->well[i] == NULL) */
        /* { */
        /*     tetris_destroy(tetris); */
        /*     return NULL; */
        /* } */
        for (int j = 0; j < WELL_H; j++)
            tetris->well[i][j].hexcode = EMPTY_COLOR;
    }
    tetris->score = 0;
    return tetris;
}

void tetris_destroy(Tetris *tetris)
{
    free(tetris);
    /* if (tetris->well == NULL) */
    /*     return; */
    for (int i = 0; i < WELL_H; i++)
    {
        /* if (tetris->well[i] == NULL) */
        /*     break; */
        free(tetris->well[i]);
    }
    free(tetris->well);
}

void tetris_next(Tetris *tetris)
{

}

void tetris_hard_drop(Tetris *tetris)
{

}

void tetris_shift_right(Tetris *tetris)
{

}

void tetris_shift_left(Tetris *tetris)
{

}

void tetris_rotate_right(Tetris *tetris)
{

}

void tetris_rotate_left(Tetris *tetris)
{

}
