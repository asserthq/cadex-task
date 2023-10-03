#pragma once
#include "ICurve.h"

#include <algorithm>

class Circle : public ICurve
{
public:
    explicit Circle(float radius) : m_rad(std::max(radius, 0.f)) {}

    virtual Vec3f Point(float t) const override;
    virtual Vec3f Derivative(float t) const override;

private:
    float m_rad;
};