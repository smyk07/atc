/*
 * https://atcoder.jp/contests/abc467/tasks/abc444_c
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#include <algorithm>
#include <iterator>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT = 300000;

u32 n;
clix::svec<u64, LIMIT> as{};

clix::svec<u64, LIMIT> ls{};

auto check_and_push = [] [[gnu::always_inline]] (u64 * ab, u64 *ae,
                                                 u64 candidate) {
  auto size = std::distance(ab, ae);

  if (size % 2 == 0) {
    for (auto i = ab, j = ae - 1; i < j; i++, j--) {
      if (*i + *j != candidate)
        return;
    }

    ls.push_back(candidate);
  }
};

i32 main() {
  io.read(n);
  io.read(as, n);

  auto ab = as.begin(), ae = as.end();
  std::sort(ab, ae);

  auto max = *(ae - 1);
  auto tae = std::remove(ab, ae, max);

  check_and_push(ab, tae, max);

  check_and_push(ab, ae, (*ab + *(ae - 1)));

  for (auto l : ls) {
    io.write(l);
    io.space();
  }

  return 0;
}
