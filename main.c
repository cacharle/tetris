#include "header.h"

int main(void)
{
    GState *gstate = graphics_init(400, 400);
    graphics_run(gstate);
    graphics_quit(gstate);
    return 0;
}
