#include "Circle.h"
#include <sstream>

Vec3f Circle::Point(float t) const
{
    return Vec3f{ 
        m_rad * std::cos(t), 
        m_rad * std::sin(t), 
        0.f 
    };
}

Vec3f Circle::Derivative(float t) const
{
    return Vec3f{ 
        -m_rad * std::sin(t), 
        m_rad * std::cos(t), 
        0.f 
    };
}

std::string Circle::ToString() const
{
    std::stringstream ss;
    ss << "Circle (rad = " << m_rad << ")";
    return ss.str(); 
}