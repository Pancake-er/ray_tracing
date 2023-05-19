#include <render.h>
#include <vector3f.h>
#include <vector2f.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

struct RGB render_rgb_init(float red, float green, float blue) {
    struct RGB color;
    color.red = red;
    color.green = green;
    color.blue = blue;
    return color;
}
struct Ray render_ray_init(struct Vector3f position, 
    struct Vector3f direction) 
{
    struct Ray ray;
    ray.position = position;
    ray.direction = direction;
    return ray;
}
struct Sphere render_sphere_init(struct Vector3f position, float radius, 
    struct RGB color) 
{
    struct Sphere sphere;
    sphere.position = position;
    sphere.radius = radius;
    sphere.color.red = color.red;
    sphere.color.green = color.green;
    sphere.color.blue = color.blue;
    return sphere;
}
struct Camera render_camera_init(struct Vector3f position,
    struct Vector3f angle, float field_of_view, float plane_width)
{
    struct Camera camera;
    camera.position = position;
    camera.angle = angle;
    camera.field_of_view = field_of_view;
    camera.focal_length = plane_width / 2 / sqrt(pow(tan(field_of_view * 3.141f 
        / 180 / 2.0f), 2.0f));
    return camera;
}
struct RayResults render_cast(struct Ray ray, struct Sphere sphere) {
    struct RayResults results;
    results.color = render_rgb_init(0.0f, 0.0f, 0.0f);

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
        results.color = sphere.color;
    }
    
    return results;
}
struct Vector3f render_pixel_direction(struct Camera camera, 
    struct Vector2f pixel) 
{
    return vector3f_normalize(vector3f_sub(vector3f_init(pixel.x, pixel.y, 
        camera.focal_length), camera.position));
}