#pragma once
#include "Vector3D.h"

class ICurve
{
public:
    using ParamTy = float;
    using PointTy = Vector3D<float>;

public:
    virtual ~ICurve() = default;

    virtual PointTy Point(ParamTy t) = 0;
    virtual PointTy Derivative(ParamTy t) = 0;
};