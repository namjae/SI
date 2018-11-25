#pragma once

#include <limits>
#include <ratio>
#include <stdexcept>

namespace SI::detail {
template <template <class, typename> class U, typename _Ratio>
constexpr auto
generate_unit_type_overflow_check(const unsigned long long int magnitude) {
  if (magnitude >
      std::numeric_limits<
          typename U<_Ratio, long long int>::internal_type>::max()) {
    throw std::overflow_error("supplied value too large");
  }
  return U<_Ratio, long long int>(magnitude);
}

/// @returns the ratio between two value holders
template <
    typename _lhs, typename _rhs,
    typename std::enable_if<_lhs::ratio::num == 1 || _lhs::ratio::den == 1,
                            _lhs>::type * = nullptr>
static constexpr auto ratio_to() {
  typedef std::ratio_divide<_rhs, _lhs> resulting_ratio;
  return resulting_ratio{};
}

template <typename _Tp> struct is_ratio : std::false_type {};

template <intmax_t _Num, intmax_t _Den>
struct is_ratio<std::ratio<_Num, _Den>> : std::true_type {};

} // namespace SI::detail