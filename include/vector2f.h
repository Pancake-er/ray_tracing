#ifndef VECTOR2F_INCLUDED
#define VECTOR2F_INCLUDED

struct Vector2f {
    float x;
    float y;
};
struct Vector2f vector2f_init(float x, float y);
struct Vector2f vector2f_scale(struct Vector2f vector, float scalar);
struct Vector2f vector2f_add(struct Vector2f vector1, struct Vector2f vector2);
struct Vector2f vector2f_subtract(struct Vector2f vector1, 
    struct Vector2f vector2);
float vector2f_dot(struct Vector2f vector1, struct Vector2f vector2);
float vector2f_distance(struct Vector2f vector1, struct Vector2f vector2);
#endif