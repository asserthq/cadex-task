#include <gtest/gtest.h>
#include "../src/Vec3.h"
#include "../src/ICurve.h"
#include "../src/Circle.h"

TEST(Vec3_Test, CopyMoveConstructTest) {
    Vec3<float> vf{ 1.f, -5.f, 0.f };
    auto copy = vf;
    ASSERT_EQ(vf, copy);
    auto move = std::move(copy);
    ASSERT_EQ(vf, move);
}

TEST(Vec3_Test, ComparasionTest) {
    Vec3<float> vf{ 1.f, -5.f, 0.f };
    ASSERT_TRUE(Vec3f(1.f, -5.f, 0.f) == vf);
    ASSERT_TRUE(Vec3f() != vf);

    Vec3<double> vd{ 1.0, -5.0, 0.0 };
    ASSERT_TRUE(Vec3d(1.0, -5.0, 0.0) == vd);
    ASSERT_TRUE(Vec3d() != vd);
}

TEST(CurvesTest, CircleTest) {
    Circle c(4.f);
    ASSERT_EQ(c.Radius(), 4.f);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}