#ifndef WORLD_AFTER_ENGINE_MATH_VECTOR_H
#define WORLD_AFTER_ENGINE_MATH_VECTOR_H

#include <math.h>

class waVector2f
{

public:
    float x, y;

    static const waVector2f zero;
    static const waVector2f one;
    static const waVector2f up;
    static const waVector2f left;

    waVector2f(); /* zero */
    waVector2f(float xy);
    waVector2f(float x, float y);

public:
    waVector2f& operator=(const waVector2f& other);

    waVector2f operator+(const waVector2f& other);
    waVector2f operator-(const waVector2f& other);
    waVector2f operator*(const waVector2f& other); /* multiply components, not dot product */
    waVector2f operator/(const waVector2f& other);

public:
    float dot(); 
    float magnitude();
    float angleFrom(waVector2f& b); /* angle from this (a) to b */
};

class waVector3f
{

public:
    float x, y, z;

    static const waVector3f zero;
    static const waVector3f one;
    static const waVector3f up;
    static const waVector3f left;
    static const waVector3f forward;

    waVector3f(); /* zero */
    waVector3f(float xyz);
    waVector3f(float x, float y, float z);

public:
    waVector3f& operator=(const waVector3f& other);

    waVector3f operator+(const waVector3f& other);
    waVector3f operator-(const waVector3f& other);
    waVector3f operator*(const waVector3f& other); /* multiply components, not dot product */
    waVector3f operator/(const waVector3f& other);

public:
    float dot(); 
    float magnitude();
    float angleFrom(waVector3f& b); /* angle from this (a) to b */
    waVector3f cross(waVector3f& b); /* cross product from this (a) with b*/
};

typedef struct waVector4f
{
    float x;
    float y;
    float z;
    float w;
} waVector4f;

#endif /* WORLD_AFTER_ENGINE_MATH_VECTOR_H */