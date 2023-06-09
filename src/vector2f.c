#include <vector2f.h>
#include <math.h>

struct Vector2f vector2f_init(float x, float y) {
    struct Vector2f vector;
    vector.x = x;
    vector.y = y;
    return vector;
}
struct Vector2f vector2f_scale(struct Vector2f vector, float scalar) {
    vector.x *= scalar;
    vector.y *= scalar;
    return vector;
}
struct Vector2f vector2f_add(struct Vector2f vector1, struct Vector2f vector2) {
    vector1.x += vector2.x;
    vector1.y += vector2.y;
    return vector1;
}
struct Vector2f vector2f_sub(struct Vector2f vector1, 
    struct Vector2f vector2) 
{
    vector1.x -= vector2.x;
    vector1.y -= vector2.y;
    return vector1;
}
float vector2f_dot(struct Vector2f vector1, struct Vector2f vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y;
}
float vector2f_distance(struct Vector2f vector1, struct Vector2f vector2) {
    return sqrt(pow(vector1.x - vector2.x, 2) + pow(vector1.y - vector2.y, 2));
}
float vector2f_magnitude(struct Vector2f vector) {
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}
struct Vector2f vector2f_normalize(struct Vector2f vector) {
    float magnitude = vector2f_magnitude(vector);
    vector.x /= magnitude;
    vector.y /= magnitude;
    return vector;
}