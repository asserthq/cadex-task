#include "Helix.h"

Vec3f Helix::Point(float t) const
{
    return Vec3f{ 
        m_rad * std::cos(t), 
        m_rad * std::sin(t), 
        m_step * t
    };
}

Vec3f Helix::Derivative(float t) const
{
    return Vec3f{ 
        -m_rad * std::sin(t), 
        m_rad * std::cos(t), 
        m_step
    };
}