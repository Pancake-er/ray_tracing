#ifndef IMAGE_MAKER_INCLUDED
#define IMAGE_MAKER_INCLUDED

#include <stdlib.h>

void image_maker_ppm(char *path, int width, int height, int color_depth, 
    unsigned char* rgb_pixels, size_t rgb_pixels_count);

#endif