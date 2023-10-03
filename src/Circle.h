#pragma once
#include "ICurve.h"

#include <algorithm>

class Circle : public ICurve
{
public:
    explicit Circle(float radius) : m_rad(std::max(radius, 0.f)) {}

    virtual PointTy Point(float t) const override;
    virtual PointTy Derivative(float t) const override;

private:
    float m_rad;
};