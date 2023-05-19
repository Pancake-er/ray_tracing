#ifndef RENDER_INCLUDED
#define RENDER_INCLUDED

#include <vector3f.h>
#include <vector2f.h>
#include <stdbool.h>

struct RGB {
    float red;
    float green;
    float blue;
};
struct Ray {
    struct Vector3f position;
    struct Vector3f direction;
};
struct Sphere {
    struct Vector3f position;
    float radius;
    struct RGB color;
};
struct RayResults {
    bool hit;
    float distance;
    struct RGB color;
};
struct Camera {
    struct Vector3f position;
    struct Vector3f angle;
    float field_of_view;
    float focal_length;
};
struct RGB render_rgb_init(float red, float green, float blue);
struct Ray render_ray_init(struct Vector3f position, 
    struct Vector3f direction);
struct Sphere render_sphere_init(struct Vector3f position, float radius, 
    struct RGB color);
struct Camera render_camera_init(struct Vector3f position,
    struct Vector3f angle, float field_of_view, float plane_width);
struct RayResults render_cast(struct Ray ray, struct Sphere sphere);
struct Vector3f render_pixel_direction(struct Camera camera, 
    struct Vector2f pixel);

#endif