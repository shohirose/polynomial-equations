#include "quadratic_equation.hpp"
#include <gtest/gtest.h>

TEST(QuadraticEquationTest, DiscriminantTest) {
  using equation_t = shirose::quadratic_equation<double>;
  using shirose::calc_discriminant;

  // \f[ x^2 - 2x + 1 = 0 \f]
  {
      const equation_t eq{1, -2, 1};
      const auto d = calc_discriminant(eq);
      EXPECT_NEAR(d, 0.0, 1e-10);
  }

  // \f[ x^2 - 3x + 2 = 0 \f]
  {
      const equation_t eq{1, -3, 2};
      const auto d = calc_discriminant(eq);
      EXPECT_NEAR(d, 1.0, 1e-10);
  }

  // \f[ x^2 + x + 1 = 0 \f]
  {
      const equation_t eq{1, 1, 1};
      const auto d = calc_discriminant(eq);
      EXPECT_NEAR(d, -3.0, 1e-10);
  }
}

TEST(QuadraticEquationTest, RootsTest) {
  using equation_t = shirose::quadratic_equation<double>;
  using shirose::calc_roots;

  // Only one real root
  // \f[ x^2 - 2x + 1 = 0 \f]
  {
    const equation_t eq{1, -2, 1};
    const auto x = calc_roots(eq);

    EXPECT_NEAR(x[0].imag(), 0.0, 1e-10);
    EXPECT_NEAR(x[1].imag(), 0.0, 1e-10);

    EXPECT_NEAR(x[0].real(), 1.0, 1e-10);
    EXPECT_NEAR(x[1].real(), 1.0, 1e-10);
  }

  // Two real roots
  // \f[ x^2 - 3x + 2 = 0 \f]
  {
    const equation_t eq{1, -3, 2};
    const auto x = calc_roots(eq);

    EXPECT_NEAR(x[0].imag(), 0.0, 1e-10);
    EXPECT_NEAR(x[1].imag(), 0.0, 1e-10);

    EXPECT_NEAR(x[0].real(), 2.0, 1e-10);
    EXPECT_NEAR(x[1].real(), 1.0, 1e-10);
  }

  // Two complex roots
  // \f[ x^2 + x + 1 = 0 \f]
  {
    const equation_t eq{1, 1, 1};
    const auto x = calc_roots(eq);

    EXPECT_NEAR(x[0].imag(), std::sqrt(3.0) / 2, 1e-10);
    EXPECT_NEAR(x[1].imag(), -std::sqrt(3.0) / 2, 1e-10);

    EXPECT_NEAR(x[0].real(), -0.5, 1e-10);
    EXPECT_NEAR(x[1].real(), -0.5, 1e-10);
  }
}
