/*
 * https://atcoder.jp/contests/abc467/tasks/abc470_d
 */

#include "io.hpp"
#include "svec.hpp"

#include <cstdint>
#include <cstdio>
#include <utility>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u32 = std::uint32_t;

constexpr u32 LIMIT = 500000;

u32 qi, x, y;
u32 f, g;
clix::svec<u32, LIMIT + 1> p;
clix::svec<u32, LIMIT + 1> pi;

auto *pref = p.data();
auto *piref = pi.data();

int main() {
  auto [n, q] = io.read<u32, 2>();

  io.read(p, n);

  for (u32 i = 0; i < n; i++) {
    pi[p[i] - 1] = i + 1;
  }

  while (q-- > 0) {
    io.read(&qi);

    if (qi == 1) {
      auto [x, y] = io.read<u32, 2>();
      x--;
      y--;

      f = pref[x];
      g = pref[y];

      std::swap(pref[x], pref[y]);

      piref[f - 1] = y + 1;
      piref[g - 1] = x + 1;
    } else {
      std::swap(pref, piref);
    }
  }

  for (auto i = 0; i < n; i++) {
    std::printf("%d ", pref[i]);
  }

  return 0;
}
