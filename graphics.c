#include <stdbool.h>
#include <SDL2/SDL.h>
#include "header.h"

#define WINDOW_TITLE "Title"
#define WINDOW_X 20
#define WINDOW_Y 20

static void update(GState *state);
static void event_handler(GState *state);
static void destroy_state(GState *state);
static void error_exit_state(GState *state, const char *msg);
static void error_exit(const char *msg);

GState *graphics_init(int width, int height)
{
    GState *state = (GState*)malloc(sizeof(GState));
    if (state == NULL)
        return NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        error_exit("unable to init SDL");
    state->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_X, WINDOW_Y,
            width, height, 0);
    if (state->window == NULL)
        error_exit("unable to create window");
    state->renderer = SDL_CreateRenderer(state->window, -1, 0);
    if (state->renderer == NULL)
        error_exit_state(state, "unable to create renderer");
    state->running = true;
    return state;
}

void graphics_quit(GState *state)
{
    destroy_state(state);
    SDL_Quit();
}

void graphics_run(GState *state)
{
    while (state->running)
    {
        event_handler(state);
        update(state);
        SDL_Delay(10);
    }
}

static void update(GState *state)
{
    //do stuff
}

static void event_handler(GState *state)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                state->running =
                    false;
                break;
        }
    }
}

static void destroy_state(GState *state)
{
    if (state == NULL)
        return;
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
