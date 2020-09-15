#ifndef SHIROSE_CUBIC_EQUATION_HPP
#define SHIROSE_CUBIC_EQUATION_HPP

#include <array>
#include <complex>

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

/// @brief Depressed cubic equation of the form \f[ y^3 + \frac{p}{3} y +
/// \frac{q}{2} = 0 \f]
template <typename T>
struct depressed_cubic_equation {
  T p;
  T q;
};

template <typename T>
depressed_cubic_equation<T> make_depressed_cubic_equation(
    const cubic_equation<T>& eq) {
  const auto a0 = eq.b / eq.a;
  const auto a1 = eq.c / eq.a;
  const auto a2 = eq.d / eq.a;
  return {(3 * a1 - a0 * a0) / 9, (27 * a2 + a0 * (2 * a0 * a0 - 9 * a1)) / 54};
}

template <typename T>
T calc_discriminant(const depressed_cubic_equation<T>& eq) {
  const auto p = eq.p;
  const auto q = eq.q;
  return -p * p * p - q * q;
}

}  // namespace cubic_equation_impl

template <typename T>
T calc_discriminant(const cubic_equation<T>& eq) {
  return calc_discriminant(
      cubic_equation_impl::make_depressed_cubic_equation(eq));
}

template <typename T>
std::array<std::complex<T>, 3> calc_roots(const cubic_equation<T>& eq) {
  using std::complex;
  using std::pow;
  using std::sqrt;

  const auto deq = cubic_equation_impl::make_depressed_cubic_equation(eq);
  const auto d = calc_discriminant(deq);
  const auto s = sqrt(complex<T>(-d, 0));
  const auto q = deq.q;
  const auto u1 = pow(-q + s, 1.0 / 3.0);
  const auto u2 = pow(-q - s, 1.0 / 3.0);

  const auto sqrt3 = std::sqrt(3.0);
  // The primitive cube roots of unity
  const auto w1 = complex<T>{-0.5, sqrt3 / 2.0};
  const auto w2 = complex<T>{-0.5, -sqrt3 / 2.0};

  const auto a0 = eq.b / eq.a;
  // Roots calculated by using the Cardano's formula
  const auto x1 = u1 + u2 - a0 / 3;
  const auto x2 = w1 * u1 + w2 * u2 - a0 / 3;
  const auto x3 = w2 * u1 + w1 * u2 - a0 / 3;

  return {x1, x2, x3};
}

}  // namespace shirose

#endif  // SHIROSE_CUBIC_EQUATION_HPP