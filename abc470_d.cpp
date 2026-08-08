/*
 * https://atcoder.jp/contests/abc467/tasks/abc470_d
 */

#include <array>
#include <cstdint>
#include <cstdio>
#include <utility>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u32 = std::uint32_t;

constexpr u32 LIMIT = 500000;

u32 n, q;
u32 qi, x, y;
u32 f, g;
std::array<u32, LIMIT + 1> p;
std::array<u32, LIMIT + 1> pi;

auto *pref = p.data();
auto *piref = pi.data();

int main() {
  std::scanf("%d %d", &n, &q);

  for (u32 i = 1; i <= n; i++) {
    std::scanf("%d", &p[i]);
  }

  for (u32 i = 1; i <= n; i++) {
    pi[p[i]] = i;
  }

  while (q-- > 0) {
    std::scanf("%d", &qi);

    if (qi == 1) {
      std::scanf("%d %d", &x, &y);

      f = pref[x], g = pref[y];

      std::swap(pref[x], pref[y]);

      std::swap(piref[f], piref[g]);
    } else {
      std::swap(pref, piref);
    }
  }

  for (auto i = 1; i <= n; i++) {
    std::printf("%d ", pref[i]);
  }

  return 0;
}
