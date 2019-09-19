#include <stdlib.h>
#include "header.h"

static void update_falling(Tetris *tetris, Position updated_pos[4], Color color);
static bool check_collision(Tetris *tetris, int y, int x);

Tetris *tetris_init(void)
{
    Tetris *tetris = (Tetris*)malloc(sizeof(Tetris));
    if (tetris == NULL)
        return NULL;
    tetris->well = (Color**)malloc(sizeof(Color*) * WELL_FULL_H);
    if (tetris->well == NULL)
    {
        tetris_destroy(tetris);
        return NULL;
    }
    for (int i = 0; i < WELL_FULL_H; i++)
    {
        tetris->well[i] = (Color*)malloc(sizeof(Color) * WELL_FULL_H);
        if (tetris->well[i] == NULL)
        {
            tetris_destroy(tetris);
            return NULL;
        }
        for (int j = 0; j < WELL_W; j++)
            tetris->well[i][j].hexcode = EMPTY_COLOR;
    }
    tetris->score = 0;
    return tetris;
}

void tetris_destroy(Tetris *tetris)
{
    free(tetris);
    if (tetris->well == NULL)
        return;
    for (int i = 0; i < WELL_FULL_H; i++)
    {
        if (tetris->well[i] == NULL)
            break;
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

static void update_falling(Tetris *tetris, Position updated_pos[4], Color color)
{
    for (int i = 0; i < 4; i++)
        tetris->well[tetris->falling.pos[i].y][tetris->falling.pos[i].x].hexcode =
            EMPTY_COLOR;
    for (int i = 0; i < 4; i++)
        tetris->well[updated_pos[i].y][updated_pos[i].x] = color;
}

static bool check_collision(Tetris *tetris, int y, int x)
{
    if (y < PREDROP_BUF_SIZE || y > WELL_FULL_H)
        return false;
    if (x < 0 || x > WELL_W)
        return false;
    if (tetris->well[y][x].hexcode != EMPTY_COLOR)
        return false;
    return true;
}
