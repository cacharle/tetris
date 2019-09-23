#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "header.h"

#define WINDOW_TITLE "Tetris"
#define WINDOW_X 20
#define WINDOW_Y 20
#define REFRESH_TIME_STEP 1
#define WELL_BORDER_SIZE 10

#define SET_RENDER_COLOR(renderer, c) ( \
        SDL_SetRenderDrawColor(renderer, c.rgb.r, c.rgb.g, c.rgb.b, SDL_ALPHA_OPAQUE))

static void update(GState *state);
static void event_handler(GState *state);
static void draw_grid(GState *state);
static void destroy_state(GState *state);
static void error_exit_state(GState *state, const char *msg);
static void error_exit(const char *msg);

GState *graphics_init(int width, int height)
{
    GState *state = (GState*)malloc(sizeof(GState));
    if (state == NULL)
    {
        fprintf(stderr, "Error: unable to allocate memory for graphic state");
        exit(EXIT_FAILURE);
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        error_exit("unable to init SDL");
    state->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X, WINDOW_Y,
            width, height, 0);
    if (state->window == NULL)
        error_exit("unable to create window");
    state->renderer = SDL_CreateRenderer(state->window, -1, 0);
    if (state->renderer == NULL)
        error_exit_state(state, "unable to create renderer");
    if ((state->tetris = tetris_init()) == NULL)
        error_exit_state(state, "unable to init tetris");
    state->running = true;
    state->window_w = width;
    state->window_h = height;
    state->block_size = 20;
    state->block_padding = 2;
    state->soft_drop = false;
    return state;
}

void graphics_quit(GState *state)
{
    destroy_state(state);
    SDL_Quit();
}

void graphics_run(GState *state)
{
    unsigned int current_time, last_time = 0, last_time_soft_drop = 0;
    while (state->running)
    {
        event_handler(state);
        current_time = SDL_GetTicks();
        if (state->soft_drop && SDL_TICKS_PASSED(current_time, last_time_soft_drop))
        {
            last_time_soft_drop = current_time + INIT_FALLING_TIME_STEP * SOFT_DROP_FACTOR;
            update(state);
            tetris_next(state->tetris);
        }
        else if (SDL_TICKS_PASSED(current_time, last_time))
        {
            last_time = current_time + INIT_FALLING_TIME_STEP;
            update(state);
            tetris_next(state->tetris);
        }
        SDL_Delay(REFRESH_TIME_STEP);
    }
}

static void update(GState *state)
{
    SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(state->renderer);
    draw_grid(state);
    SDL_RenderPresent(state->renderer);
}

static void draw_grid(GState *state)
{
    for (int i = PREDROP_BUF_SIZE; i < WELL_FULL_H; i++)
        for (int j = 0; j < WELL_W; j++)
        {
            SET_RENDER_COLOR(state->renderer, state->tetris->well[i][j]);
            SDL_Rect block_rect = {
                .x = j * state->block_size + j * state->block_padding,
                .y = i * state->block_size + i * state->block_padding,
                .w = state->block_size,
                .h = state->block_size
            };
            SDL_RenderFillRect(state->renderer, &block_rect);
        }
}

static void event_handler(GState *state)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                state->running = false;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                    case SDLK_q:
                        state->running = false;
                        break;
                    case SDLK_LEFT:
                    case SDLK_h:
                        tetris_move(state->tetris, DIRECTION_LEFT);
                        update(state);
                        break;
                    case SDLK_RIGHT:
                    case SDLK_l:
                        tetris_move(state->tetris, DIRECTION_RIGHT);
                        update(state);
                        break;
                    case SDLK_DOWN:
                    case SDLK_j:
                        state->soft_drop = true;
                        break;
                    case SDLK_SPACE:
                        tetris_hard_drop(state->tetris);
                        update(state);
                        break;
                    case SDLK_UP:
                    case SDLK_k:
                        tetris_rotate(state->tetris, DIRECTION_RIGHT);
                        update(state);
                        break;
                    case SDLK_z:
                        tetris_rotate(state->tetris, DIRECTION_LEFT);
                        update(state);
                        break;
                }
                break;
            case SDL_KEYUP:
                if (e.key.keysym.sym == SDLK_DOWN)
                    state->soft_drop = false;
        }
    }
}

static void destroy_state(GState *state)
{
    if (state == NULL)
        return;
    /* tetris_destroy(state->tetris); */
    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyWindow(state->window);
    free(state);
}

static void error_exit_state(GState *state, const char *msg)
{
    destroy_state(state);
    error_exit(msg);
}

static void error_exit(const char *msg)
{
    SDL_Log("ERROR: %s: %s", SDL_GetError(), msg);
    SDL_Quit();
    exit(EXIT_FAILURE);
}
