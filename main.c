#include <stdlib.h>
#include <time.h>
#include "header.h"

#define DEFAULT_WINDOW_W 400
#define DEFAULT_WINDOW_H 600

int main(void)
{
    srand(time(NULL));
    GState *gstate = graphics_init(DEFAULT_WINDOW_W, DEFAULT_WINDOW_H);
    if (gstate == NULL)
        return EXIT_FAILURE;
    /* gstate->tetris->well[21][0].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][1].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][2].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][3].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][4].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][5].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][6].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][7].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][8].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][9].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][10].hexcode = 0xff0000; */
    /* gstate->tetris->well[21][11].hexcode = 0xff0000; */
    graphics_run(gstate);
    graphics_quit(gstate);
    return EXIT_SUCCESS;
}
