#pragma once
#include "Vec3.h"

class ICurve
{
public:
    virtual ~ICurve() = default;

    virtual Vec3f Point(float t) const = 0;
    virtual Vec3f Derivative(float t) const = 0;
};