#pragma once

template<class T>
struct Vec3
{
    T x;
    T y;
    T z;

    Vec3() : x(0), y(0), z(0) {}
    explicit Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
    Vec3(const Vec3&) = default;
    Vec3(Vec3&&) noexcept = default;
    Vec3& operator=(const Vec3&) = default;
    Vec3& operator=(Vec3&&) noexcept = default;

    ~Vec3() = default;

    auto operator<=>(const Vec3&) const = default;
};

using Vec3f = Vec3<float>;