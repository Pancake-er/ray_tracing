#ifndef RENDER_INCLUDED
#define RENDER_INCLUDED

#include <vector3f.h>
#include <vector2f.h>
#include <stdbool.h>

struct Ray {
    struct Vector3f position;
    struct Vector3f direction;
};
struct Sphere {
    struct Vector3f position;
    float radius;
};
struct RayResults {
    bool hit;
    float distance;
};
struct Camera {
    struct Vector3f position;
    struct Vector3f angle;
    struct Vector2f field_of_view;
    float field_of_view_distance;
};
struct Ray render_ray_init(struct Vector3f position, 
    struct Vector3f direction);
struct Sphere render_sphere_init(struct Vector3f position, float radius);
struct Camera render_camera_init(struct Vector3f position,
    struct Vector3f angle, struct Vector2f field_of_view, 
    float field_of_view_distance);
struct RayResults render_cast(struct Ray ray, struct Sphere sphere);

#endif