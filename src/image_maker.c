#include <image_maker.h>
#include <stdio.h>
#include <stdlib.h>

void image_maker_ppm(char *path, int width, int height, int color_depth, 
    unsigned char* colors, size_t colors_count) {

    if (colors_count != width * height * 3) {
        printf("The amount of colors must be the same as width * height * 3\n");
        exit(EXIT_FAILURE);
    }
    if (!(color_depth > 0 && color_depth < 65536)) {
        printf("Depth must be a value between 0 and 65536\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(path, "w");
    if (file == NULL) {  
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "P6 %d %d %d\n", width, height, color_depth);
    fwrite(colors, sizeof(unsigned char), colors_count, file);
    fclose(file);
}