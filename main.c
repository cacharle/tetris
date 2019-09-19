#include <stdlib.h>
#include "header.h"

#define DEFAULT_WINDOW_W 400
#define DEFAULT_WINDOW_H 600

int main(void)
{
    GState *gstate = graphics_init(DEFAULT_WINDOW_W, DEFAULT_WINDOW_H);
    graphics_run(gstate);
    graphics_quit(gstate);
    return EXIT_SUCCESS;
}
