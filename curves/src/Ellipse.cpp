#include "Ellipse.h"

Vec3f Ellipse::Point(float t) const 
{
    return Vec3f{ 
        m_radX * std::cos(t), 
        m_radY * std::sin(t), 
        0.f 
    };
}

Vec3f Ellipse::Derivative(float t) const
{
    return Vec3f{ 
        -m_radX * std::sin(t), 
        m_radY * std::cos(t), 
        0.f 
    };
}