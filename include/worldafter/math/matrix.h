#ifndef WORLD_AFTER_MATH_MATRIX_H
#define WORLD_AFTER_MATH_MATRIX_H


#include "vector.h"
#include "quaternion.h"


/***
 * I'm not sure what else to implement concerning waMatrix2f. 
 * Not certain that it's really going to be that important yet.
 */

class waMatrix2f
{

public:
    float m11, m12,
          m21, m22;

    static const waMatrix2f identity;

    waMatrix2f(); /* Identity */
    waMatrix2f(float m11, float m12, float m21, float m22);

public:
    waMatrix2f& operator=(const waMatrix2f& other);

    waMatrix2f& operator+(waMatrix2f& other);
    waMatrix2f& operator-(waMatrix2f& other);
    waMatrix2f& operator*(waMatrix2f& other);

public:
    float determinant();

};

class waMatrix3f
{

public:
    float m11, m12, m13,
          m21, m22, m23,
          m31, m32, m33;

    static const waMatrix3f identity;

    waMatrix3f(); /* Identity */
    waMatrix3f(float m11, float m12, float m13, float m21, float m22,
        float m23, float m31, float m32, float m33);

public:
    waMatrix3f& operator=(const waMatrix3f& other);

    waMatrix3f& operator+(const waMatrix3f& other) const;
    waMatrix3f& operator-(const waMatrix3f& other) const;
    waMatrix3f& operator*(const waMatrix3f& other) const;

public:
    float determinant() const;
    waMatrix3f inverted() const;
    waMatrix3f transposed() const;

    waMatrix3f& invert() const;
    waMatrix3f& transpose();
    waMatrix3f& translate(waVector2f& translation);
    waMatrix3f& rotate(float angle);
    waMatrix3f& scale(waVector2f& scale);
    waMatrix3f& scaleScalar(float scalar);

};

class waMatrix4f
{

public:
    float m11, m12, m13, m14, 
          m21, m22, m23, m24, 
          m31, m32, m33, m34, 
          m41, m42, m43, m44;

    static const waMatrix4f identity;

    waMatrix4f(); /* Identity */
    waMatrix4f(float m11, float m12, float m13, float m14, float m21,
        float m22, float m23, float m24, float m31, float m32,
        float m33, float m34, float m41, float m42, float m43,
        float m44);
    
public:
    waMatrix4f& operator=(waMatrix4f& other);
    
    waMatrix4f& operator+(waMatrix4f& other) const;
    waMatrix4f& operator-(waMatrix4f& other) const;
    waMatrix4f& operator*(waMatrix4f& other) const;

public:

    float determinant() const;
    waMatrix4f inverse() const;
    waMatrix4f transposed() const;

    waMatrix4f& invert();
    waMatrix4f& transpose();
    waMatrix4f& translate(waVector3f& translation);
    waMatrix4f& rotate(waQuaternion4f& rotation);
    waMatrix4f& rotateEuler(waVector3f& rotationEuler);
    waMatrix4f& scale(waVector3f& scale);
    waMatrix4f& scaleScalar(float scalar);
    waMatrix4f& setTranslation(waVector3f& translation);
    waMatrix4f& setRotation(waQuaternion4f& rotation);
    waMatrix4f& setRotationEuler(waVector3f& rotationEuler);
    waMatrix4f& setScale(waVector3f& scale);
    waMatrix4f& setScaleScalar(float scalar);


};

#endif /* WORLD_AFTER_MATH_MATRIX_H */