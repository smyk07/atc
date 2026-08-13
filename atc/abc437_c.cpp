/*
 * https://atcoder.jp/contests/abc467/tasks/abc437_c
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"
#include <algorithm>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT = 300'000;

u64 t;
u64 n;
u64 w, p;

u64 ts{0};
clix::svec<u64, LIMIT> cs;
u64 sum{0};

u64 res{0};

i32 main() {
  io.read(&t);

  while (t-- > 0) {
    io.read(&n);

    while (n-- > 0) {
      std::tie(w, p) = io.read<u32, 2>();
      ts += p;
      cs.push_back(w + p);
    }

    std::sort(cs.begin(), cs.end());

    for (auto c : cs) {
      sum += c;

      if (sum > ts)
        break;

      res++;
    }

    io.write(res);
    io.newline();

    cs.clear();

    ts = 0;
    sum = 0;
    res = 0;
  }

  return 0;
}
