/*
 * https://atcoder.jp/contests/abc467/tasks/abc446_c
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#include <numeric>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

i32 main() {
  constexpr u64 LIMIT = 200000;

  auto t = in.read<u32>();

  clix::svec<u32, LIMIT> as; // bought
  clix::svec<u32, LIMIT> bs; // used

  clix::svec<u32, LIMIT> q;

  while (t-- > 0) {
    auto [n, d] = in.read<u32, u32>();

    in.read(as, n);
    in.read(bs, n);

    auto qf = q.begin();
    auto qb = q.begin();

    for (u32 i = 0; i < n; i++) {
      *(qb++) = as[i];

      while (bs[i] > 0 && qf < qb) {
        if (bs[i] >= *qf)
          bs[i] -= *qf, qf++;
        else
          *qf -= bs[i], bs[i] = 0;
      }

      while (qf < qb) {
        u32 pd = static_cast<u32>(qf - q.begin());

        if (pd + d <= i)
          qf++;
        else
          break;
      }
    }

    u64 res = std::accumulate(qf, qb, 0);
    out.write(res);
    out.newline();
  }

  return 0;
}
