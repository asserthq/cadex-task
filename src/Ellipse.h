#pragma once
#include "ICurve.h"

#include <cmath>

class Ellipse : public ICurve
{
public:
    Ellipse() = default;
    explicit Ellipse(float x_rad, float y_rad)
        : m_radX(std::abs(x_rad)), m_radY(std::abs(y_rad)) {}
    
    virtual Vec3f Point(float t) const override;
    virtual Vec3f Derivative(float t) const override;

    float RadiusX() const { return m_radX; }
    float RadiusY() const { return m_radY; }

    void SetRadiusX(float x_rad) { m_radX = std::abs(x_rad); }
    void SetRadiusY(float y_rad) { m_radY = std::abs(y_rad); }
    void SetRadius(float x_rad, float y_rad) { m_radX = std::abs(x_rad); m_radY = std::abs(y_rad); }

    bool operator==(const Ellipse& other) const 
    { 
        return  m_radX == other.m_radX && 
                m_radY == other.m_radY; 
    }

protected:
    float m_radX{1.f};
    float m_radY{1.f};
};