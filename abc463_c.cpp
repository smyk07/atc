/*
 * https://atcoder.jp/contests/abc467/tasks/abc463_c
 */

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <utility>

using i32 = std::int32_t;
using u32 = std::uint32_t;

u32 n;

u32 h;
u32 l;

// <height, time until leave>
using taka = std::pair<u32, u32>;
std::array<taka, 300000> takas{};

// idx = some time t
// val = max height at t
std::array<u32, 300000> map;

u32 q;
u32 t;

int main() {
  std::scanf("%d", &n);

  for (u32 i = 0; i < n; i++) {
    std::scanf("%d %d", &h, &l);
    takas[i] = {h, l};
  }

  auto tb = takas.begin();
  auto te = std::next(takas.begin(), n - 1);

  map[n - 1] = te->first;

  for (i32 i = n - 2; i >= 0; i--) {
    map[i] = std::max(takas[i].first, map[i + 1]);
  }

  std::scanf("%d", &q);

  while (q-- > 0) {
    std::scanf("%d", &t);

    auto idx = std::distance(
        tb, std::ranges::lower_bound(tb, te, t + 1, {}, &taka::second));

    std::printf("%u\n", map[idx]);
  }

  return 0;
}
