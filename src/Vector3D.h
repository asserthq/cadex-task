#pragma once

template<class T>
struct Vector3D
{
    T x;
    T y;
    T z;

    vector3D() : x(0), y(0), z(0) {}
    vector3D(T x, T y, T z) : x(x), y(y), z(y) {}
    vector3D(const vector3D&) = default;
    vector3D(vector3D&&) noexcept = default;
    vector3D& operator=(const vector3D&) = default;
    vector3D& operator=(vector3D&&) noexcept = default;

    ~vector3D() = default;
};