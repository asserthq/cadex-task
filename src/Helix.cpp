#include "Helix.h"
#include <numbers>

constexpr auto pi = std::numbers::pi_v<float>;

Vec3f Helix::Point(float t) const
{
    return Vec3f{ 
        m_rad * std::cos(t), 
        m_rad * std::sin(t), 
        m_step * (t / (2 * pi))
    };
}

Vec3f Helix::Derivative(float t) const
{
    return Vec3f{ 
        -m_rad * std::sin(t), 
        m_rad * std::cos(t), 
        m_step / (2 * pi)
    };
}