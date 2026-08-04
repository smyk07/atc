/*
 * https://atcoder.jp/contests/abc467/tasks/abc463_c
 */

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <utility>

using u32 = std::uint32_t;
using u64 = std::uint64_t;

u32 n;

u64 h;
u64 l;
using taka = std::pair<u64, u64>; // <height, time until leave>
std::array<taka, 300000> takas{};

u32 q;
u32 t;

int main() {
  std::scanf("%d", &n);

  for (u32 i = 0; i < n; i++) {
    std::scanf("%ld %ld", &h, &l);
    takas[i] = {h, l};
  }

  auto tb = takas.begin();
  auto te = std::next(takas.begin(), n - 1);

  std::scanf("%d", &q);

  while (q-- > 0) {
    std::scanf("%d", &t);

    // iterator to first taka in room after T + 1/2 minutes
    auto tat_begin = std::ranges::lower_bound(tb, te, t + 1, {}, &taka::second);

    auto max_it = std::ranges::max_element(tat_begin, te, {}, &taka::first);

    std::printf("%ld\n", max_it->first);
  }

  return 0;
}
