#pragma once
#include <iostream>
#include <sstream>

template<class T>
struct Vec3
{
    T x{};
    T y{};
    T z{};

    Vec3() = default;
    explicit Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    bool operator==(const Vec3&) const = default;
};

using Vec3f = Vec3<float>;
using Vec3d = Vec3<double>;

inline std::ostream& operator<<(std::ostream& os, const Vec3f& vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}