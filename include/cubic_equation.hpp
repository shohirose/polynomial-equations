#ifndef SHIROSE_CUBIC_EQUATION_HPP
#define SHIROSE_CUBIC_EQUATION_HPP

#include <array>
#include <complex>
#include <iostream>
#include <cmath>

namespace shirose {

/// @brief Cubic equation of the form \f[ ax^3 + bx^2 + cx + d \f]
template <typename T>
struct cubic_equation {
  T a;
  T b;
  T c;
  T d;
};

namespace cubic_equation_impl {

/// @brief Depressed cubic equation of the form \f[ y^3 + py + q \f]
template <typename T>
struct depressed_cubic_equation {
  T p;
  T q;
};

template <typename T>
depressed_cubic_equation<T> make_depressed_cubic_equation(
    const cubic_equation<T>& eq) {
  const auto a = eq.a;
  const auto b = eq.b;
  const auto c = eq.c;
  const auto d = eq.d;
  return {(3 * a * c - b * b) / (3 * a * a),
          (27 * a * a * d + 2 * b * b * b - 9 * a * b * c) / (27 * a * a * a)};
}

template <typename T>
T calc_discriminant(const depressed_cubic_equation<T>& eq) {
  const auto p = eq.p;
  const auto q = eq.q;
  return -(4 * p * p * p + 27 * q * q);
}

}  // namespace cubic_equation_impl

template <typename T>
T calc_discriminant(const cubic_equation<T>& eq) {
  return calc_discriminant(
      cubic_equation_impl::make_depressed_cubic_equation(eq));
}

template <typename T>
int number_of_real_roots(const cubic_equation<T>& eq) {
  constexpr double tolerance = 1e-10;
  using std::fabs;
  const auto deq = cubic_equation_impl::make_depressed_cubic_equation(eq);
  const auto d = calc_discriminant(deq);
  if (d > 0) {
    return 3;
  } else if (d < 0) {
    return 0;
  } else {
    if (fabs(deq.p) < tolerance) {
      return 1;
    } else {
      return 2;
    }
  }
}

template <typename T>
std::array<std::complex<T>, 3> calc_roots(const cubic_equation<T>& eq) {
  using std::abs;
  using std::complex;
  using std::pow;
  using std::sqrt;
  constexpr double tolerance = 1e-10;

  const auto deq = cubic_equation_impl::make_depressed_cubic_equation(eq);
  const auto d = calc_discriminant(deq) / 108;
  const auto q = deq.q;

  // d is effectively zero.
  // There exists one real root.
  if (abs(d / q) < tolerance) {
    const auto u1 = pow(-0.5*q, 1.0/3.0);
  }
  // There exists three complex roots.
  else {
  }
  const auto s = sqrt(complex<T>(d, 0));
  std::cerr << "s = " << s << '\n';

  const auto u1 = pow(-0.5 * q + s, 1.0 / 3.0);
  const auto v1 = pow(-0.5 * q - s, 1.0 / 3.0);

  const auto sqrt3 = std::sqrt(3.0);
  // The primitive cube roots of unity
  const auto w1 = complex<T>{-0.5, sqrt3 / 2.0};
  const auto w2 = w1 * w1;

  const auto t = eq.b / (3 * eq.a);
  // Roots calculated by using the Cardano's formula
  const auto x1 = u1 + v1 - t;
  const auto x2 = u1 * w1 + v1 * w2 - t;
  const auto x3 = u1 * w2 + v1 * w1 - t;

  return {x1, x2, x3};
}

}  // namespace shirose

#endif  // SHIROSE_CUBIC_EQUATION_HPP