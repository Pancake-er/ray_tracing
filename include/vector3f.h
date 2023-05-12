#ifndef VECTOR3F_INCLUDED
#define VECTOR3F_INCLUDED

struct Vector3f {
    float x;
    float y;
    float z;
};
struct Vector3f vector3f_init(float x, float y, float z);
struct Vector3f vector3f_scale(struct Vector3f vector, float scalar);
struct Vector3f vector3f_add(struct Vector3f vector1, struct Vector3f vector2);
struct Vector3f vector3f_sub(struct Vector3f vector1, 
    struct Vector3f vector2);
float vector3f_dot(struct Vector3f vector1, struct Vector3f vector2);
float vector3f_distance(struct Vector3f vector1, struct Vector3f vector2);

#endif