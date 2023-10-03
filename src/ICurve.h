#pragma once
#include "Vector3D.h"

class ICurve
{
public:
    using PointTy = Vector3D<float>;

public:
    virtual ~ICurve() = default;

    virtual PointTy Point(float t) const = 0;
    virtual PointTy Derivative(float t) const = 0;
};