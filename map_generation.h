#ifndef _MAP_GENERATION_H
#define _MAP_GENERATION_H

void generate_empty_map(int width, int height, int (*map)[width+2]);

void generate_random_map(int width, int height, int (*map)[width+2], int r);

int read_map(int width, int height, int (*map)[width+2]);
#endif
