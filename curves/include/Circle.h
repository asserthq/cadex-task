#pragma once
#include "ICurve.h"

#include <cmath>

class Circle : public ICurve
{
public:
    Circle() = default;
    explicit Circle(float radius) : m_rad(std::abs(radius)) {}

    virtual Vec3f Point(float t) const override;
    virtual Vec3f Derivative(float t) const override;
    virtual std::string ToString() const override;

    float Radius() const { return m_rad; }
    void SetRadius(float radius) { m_rad = std::abs(radius); }

    bool operator==(const Circle& other) const { return m_rad == other.m_rad; };

protected:
    float m_rad{1.f};
};