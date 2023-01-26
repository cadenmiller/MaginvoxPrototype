waVector2f& waVector2f::operator=(const waVector2f& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

waVector2f& waVector2f::operator+=(const waVector2f& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

waVector2f& waVector2f::operator-=(const waVector2f& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

waVector2f& waVector2f::operator*=(const waVector2f& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

waVector2f& waVector2f::operator/=(const waVector2f& rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

waVector2f waVector2f::operator+(const waVector2f& rhs) const
{
    return waVector2f(x+rhs.x, y+rhs.y);
}

waVector2f waVector2f::operator-(const waVector2f& rhs) const
{
    return waVector2f(x-rhs.x, y+rhs.y);
}

waVector2f waVector2f::operator*(const waVector2f& rhs) const
{
    return waVector2f(x*rhs.x, y*rhs.y);
}

waVector2f waVector2f::operator/(const waVector2f& rhs) const
{
    return waVector2f(x/rhs.x, y/rhs.y);
}

waVector3f& waVector3f::operator=(const waVector3f& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

waVector3f& operator=(const waVector3f& other)
{
    
}

waVector3f& operator+=(const waVector3f& other)
{

}

waVector3f& operator-=(const waVector3f& other)
{

}

waVector3f& operator*=(const waVector3f& other)
{

}

waVector3f& operator/=(const waVector3f& other)
{

}

waVector3f waVector3f::operator+(const waVector3f& other) const
{
    return waVector3f{x+other.x, y+other.y, z+other.z};
}

waVector3f waVector3f::operator-(const waVector3f& other) const
{
    return waVector3f{x-other.x, y-other.y, z-other.z};
}

waVector3f waVector3f::operator*(const waVector3f& other) const
{
    return waVector3f{x*other.x, y*other.y, z*other.z};
}

waVector3f waVector3f::operator/(const waVector3f& other) const
{
    return waVector3f{x/other.x, y/other.y, z/other.z};
}
