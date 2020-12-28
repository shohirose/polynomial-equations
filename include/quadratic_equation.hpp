#ifndef SHIROSE_QUADRATIC_EQUATION_HPP
#define SHIROSE_QUADRATIC_EQUATION_HPP

#include <array>
#include <cmath>
#include <complex>

namespace shirose {

/// @brief Quadratic equation of the form \f[ ax^2 + bx + c \f]
template <typename T>
struct quadratic_equation {
  T a;
  T b;
  T c;
};

template <typename T>
inline T square(T x) {
  return x * x;
}

template <typename T>
T calc_discriminant(const quadratic_equation<T>& eq) {
  return square(eq.b) - 4 * eq.a * eq.c;
}

template <typename T>
std::array<std::complex<T>, 2> calc_roots(const quadratic_equation<T>& eq) {
  const auto d = calc_discriminant(eq);
  using std::complex;
  using std::sqrt;
  const auto s = sqrt(complex<T>(d, 0));
  std::array<std::complex<T>, 2> x;
  x[0] = (-eq.b + s) / (2.0 * eq.a);
  x[1] = (-eq.b - s) / (2.0 * eq.a);
  return x;
}

}  // namespace shirose

#endif  // SHIROSE_QUADRATIC_EQUATION_HPP