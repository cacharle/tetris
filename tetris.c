#include <stdlib.h>
#include "header.h"

#define DIRECTION_MODIFIER(direction) (direction == DIRECTION_LEFT ? -1 : 1)

static Tetrimino *init_falling(Tetris *tetris);
static void update_falling(Tetris *tetris, Position *updated_pos);
static bool check_collisions(Tetris *tetris, Position *pos);
static bool check_collision(Tetris *tetris, Position pos);
static bool tetris_clear_lines(Tetris *tetris);
static Position *clone_pos(Tetrimino *tetrimino);
static Position *rotation_pos(Tetrimino *tetrimino);

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
    if ((tetris->falling = init_falling(tetris)) == NULL)
        return NULL;
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
    free(tetris->falling->pos);
    free(tetris->falling);
}

NextStatus tetris_next(Tetris *tetris)
{
    if (tetris_move(tetris, DIRECTION_DOWN))
        return NEXT_STATUS_OK;
    else
    {
        tetris_clear_lines(tetris);
        /* free(tetris->falling->pos); */
        /* free(tetris->falling); */
        tetris->falling = init_falling(tetris);
        if (tetris->falling == NULL)
            return NEXT_STATUS_ERROR;
        return NEXT_STATUS_END;
    }
}

void tetris_hard_drop(Tetris *tetris)
{
    while (tetris_next(tetris) != NEXT_STATUS_END);
}

bool tetris_move(Tetris *tetris, Direction direction)
{
    Position *clone = clone_pos(tetris->falling);
    for (int i = 0; i < 4; i++)
        printf("x %d, y %d\n", clone[i].x, clone[i].y);
    for (int i = 0; i < 4; i++)
    {
        if (direction == DIRECTION_DOWN)
            clone[i].y++;
        else
            clone[i].x = clone[i].x + DIRECTION_MODIFIER(direction);
        printf("x %d, y %d\n", clone[i].x, clone[i].y);
    }
    if (!check_collisions(tetris, clone))
    {
        free(clone);
        return false;
    }
    update_falling(tetris, clone);
    return true;
}

void tetris_rotate(Tetris *tetris, Direction direction)
{
    tetris->falling->rotation_index = (tetris->falling->rotation_index
                                       + DIRECTION_MODIFIER(direction)) % 4;
    Position *new_pos = rotation_pos(tetris->falling);
    if (new_pos == NULL)
        return;
    if (!check_collisions(tetris, new_pos))
        return;
    free(tetris->falling->pos);
    tetris->falling->pos = new_pos;
}

static Position *rotation_pos(Tetrimino *tetrimino)
{
    Position *pos = (Position*)malloc(sizeof(Position) * 4);
    if (pos == NULL)
        return NULL;
    Position pivot;
    /* int **current_rotation = (int**); */
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (TETRIMINOES[tetrimino->index][tetrimino->rotation_index][i][j] == 2)
            {
                pivot.y = i;
                pivot.x = j;
            }
    int pos_index = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (TETRIMINOES[tetrimino->index][tetrimino->rotation_index][i][j] != 0)
            {
                pos[pos_index].y = i - pivot.y + tetrimino->pivot.y;
                pos[pos_index].x = j - pivot.x + tetrimino->pivot.x;
                pos_index++;
            }
    return pos;
}

static bool tetris_clear_lines(Tetris *tetris)
{

    return true;
}

static Tetrimino *init_falling(Tetris *tetris)
{
    Tetrimino *spawn = (Tetrimino*)malloc(sizeof(Tetrimino));
    if (spawn == NULL)
        return NULL;
    spawn->index = rand() % 7;
    spawn->rotation_index = 0;
    spawn->color.hexcode = 0x00aa00;
    spawn->pivot.y = 3;
    spawn->pivot.x = 4;
    spawn->pos = rotation_pos(spawn);
    return spawn;
}

static Position *clone_pos(Tetrimino *tetrimino)
{
    Position *pos = (Position*)malloc(sizeof(Position) * 4);
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
        int y = tetris->falling->pos[i].y;
        int x = tetris->falling->pos[i].x;
        tetris->well[y][x].hexcode = EMPTY_COLOR;
    }
    for (int i = 0; i < 4; i++)
        tetris->well[updated_pos[i].y][updated_pos[i].x] = tetris->falling->color;
    free(tetris->falling->pos);
    tetris->falling->pos = updated_pos;
}

static bool check_collisions(Tetris *tetris, Position *pos)
{
    for (int i = 0; i < 4; i++)
        if (!check_collision(tetris, pos[i]))
            return false;
    return true;
}

static bool check_collision(Tetris *tetris, Position pos)
{
    if (pos.y < PREDROP_BUF_SIZE || pos.y > WELL_FULL_H - 1)
        return false;
    if (pos.x < 0 || pos.x > WELL_W)
        return false;

    /* if (tetris->well[pos.y][pos.x].hexcode != EMPTY_COLOR) */
    /*     return false; */
    return true;
}
