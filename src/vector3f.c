#include <vector3f.h>
#include <math.h>

struct Vector3f vector3f_init(float x, float y, float z) {
    struct Vector3f vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}
struct Vector3f vector3f_scale(struct Vector3f vector, float scalar) {
    vector.x *= scalar;
    vector.y *= scalar;
    vector.z *= scalar;
    return vector;
}
struct Vector3f vector3f_add(struct Vector3f vector1, struct Vector3f vector2) {
    vector1.x += vector2.x;
    vector1.y += vector2.y;
    vector1.z += vector2.z;
    return vector1;
}
struct Vector3f vector3f_sub(struct Vector3f vector1, 
    struct Vector3f vector2) 
{
    vector1.x -= vector2.x;
    vector1.y -= vector2.y;
    vector1.z -= vector2.z;
    return vector1;
}
float vector3f_dot(struct Vector3f vector1, struct Vector3f vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z 
        * vector2.z;
}
float vector3f_distance(struct Vector3f vector1, struct Vector3f vector2) {
    return sqrt(pow(vector1.x - vector2.x, 2) + pow(vector1.y - vector2.y, 2) 
        + pow(vector1.z - vector2.z, 2));
}
float vector3f_magnitude(struct Vector3f vector) {
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}
struct Vector3f vector3f_normalize(struct Vector3f vector) {
    float magnitude = vector3f_magnitude(vector);
    vector.x /= magnitude;
    vector.y /= magnitude;
    vector.z /= magnitude;
    return vector;
}