#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "header.h"

#define WINDOW_TITLE "Tetris"
#define WINDOW_X SDL_WINDOWPOS_UNDEFINED
#define WINDOW_Y SDL_WINDOWPOS_UNDEFINED
#define REFRESH_TIME_STEP 1
#define WELL_BORDER_SIZE 10

#define FONT_PTSIZE 16
#define SCORE_MARGIN 30
#define NEXT_FALLING_MARGIN_TOP 150
#define NEXT_FALLING_MARGIN_LEFT 15
#define SET_RENDER_COLOR(renderer, c) ( \
        SDL_SetRenderDrawColor(renderer, c.rgb.r, c.rgb.g, c.rgb.b, SDL_ALPHA_OPAQUE))
#define BORDER_LEN_HEIGHT(state) ((state->block_size + state->block_padding) \
        * WELL_H + WELL_BORDER_SIZE - state->block_padding)
#define BORDER_LEN_WIDTH(state) ((state->block_size + state->block_padding) \
        * WELL_W + WELL_BORDER_SIZE - state->block_padding)
#define BORDER_COLOR 0xaaaaaa

static void update(GState *state);
static void event_handler(GState *state);
static void draw_well(GState *state);
static void draw_well_borders(GState *state);
static void draw_score(GState *state);
static void draw_next_falling(GState *state);
static void draw_surface(GState *state, SDL_Surface *surface, int x, int y);
static void destroy_state(GState *state);
static void error_exit_state(GState *state, const char *msg);
static void error_exit(const char *msg);

GState *graphics_init(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        error_exit("unable to init SDL");
    GState *state = (GState*)malloc(sizeof(GState));
    if (state == NULL)
    {
        fprintf(stderr, "Error: unable to allocate memory for graphic state");
        exit(EXIT_FAILURE);
    }
    if (TTF_Init() < 0)
    {
        free(state);
        error_exit("unable to init TTF");
    }
    state->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X, WINDOW_Y,
            width, height, 0);
    if (state->window == NULL)
        error_exit("unable to create window");
    state->tetris = NULL;
    state->font = NULL;
    state->renderer = SDL_CreateRenderer(state->window, -1, 0);
    if (state->renderer == NULL)
        error_exit_state(state, "unable to create renderer");
    if ((state->font = TTF_OpenFont("./fonts/potra/Potra.ttf", FONT_PTSIZE)) == NULL)
        error_exit_state(state, "unable to open font");
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
    if (TTF_WasInit())
        TTF_Quit();
    if (SDL_WasInit(SDL_INIT_VIDEO))
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
    draw_well(state);
    draw_well_borders(state);
    draw_score(state);
    draw_next_falling(state);
    SDL_RenderPresent(state->renderer);
}

static void draw_well(GState *state)
{
    SDL_Rect block_rect;
    block_rect.w = state->block_size;
    block_rect.h = state->block_size;
    for (int i = 0; i < WELL_H; i++)
        for (int j = 0; j < WELL_W; j++)
        {
            SET_RENDER_COLOR(state->renderer, state->tetris->well[i + PREDROP_BUF_SIZE][j]);
            block_rect.x = j * state->block_size + j * state->block_padding + WELL_BORDER_SIZE;
            block_rect.y = i * state->block_size + i * state->block_padding + WELL_BORDER_SIZE;
            SDL_RenderFillRect(state->renderer, &block_rect);
        }
}

static void draw_well_borders(GState *state)
{
    SDL_Rect border_left;
    SDL_Rect border_right;
    SDL_Rect border_up;
    SDL_Rect border_bottom;

    Color border_color = { .hexcode = BORDER_COLOR };
    SET_RENDER_COLOR(state->renderer, border_color);
    border_left.x = 0;
    border_left.y = 0;
    border_left.w = WELL_BORDER_SIZE;
    border_left.h = BORDER_LEN_HEIGHT(state);
    SDL_RenderFillRect(state->renderer, &border_left);
    border_right.x = BORDER_LEN_WIDTH(state);
    border_right.y = 0;
    border_right.w = WELL_BORDER_SIZE;
    border_right.h = BORDER_LEN_HEIGHT(state);
    SDL_RenderFillRect(state->renderer, &border_right);
    border_up.x = 0;
    border_up.y = 0;
    border_up.w = BORDER_LEN_WIDTH(state);
    border_up.h = WELL_BORDER_SIZE;
    SDL_RenderFillRect(state->renderer, &border_up);
    border_bottom.x = 0;
    border_bottom.y = BORDER_LEN_HEIGHT(state);
    border_bottom.w = BORDER_LEN_WIDTH(state) + WELL_BORDER_SIZE;
    border_bottom.h = WELL_BORDER_SIZE;
    SDL_RenderFillRect(state->renderer, &border_bottom);
}

static void draw_score(GState *state)
{
    SDL_Color text_color = { .r = 255, .g = 255, .b = 255, .a = 255 };
    SDL_Surface *score_text_surface = TTF_RenderText_Solid(state->font, "score", text_color);
    if (score_text_surface == NULL)
        error_exit_state(state, "unable to create score text surface");
    draw_surface(state, score_text_surface, BORDER_LEN_WIDTH(state) + SCORE_MARGIN, 0);

    char score_str[128];
    snprintf(score_str, 128, "%d", state->tetris->score);
    SDL_Surface *score_text = TTF_RenderText_Solid(state->font, score_str, text_color);
    draw_surface(state, score_text,  BORDER_LEN_WIDTH(state) + SCORE_MARGIN, 40);
}

static void draw_next_falling(GState *state)
{
    SDL_Rect block;
    block.w = state->block_size;
    block.h = state->block_size;
    SDL_SetRenderDrawColor(state->renderer, 255, 255, 255, 255);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (TETRIMINOES[state->tetris->next_falling_index][0][i][j] == EMPTY_COLOR)
                continue;
            block.x = i * (state->block_padding + state->block_size)
                + NEXT_FALLING_MARGIN_LEFT + BORDER_LEN_WIDTH(state);
            block.y = j * (state->block_padding + state->block_size) + NEXT_FALLING_MARGIN_TOP;
            SDL_RenderFillRect(state->renderer, &block);

        }
}

static void draw_surface(GState *state, SDL_Surface *surface, int x, int y)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(state->renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL)
        error_exit_state(state, "unable to create texture");
    SDL_Rect frame;
    if (SDL_QueryTexture(texture, NULL, NULL, &frame.w, &frame.h) != 0)
    {
        SDL_DestroyTexture(texture);
        error_exit_state(state, "unable to load texture");
    }
    frame.x = x;
    frame.y = y;
    if (SDL_RenderCopy(state->renderer, texture, NULL, &frame) != 0)
    {
        SDL_DestroyTexture(texture);
        error_exit_state(state, "unable to render texture");
    }
    SDL_DestroyTexture(texture);
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
                if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_j)
                    state->soft_drop = false;
        }
    }
}

static void destroy_state(GState *state)
{
    if (state == NULL)
        return;
    tetris_destroy(state->tetris);
    TTF_CloseFont(state->font);
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
    if (TTF_WasInit())
        TTF_Quit();
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
    exit(EXIT_FAILURE);
}
