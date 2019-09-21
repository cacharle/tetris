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
    graphics_run(gstate);
    graphics_quit(gstate);
    return EXIT_SUCCESS;
}
