/*
 * Clix's Fenwick Tree
 *    AKA Binary Indexed Tree
 */

#include "svec.hpp"
#include "types.hpp"

#include <cstddef>

namespace clix {

template <std::size_t N> struct ftree {
private:
  clix::svec<u64, N> bit_{};

public:
  constexpr ftree() = default;

  template <typename T, std::size_t ArrSize>
  constexpr explicit ftree(const clix::svec<T, ArrSize> &arr) {
    build(arr);
  }

  template <typename T, std::size_t ArrSize>
  constexpr void build(const clix::svec<T, ArrSize> &arr) {
    static_assert(ArrSize < N, "clix::ftree: Input array size exceeds ftree "
                               "capacity");

    bit_.clear();

    for (std::size_t i = 0; i < ArrSize; i++) {
      bit_[i + 1] = arr[i];
    }

    for (std::size_t i = ArrSize + 1; i < N; i++)
      bit_[i] = 0;

    for (u64 i = 1; i < N; ++i) {
      u64 parent = i + (i & -i);

      if (parent < N) [[likely]] {
        bit_[parent] += bit_[i];
      }
    }
  }

  constexpr void update(u64 x, u64 delta) {
    x++;

    while (x < N) {
      bit_[x] += delta;
      x += (x & -x);
    }
  }

  [[nodiscard]]
  constexpr u64 query(u64 x) const {
    x++;

    u64 res{0};

    while (x > 0) {
      res += bit_[x];
      x -= (x & -x);
    }

    return res;
  }

  [[nodiscard]]
  constexpr u64 range_query(u64 l, u64 r) const {
    return query(r) - query(l - 1);
  }

  constexpr void clear() { bit_.clear(); }
};

} // namespace clix
