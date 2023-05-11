#ifndef RAY_TRACE_INCLUDED
#define RAY_TRACE_INCLUDED

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
    float field_of_view;
};
struct Ray ray_trace_ray_init(struct Vector3f position, 
    struct Vector3f direction);
struct Sphere ray_trace_sphere_init(struct Vector3f position, float radius);
struct Camera ray_trace_camera_init(struct Vector3f position,
    struct Vector3f angle, float field_of_view);
struct RayResults ray_trace_cast(struct Ray ray, struct Sphere sphere);

#endif