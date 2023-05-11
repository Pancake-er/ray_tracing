#include <ray_trace.h>
#include <vector3f.h>
#include <vector2f.h>
#include <stdbool.h>
#include <math.h>

struct Ray ray_trace_ray_init(struct Vector3f position, 
    struct Vector3f direction) 
{
    struct Ray ray;
    ray.position = position;
    ray.direction = direction;
    return ray;
}
struct Sphere ray_trace_sphere_init(struct Vector3f position, float radius) {
    struct Sphere sphere;
    sphere.position = position;
    sphere.radius = radius;
    return sphere;
}
struct Camera ray_trace_camera_init(struct Vector3f position,
    struct Vector3f angle, float field_of_view) 
{
    struct Camera camera;
    camera.position = position;
    camera.angle = angle;
    camera.field_of_view = field_of_view;    
    return camera;
};
struct RayResults ray_trace_cast(struct Ray ray, struct Sphere sphere) {
    struct RayResults results;

    struct Vector3f ray_sphere_offset = vector3f_subtract(ray.position, 
        sphere.position);
    float discriminant = pow(vector3f_dot(ray_sphere_offset, ray.direction), 2) 
        - (vector3f_dot(ray_sphere_offset, ray_sphere_offset) 
        - pow(sphere.radius, 2));

    results.distance = -1 * vector3f_dot(ray_sphere_offset, ray.direction) 
        - sqrt(discriminant);
    if (discriminant < 0) {
        results.hit = false;
    }
    else {
        results.hit = true;
    }
    
    return results;
}