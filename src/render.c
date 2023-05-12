#include <render.h>
#include <vector3f.h>
#include <vector2f.h>
#include <stdbool.h>
#include <math.h>

struct Ray render_ray_init(struct Vector3f position, 
    struct Vector3f direction) 
{
    struct Ray ray;
    ray.position = position;
    ray.direction = direction;
    return ray;
}
struct Sphere render_sphere_init(struct Vector3f position, float radius) {
    struct Sphere sphere;
    sphere.position = position;
    sphere.radius = radius;
    return sphere;
}
struct Camera render_camera_init(struct Vector3f position,
    struct Vector3f angle, struct Vector2f field_of_view, 
    float field_of_view_distance)
{
    struct Camera camera;
    camera.position = position;
    camera.angle = angle;
    camera.field_of_view = field_of_view;
    camera.field_of_view_distance = field_of_view_distance;
    return camera;
};
struct RayResults render_cast(struct Ray ray, struct Sphere sphere) {
    struct RayResults results;

    struct Vector3f ray_sphere_offset = vector3f_sub(ray.position, 
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
struct Vector3f render_pixel_direction(struct Camera camera, 
    struct Vector2f pixel) 
{

}