#include <stdlib.h>
#include <time.h>
#include "header.h"

#define DEFAULT_WINDOW_W 400
#define DEFAULT_WINDOW_H 600

int main(void)
{
    srand(time(NULL));
    /*  */
    /* int ****ts = malloc(sizeof(int***) * 7); */
    /* if (ts == NULL) */
    /*     return EXIT_FAILURE; */
    /* for (int i = 0; i < 7; i++) */
    /* { */
    /*     ts[i] = malloc(sizeof(int**) * 4); */
    /*     if (ts[i] == NULL) */
    /*         return EXIT_FAILURE; */
    /*     for (int j = 0; j < 4; j++) */
    /*     { */
    /*         ts[i][j] = malloc(sizeof(int*) * 4); */
    /*         if (ts[i][j] == NULL) */
    /*             return EXIT_FAILURE; */
    /*         for (int k = 0; k < 4; k++) */
    /*         { */
    /*             ts[i][j][k] = malloc(sizeof(int) * 4); */
    /*             if (ts[i][j][k] == NULL) */
    /*                 return EXIT_FAILURE; */
    /*             for (int l = 0; l < 4; l++) */
    /*                 ts[i][j][k][l] = TETRIMINOES[i][j][k][l]; */
    /*         } */
    /*     } */
    /* } */

    GState *gstate = graphics_init(DEFAULT_WINDOW_W, DEFAULT_WINDOW_H);
    if (gstate == NULL)
        return EXIT_FAILURE;
    gstate->tetris->well[21][0].hexcode = 0xff0000;
    gstate->tetris->well[21][1].hexcode = 0xff0000;
    gstate->tetris->well[21][2].hexcode = 0xff0000;
    gstate->tetris->well[21][3].hexcode = 0xff0000;
    gstate->tetris->well[21][4].hexcode = 0xff0000;
    gstate->tetris->well[21][5].hexcode = 0xff0000;
    gstate->tetris->well[21][6].hexcode = 0xff0000;
    gstate->tetris->well[21][7].hexcode = 0xff0000;
    gstate->tetris->well[21][8].hexcode = 0xff0000;
    gstate->tetris->well[21][9].hexcode = 0xff0000;
    gstate->tetris->well[21][10].hexcode = 0xff0000;
    gstate->tetris->well[21][11].hexcode = 0xff0000;
    gstate->tetris->well[20][0].hexcode = 0xff0000;
    gstate->tetris->well[20][1].hexcode = 0xff0000;
    gstate->tetris->well[20][2].hexcode = 0xff0000;
    gstate->tetris->well[20][3].hexcode = 0xff0000;
    gstate->tetris->well[20][4].hexcode = 0xff0000;
    gstate->tetris->well[20][5].hexcode = 0xff0000;
    gstate->tetris->well[20][6].hexcode = 0xff0000;
    gstate->tetris->well[20][7].hexcode = 0xff0000;
    gstate->tetris->well[20][8].hexcode = 0xff0000;
    gstate->tetris->well[20][9].hexcode = 0xff0000;
    gstate->tetris->well[20][10].hexcode = 0xff0000;
    gstate->tetris->well[20][11].hexcode = 0xff0000;
    gstate->tetris->well[19][0].hexcode = 0xff0000;
    gstate->tetris->well[19][1].hexcode = 0xff0000;
    gstate->tetris->well[19][2].hexcode = 0xff0000;
    gstate->tetris->well[19][3].hexcode = 0xff0000;
    gstate->tetris->well[19][4].hexcode = 0xff0000;
    gstate->tetris->well[19][5].hexcode = 0xff0000;
    gstate->tetris->well[19][6].hexcode = 0xff0000;
    gstate->tetris->well[19][7].hexcode = 0xff0000;
    gstate->tetris->well[19][8].hexcode = 0xff0000;
    gstate->tetris->well[19][9].hexcode = 0xff0000;
    gstate->tetris->well[19][10].hexcode = 0xff0000;
    gstate->tetris->well[19][11].hexcode = 0xff0000;
    gstate->tetris->well[18][0].hexcode = 0xff0000;
    gstate->tetris->well[18][1].hexcode = 0xff0000;
    gstate->tetris->well[18][2].hexcode = 0xff0000;
    gstate->tetris->well[18][3].hexcode = 0xff0000;
    gstate->tetris->well[18][4].hexcode = 0xff0000;
    gstate->tetris->well[18][5].hexcode = 0xff0000;
    gstate->tetris->well[18][6].hexcode = 0xff0000;
    gstate->tetris->well[18][7].hexcode = 0xff0000;
    gstate->tetris->well[18][8].hexcode = 0xff0000;
    gstate->tetris->well[18][9].hexcode = 0xff0000;
    gstate->tetris->well[18][10].hexcode = 0xff0000;
    gstate->tetris->well[18][11].hexcode = 0xff0000;
    graphics_run(gstate);
    graphics_quit(gstate);
    return EXIT_SUCCESS;
}
