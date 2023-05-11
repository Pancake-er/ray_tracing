#include <image_maker.h>
#include <ray_trace.h>
#include <vector3f.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void set_pixel(unsigned char *data, size_t x, size_t y, size_t width, int red, 
    int green, int blue) 
{
    data[(y * width + x) * 3] = red;
    data[(y * width + x) * 3 + 1] = green;
    data[(y * width + x) * 3 + 2] = blue;
}
int main() {
    // Allocate frame buffer.
    size_t width = 100;
    size_t height = 100;
    size_t data_size = width * height * 3;
    unsigned char *data = malloc(data_size);
    if (data == NULL) {
        printf("Failed to allocate memory");       
        exit(1);
    }

    struct Sphere sphere = ray_trace_sphere_init(vector3f_init(50, 50, 10), 40);
    // Orthographic raycast for every pixel on screen.
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            struct RayResults results 
                = ray_trace_cast(ray_trace_ray_init(vector3f_init(i, j, 0), 
                vector3f_init(0, 0, 1)), sphere);
            if (results.hit) {
                set_pixel(data, i, j, width, 255, 255, 255);
            }
            else {
                set_pixel(data, i, j, width, 0, 0, 0);
            }
        }
    }
    // Put frame buffer into a ppm image at ./res/output.ppm.
    image_maker_ppm("./output/image.ppm", width, height, 255, data, data_size);

    free(data);
}