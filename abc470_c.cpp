/*
 * https://atcoder.jp/contests/abc467/tasks/abc470_c
 */

#include <array>
#include <cstdint>
#include <cstdio>
#include <vector>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u32 = std::uint32_t;
using u64 = std::uint64_t;

constexpr u64 LIMIT = 500000;

u64 n, q;
std::array<u32, LIMIT> as{};
std::vector<u32> acs;

u32 qi, x, xora;

int main() {
  std::scanf("%ld %ld", &n, &q);

  while (q-- > 0) {
    std::scanf("%d", &qi);

    if (qi == 1) {
      std::scanf("%d", &x);
      auto id = x - 1;

      if (as[id] == 0) {
        acs.push_back(id);
      }

      xora ^= as[id];
      as[id]++;
      xora ^= as[id];
    } else {
      u64 ns{0};

      for (u64 i = 0; i < acs.size(); i++) {
        auto id = acs[i];

        xora ^= as[id];
        as[id]--;
        xora ^= as[id];

        if (as[id] > 0) {
          acs[ns++] = id;
        }
      }

      acs.resize(ns);
    }

    std::printf("%d\n", xora);
  }

  return 0;
}
