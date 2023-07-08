#include "parser.h"
#include <stdlib.h>

void get_file_data(char *file_name, obj_data *data) {
    data->count_surfaces = 6;
    data->count_vertices = 10;

    unsigned int **all_surfaces = (unsigned int **)malloc(6 * sizeof(unsigned int *));
    for (int i = 0; i < 6; ++i)
    {
        all_surfaces[i] = (unsigned int *)malloc(3 * sizeof(unsigned int));
    }

    all_surfaces[0][0] = 1;
    all_surfaces[0][1] = 2;
    all_surfaces[0][2] = 3;
    all_surfaces[1][0] = 4;
    all_surfaces[1][1] = 5;
    all_surfaces[1][2] = 6;
    all_surfaces[2][0] = 4;
    all_surfaces[2][1] = 7;
    all_surfaces[2][2] = 5;
    all_surfaces[2][0] = 4;
    all_surfaces[2][1] = 8;
    all_surfaces[2][2] = 7;
    all_surfaces[3][0] = 8;
    all_surfaces[3][1] = 9;
    all_surfaces[3][2] = 7;
    all_surfaces[4][0] = 7;
    all_surfaces[4][1] = 10;
    all_surfaces[4][2] = 5;

    data->all_surfaces = all_surfaces;

    vertices *all_vertices = (vertices *)malloc(11 * sizeof(vertices));
    all_vertices[0].x = 0;
    all_vertices[0].y = 0;
    all_vertices[0].z = 0;

    all_vertices[1].x = 26.7292;
    all_vertices[1].y = 34.3821;
    all_vertices[1].z = -4.2469;

    all_vertices[2].x = 25.4339;
    all_vertices[2].y = 33.2105;
    all_vertices[2].z = -3.8287;

    all_vertices[3].x = 26.2912;
    all_vertices[3].y = 34.0415;
    all_vertices[3].z = -4.0001;

    all_vertices[4].x = 27.5827;
    all_vertices[4].y = 29.1212;
    all_vertices[4].z = -2.8183;

    all_vertices[5].x = 27.6959;
    all_vertices[5].y = 28.4554;
    all_vertices[5].z = -2.5997;

    all_vertices[6].x = 27.6897;
    all_vertices[6].y = 27.6990;
    all_vertices[6].z = -3.0215;

    all_vertices[7].x = 28.7485;
    all_vertices[7].y = 29.0138;
    all_vertices[7].z = -1.3476;

    all_vertices[8].x = 27.3359;
    all_vertices[8].y = 30.3246;
    all_vertices[8].z = -1.4240;

    all_vertices[9].x = 27.6785;
    all_vertices[9].y = 30.2648;
    all_vertices[9].z = -0.6191;

    all_vertices[10].x = 28.4329;
    all_vertices[10].y = 28.3617;
    all_vertices[10].z = -1.6861;

    data->all_vertices = all_vertices;
}

// f 1/1/1 2/2/2 3/3/3 
// f 4/4/4 5/5/5 6/6/6 
// f 4/4/4 7/7/7 5/5/5 

// f 4/4/4 8/8/8 7/7/7 
// f 8/8/8 9/9/9 7/7/7 
// f 7/7/7 10/10/10 5/5/5 

// v  26.7292 34.3821 -4.2469
// v  25.4339 33.2105 -3.8287
// v  26.2912 34.0415 -4.0001
// v  27.5827 29.1212 -2.8183
// v  27.6959 28.4554 -2.5997
// v  27.6897 27.6990 -3.0215
// v  28.7485 29.0138 -1.3476
// v  27.3359 30.3246 -1.4240
// v  27.6785 30.2648 -0.6191
// v  28.4329 28.3617 -1.6861
