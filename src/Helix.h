#pragma once
#include "Circle.h"

#include <cmath>

class Helix : public Circle
{
public:
    Helix() = default;
    explicit Helix(float radius, float step)
        : Circle(radius), m_step(step) {}

    virtual Vec3f Point(float t) const override;
    virtual Vec3f Derivative(float t) const override;

    float Step() const { return m_step; }
    void SetStep(float step) { m_step = step; }

    bool operator==(const Helix& other)
    {
        return  m_rad == other.m_rad &&
                m_step == other.m_step;
    }

protected:
    float m_step{1.f};
};