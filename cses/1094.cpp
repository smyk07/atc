/*
 * https://cses.fi/problemset/task/1094
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT = 200'000;

u64 n;
clix::svec<u64, LIMIT> as{};

u64 res{0};

i32 main() {
  io.read(&n);
  io.read(as, n);

  for (u32 i = 1; i < as.size(); i++)
    if (as[i] < as[i - 1]) {
      res += as[i - 1] - as[i];
      as[i] += as[i - 1] - as[i];
    }

  io.write(res);

  return 0;
}
