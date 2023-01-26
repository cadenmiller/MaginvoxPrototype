#include <math.h>

#include "vector.h"

/**********
 * waVector2f
 **********/

const waVector2f waVector2f::zero{0.0f}; 
const waVector2f waVector2f::one{1.0f};
const waVector2f waVector2f::up{0.0f, 1.0f};
const waVector2f waVector2f::left{-1.0f, 0.0f};

waVector2f::waVector2f()
{
    *this = zero;
}

waVector2f::waVector2f(const waVector2f& other)
    : x(other.x), y(other.y)
{
}

waVector2f::waVector2f(float xy)
    : x(xy), y(xy)
{
}

waVector2f::waVector2f(float x, float y)
    : x(x), y(y)
{
}

float waVector2f::magnitude() const
{
    return sqrtf(x*x + y*y);
}

float waVector2f::dot(const waVector2f& other) const
{
    return x*other.x + y*other.y;
}

float waVector2f::angle(const waVector2f& other) const
{
    return acosf(dot(other) / magnitude() * other.magnitude());
}

/**********
 * waVector3f
 **********/

const waVector3f waVector3f::zero{0.0f};
const waVector3f waVector3f::one{1.0f};
const waVector3f waVector3f::up{0.0f, 1.0f, 0.0f};
const waVector3f waVector3f::left{-1.0f, 0.0f, 0.0f};
const waVector3f waVector3f::forward{0.0f, 0.0f, 1.0f};

waVector3f::waVector3f()
{
    *this = zero;
}

waVector3f::waVector3f(const waVector3f& other)
    : x(other.x), y(other.y), z(other.z)
{
}

waVector3f::waVector3f(float xyz)
    : x(xyz), y(xyz), z(xyz)
{
}

waVector3f::waVector3f(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

float waVector3f::magnitude() const
{
    return sqrtf(x*x + y*y + z*z);
}

float waVector3f::dot(const waVector3f& other) const
{
    return x*other.x + y*other.y + z*other.z;
}

float waVector3f::angle(const waVector3f& other) const
{
    return acosf(dot(other) / magnitude()*other.magnitude());
}

waVector3f waVector3f::cross(const waVector3f& other) const
{
    return waVector3f{
        y*other.z - z*other.y,
        z*other.x - x*other.z,
        x*other.y - y*other.x};
}

/**********
 * waVector4f
 **********/

const waVector4f waVector4f::zero{0.0f};
const waVector4f waVector4f::one{1.0f};

waVector4f::waVector4f()
{
    *this = zero;
}

waVector4f::waVector4f(const waVector4f& other)
    : x(other.x), y(other.y), z(other.z), w(other.w)
{
}

waVector4f::waVector4f(float xyzw)
    : x(xyzw), y(xyzw), z(xyzw), w(xyzw)
{
}

waVector4f::waVector4f(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
{
}

waVector4f& waVector4f::operator=(const waVector4f& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    return *this;
}

waVector4f waVector4f::operator+(const waVector4f& other) const
{
    return waVector4f{x+other.x, y+other.y, z+other.z, w+other.w};
}

waVector4f waVector4f::operator-(const waVector4f& other) const
{
    return waVector4f{x-other.x, y-other.y, z-other.z, w-other.w};
}

waVector4f waVector4f::operator*(const waVector4f& other) const
{
    return waVector4f{x*other.x, y*other.y, z*other.z, w*other.w};
}

waVector4f waVector4f::operator/(const waVector4f& other) const
{
    return waVector4f{x/other.x, y/other.y, z/other.z, w/other.w};
}

float waVector4f::magnitude() const
{
    return sqrtf(x*x + y*y + z*z + w*w);
}

float waVector4f::dot(const waVector4f& other) const
{
    return x*other.x + y*other.y + z*other.z + w*other.w;
}

float waVector4f::angle(const waVector4f& other) const
{
    return acosf(dot(other)/magnitude()*other.magnitude());
}
