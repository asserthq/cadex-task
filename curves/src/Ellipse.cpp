#include "Ellipse.h"
#include <sstream>

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

std::string Ellipse::ToString() const
{
    std::stringstream ss;
    ss << "Ellipse (x_rad = " << m_radX << ", y_rad = " << m_radY << ")";
    return ss.str(); 
}