#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Vec3.h"
#include "Circle.h"

#include <numbers>
#include <cmath>

auto pi = std::numbers::pi_v<float>;

auto Vec3f_Near(const Vec3f& expected, float max_abs_error)
{
    using namespace testing;
    return AllOf(Field(&Vec3f::x, FloatNear(expected.x, max_abs_error)),
                 Field(&Vec3f::y, FloatNear(expected.y, max_abs_error)),
                 Field(&Vec3f::z, FloatNear(expected.z, max_abs_error)));
}

TEST(HelperTest, Vec3f_Near_MatcherTest) 
{
    Vec3f calc_v(
        std::cos(pi), 
        std::cos(-pi/4), 
        std::tan(pi/6)
    );
    ASSERT_THAT(calc_v, Vec3f_Near(
        Vec3f(
            -1.f, 
            std::sqrt(2)/2, 
            1/std::sqrt(3)
        ),
        0.001f
    ));
}

TEST(Vec3_Test, ComparasionTest) 
{
    Vec3<float> vf{ 1.f, -5.f, 0.f };
    ASSERT_TRUE(Vec3f(1.f, -5.f, 0.f) == vf);
    ASSERT_TRUE(Vec3f() != vf);

    Vec3<double> vd{ 1.0, -5.0, 0.0 };
    ASSERT_TRUE(Vec3d(1.0, -5.0, 0.0) == vd);
    ASSERT_TRUE(Vec3d() != vd);
}

TEST(Vec3_Test, DefConstructorTest) 
{
    Vec3f v;
    ASSERT_EQ(v, Vec3f(0.f, 0.f, 0.f));
}

TEST(Vec3_Test, CopyTest) 
{
    Vec3f v(1.f, -5.f, 0.f);
    auto cv = v;
    ASSERT_EQ(v, cv);

    Vec3f v2(2.f, 2.f, 2.f);
    v2 = v;
    ASSERT_EQ(v, v2);
}

TEST(CircleTest, BasicTest)
{
    Circle c1(100.f);
    auto c2 = Circle(-100.f);
    auto x = c1 == c2;

    ASSERT_EQ(c1.Radius(), 100.f);
    ASSERT_TRUE(c1 == c2);
    ASSERT_EQ(c1, c2);

    c2 = Circle(30.f);
    ASSERT_TRUE(c1 != c2);
    c2.SetRadius(200.f);
    ASSERT_EQ(c2.Radius(), 200.f);
} 

TEST(CircleTest, PointTest) 
{
    float rad = 100.f;
    Circle c(rad);
    ASSERT_EQ(c.Radius(), 100.f);

    ASSERT_THAT(
        c.Point(0.f), 
        Vec3f_Near( 
            Vec3f(
                rad, 
                0.f, 
                0.f
            ), 
            0.001f
        )
    );
    
    ASSERT_THAT(
        c.Point(pi * 2.f), 
        Vec3f_Near( 
            c.Point(0.f), 
            0.001f
        )
    );

    ASSERT_THAT(
        c.Point(pi), 
        Vec3f_Near( 
            Vec3f(
                -rad, 
                0.f, 
                0.f
            ), 
            0.001f
        )
    );

    ASSERT_THAT(
        c.Point(-pi / 2.f), 
        Vec3f_Near( 
            Vec3f(
                0.f, 
                -rad, 
                0.f
            ), 
            0.001f
        )
    );

    ASSERT_THAT(
        c.Point((4.f*pi) + (4.f*pi / 3.f)), 
        Vec3f_Near( 
            Vec3f(
                rad * (-0.5f), 
                rad * (-std::sqrt(3)/2.f), 
                0.f
            ), 
            0.001f
        )
    );
}

TEST(CircleTest, DerivativeTest)
{
    float rad = 100.f;
    Circle c(rad);

    ASSERT_THAT(
        c.Derivative(0.f), 
        Vec3f_Near( 
            Vec3f(
                0.f, 
                rad, 
                0.f
            ), 
            0.001f
        )
    );
    
    ASSERT_THAT(
        c.Derivative(pi*20.f), 
        Vec3f_Near( 
            c.Derivative(0.f),
            0.001f
        )
    );

    ASSERT_THAT(
        c.Derivative(-pi/4.f - pi*100.f), 
        Vec3f_Near( 
            Vec3f(
                rad * (std::sqrt(2)/2), 
                rad * (std::sqrt(2)/2), 
                0.f
            ),
            0.001f
        )
    );
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}