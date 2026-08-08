/*
 * https://atcoder.jp/contests/abc467/tasks/abc470_c
 */

#include "io.hpp"
#include "svec.hpp"

#include <cstdint>
#include <cstdio>
#include <vector>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u32 = std::uint32_t;
using u64 = std::uint64_t;

constexpr u64 LIMIT = 500000;

clix::svec<u32, LIMIT> as{};
std::vector<u32> acs;

u32 qi, x, xora;

int main() {
  auto [n, q] = io.read<u64, 2>();

  while (q-- > 0) {
    io.read(&qi);

    if (qi == 1) {
      io.read(&x);
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
