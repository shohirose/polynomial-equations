#include "cubic_equation.hpp"

#include <gtest/gtest.h>

TEST(CubicEquationTest, RootsTest) {
  using equation_t = shirose::cubic_equation<double>;
  using shirose::calc_roots;

  // Only one real root
  {
    const equation_t eq{1.0, -3.0, 3.0, -1.0};
    const auto x = calc_roots(eq);

    EXPECT_DOUBLE_EQ(x[0].imag(), 0);
    EXPECT_DOUBLE_EQ(x[1].imag(), 0);
    EXPECT_DOUBLE_EQ(x[2].imag(), 0);

    EXPECT_NEAR(x[0].real(), 1.0, 1e-10);
    EXPECT_NEAR(x[1].real(), 1.0, 1e-10);
    EXPECT_NEAR(x[2].real(), 1.0, 1e-10);
  }

  // Three real roots
  {
    const equation_t eq{1.0, 0.0, -1.0, 0.0};
    const auto x = calc_roots(eq);

    EXPECT_DOUBLE_EQ(x[0].imag(), 0);
    EXPECT_DOUBLE_EQ(x[1].imag(), 0);
    EXPECT_DOUBLE_EQ(x[2].imag(), 0);

    EXPECT_NEAR(x[0].real(), 1.0, 1e-10);
    EXPECT_NEAR(x[1].real(), -1.0, 1e-10);
    EXPECT_NEAR(x[2].real(), 0.0, 1e-10);
  }

  // Two real roots
  {
    const equation_t eq{1.0, -2.0, 1.0, 0.0};
    const auto x = calc_roots(eq);

    EXPECT_DOUBLE_EQ(x[0].imag(), 0);
    EXPECT_DOUBLE_EQ(x[1].imag(), 0);
    EXPECT_DOUBLE_EQ(x[2].imag(), 0);

    EXPECT_NEAR(x[0].real(), 1.0, 1e-10);
    EXPECT_NEAR(x[1].real(), 0.0, 1e-10);
    EXPECT_NEAR(x[2].real(), 1.0, 1e-10);
  }

  /*
  // TODO: Fix cubic_equation to pass this test.
  // One real root and two complex roots
  {
    const equation_t eq{1.0, 0.0, 0.0, -1.0};
    const auto x = calc_roots(eq);

    EXPECT_NEAR(x[0].imag(), 0, 1e-10);
    EXPECT_NEAR(x[1].imag(), 0.8660254037, 1e-10);
    EXPECT_NEAR(x[2].imag(), -0.8660254037, 1e-10);

    EXPECT_NEAR(x[0].real(), 1.0, 1e-10);
    EXPECT_NEAR(x[1].real(), -0.5, 1e-10);
    EXPECT_NEAR(x[2].real(), -0.5, 1e-10);
  }
  */
}