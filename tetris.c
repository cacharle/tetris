#include <stdlib.h>
#include "header.h"

static Tetrimino *init_falling(void);
static Position *next_rotation(Tetrimino *tetrimino);
static void update_falling(Tetris *tetris, Position *updated_pos);
static bool check_collision(Tetris *tetris, Position pos);
static bool tetris_clear_lines(Tetris *tetris);
static Position *clone_pos(Tetrimino *tetrimino);

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

NextStatus tetris_next(Tetris *tetris)
{
    if (tetris_move(tetris, DIRECTION_DOWN))
        return NEXT_STATUS_OK;
    else
    {
        tetris_clear_lines(tetris);
        return NEXT_STATUS_END;
    }
}

static bool tetris_clear_lines(Tetris *tetris)
{
    return true;
}

void tetris_hard_drop(Tetris *tetris)
{
    while (tetris_next(tetris) != NEXT_STATUS_END);
}

bool tetris_move(Tetris *tetris, Direction direction)
{
    Position *clone = clone_pos(&tetris->falling);
    for (int i = 0; i < 4; i++)
    {
        if (direction == DIRECTION_DOWN)
            clone[i].y++;
        else
            clone[i].x = clone[i].x + direction == DIRECTION_LEFT ? -1 : 1;
        if (!check_collision(tetris, clone[i]))
        {
            free(clone);
            return false;
        }
    }
    update_falling(tetris, clone);
    free(clone);
    return true;
}

void tetris_rotate_right(Tetris *tetris, Direction direction)
{

}

static Tetrimino *init_falling(void)
{
    /* TETRIMINOES[rand() % 7]; */
    return NULL;
}

static Position *next_rotation(Tetrimino *tetrimino)
{
    tetrimino->rotation_index++;
    tetrimino->rotation_index %= 4;
    /* Position *new = tetrimino->rotations[tetrimino->rotation_index]; */
    return NULL;
}

static Position *clone_pos(Tetrimino *tetrimino)
{
    Position *pos = (Position*)malloc(sizeof(Position));
    if (pos == NULL)
        return NULL;
    for (int i = 0; i < 4; i++)
        pos[i] = tetrimino->pos[i];
    return pos;
}

static void update_falling(Tetris *tetris, Position *updated_pos)
{
    for (int i = 0; i < 4; i++)
    {
        int y = tetris->falling.pos[i].y;
        int x = tetris->falling.pos[i].x;
        tetris->well[y][x].hexcode = EMPTY_COLOR;
    }
    for (int i = 0; i < 4; i++)
        tetris->well[updated_pos[i].y][updated_pos[i].x] = tetris->falling.color;
    tetris->falling.pos = updated_pos;
}

static bool check_collision(Tetris *tetris, Position pos)
{
    if (pos.y < PREDROP_BUF_SIZE || pos.y > WELL_FULL_H)
        return false;
    if (pos.x < 0 || pos.x > WELL_W)
        return false;
    if (tetris->well[pos.y][pos.x].hexcode != EMPTY_COLOR)
        return false;
    return true;
}
