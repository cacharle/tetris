#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <SDL2/SDL.h>

typedef struct
{
        SDL_Window *window;
            SDL_Renderer *renderer;
                bool running;
} GState;

GState *graphics_init(int width, int height);
void graphics_quit(GState *state);
void graphics_run(GState *state);

#endif
