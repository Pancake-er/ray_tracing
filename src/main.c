#include <image_maker.h>
#include <render.h>
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
        exit(EXIT_FAILURE);
    }

    struct Camera camera = render_camera_init(vector3f_init(0.0f, 0.0f, 0.0f), 
        vector3f_init(0.0f, 0.0f, 0.0f), 60.0f, width);
    // Three sphere with the same radius, but one is closer.
    struct Sphere spheres[3] = {
        render_sphere_init(vector3f_init(20.0f, 20.0f, 150.0f), 15.0f, 
            render_rgb_init(255.0f, 0.0f, 0.0f)),
        render_sphere_init(vector3f_init(70.0f, 70.0f, 30.0f), 15.0f, 
            render_rgb_init(0.0f, 0.0f, 255.0f)),
        render_sphere_init(vector3f_init(70.0f, 70.0f, 150.0f), 15.0f, 
            render_rgb_init(0.0f, 255.0f, 0.0f)),
    };
    // Perspective raycast for every pixel on screen.
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Determine the closest sphere color for this ray or set to black.
            struct RayResults closest_results;
            closest_results.hit = false;
            closest_results.distance = 999999999.0f;
            closest_results.color = render_rgb_init(0.0f, 0.0f, 0.0f);
            // Length of spheres[].
            for (int k = 0; k < 3; k++) {
                struct RayResults results
                    = render_cast(render_ray_init(vector3f_init(i, j, 0), 
                    render_pixel_direction(camera, vector2f_init(i - 50, 
                    j - 50))), spheres[k]);
                if (results.hit && results.distance < closest_results.distance) {
                    closest_results = results;
                }
            }
            // Multiplied for shading effect. Temporary solution.
            set_pixel(data, i, j, width, closest_results.color.red 
                * (10 / closest_results.distance), closest_results.color.green 
                * (10 / closest_results.distance), closest_results.color.blue 
                * (10 / closest_results.distance)); 
        }
    }
    // Put frame buffer into a ppm image at ./output/image.ppm.
    image_maker_ppm("image.ppm", width, height, 255, data, data_size);

    free(data);
}