#include "Circle.h"
#include <cmath>

Circle::PointTy Circle::Point(float t) const
{
    return { m_rad * cos(t), m_rad * sin(t), 0.f };
}

Circle::PointTy Circle::Derivative(float t) const
{
    return { -m_rad * sin(t), m_rad * cos(t), 0.f };
}