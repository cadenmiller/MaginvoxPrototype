#ifndef WA_ENGINE_MATH_VECTOR_H
#define WA_ENGINE_MATH_VECTOR_H

class waVector2f
{

public:
    float x, y;

    static const waVector2f zero;
    static const waVector2f one;
    static const waVector2f up;
    static const waVector2f left;

    waVector2f(); /* zero */
    waVector2f(const waVector2f& copy);
    waVector2f(float xy);
    waVector2f(float x, float y);

public:
    inline waVector2f& operator=(const waVector2f& rhs);
    inline waVector2f& operator+=(const waVector2f& rhs);
    inline waVector2f& operator-=(const waVector2f& rhs);
    inline waVector2f& operator*=(const waVector2f& rhs); /* multiply components, not dot product */
    inline waVector2f& operator/=(const waVector2f& rhs);

    inline waVector2f operator+(const waVector2f& rhs) const;
    inline waVector2f operator-(const waVector2f& rhs) const;
    inline waVector2f operator*(const waVector2f& rhs) const; /* multiply components, not dot product */
    inline waVector2f operator/(const waVector2f& rhs) const;

public:
    float magnitude() const;
    float dot(const waVector2f& other) const; 
    float angle(const waVector2f& other) const;

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
    waVector3f(const waVector3f& other);
    waVector3f(float xyz);
    waVector3f(float x, float y, float z);

public:
    waVector3f& operator=(const waVector3f& other);
    waVector3f& operator+=(const waVector3f& other);
    waVector3f& operator-=(const waVector3f& other);
    waVector3f& operator*=(const waVector3f& other); /* multiply components, not dot product */
    waVector3f& operator/=(const waVector3f& other);

    waVector3f operator+(const waVector3f& other) const;
    waVector3f operator-(const waVector3f& other) const;
    waVector3f operator*(const waVector3f& other) const; /* multiply components, not dot product */
    waVector3f operator/(const waVector3f& other) const;

public:
    float magnitude() const;
    float dot(const waVector3f& other) const; 
    float angle(const waVector3f& other) const;
    waVector3f cross(const waVector3f& other) const;

};

class waVector4f
{

public:
    float x, y, z, w;

    static const waVector4f zero;
    static const waVector4f one;

    waVector4f(); /* zero */
    waVector4f(const waVector4f& other);
    waVector4f(float xyzw);
    waVector4f(float x, float y, float z, float w);

public:
    waVector4f& operator=(const waVector4f& other);
    waVector4f& operator+=(const waVector4f& other);
    waVector4f& operator-=(const waVector4f& other);
    waVector4f& operator*=(const waVector4f& other); /* multiply components, not dot product */
    waVector4f& operator/=(const waVector4f& other);

    waVector4f operator+(const waVector4f& other) const;
    waVector4f operator-(const waVector4f& other) const;
    waVector4f operator*(const waVector4f& other) const; /* multiply components, not dot product */
    waVector4f operator/(const waVector4f& other) const;
    
public:
    float magnitude() const;
    float dot(const waVector4f& other) const;
    float angle(const waVector4f& other) const;

};

#include "vector.inl"

#endif /* WA_ENGINE_MATH_VECTOR_H */