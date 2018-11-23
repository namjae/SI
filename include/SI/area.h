#pragma once
#include "value_holder.h"

namespace SI
{
template <class _Ratio = std::ratio<1>, typename _Type = long long int>
struct area_t : public value_holder_t<_Ratio, _Type, 2>
{
  using value_holder_t<_Ratio, _Type, 2>::value_holder_t;
};
} // namespace SI