#ifndef WORLD_AFTER_MATH_QUATERNION_H
#define WORLD_AFTER_MATH_QUATERNION_H

class waQuaternion4f
{

public:
    float x, y, z, w;

    static const waQuaternion4f identity;

    waQuaternion4f(); /* Identity */
    waQuaternion4f(float x, float y, float z, float w);

public:
    waQuaternion4f& operator=(const waQuaternion4f& other);
    waQuaternion4f& operator*(const waQuaternion4f& other);

};

#endif /* WORLD_AFTER_MATH_QUATERNION_H */