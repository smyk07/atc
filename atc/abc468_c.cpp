/*
 * https://atcoder.jp/contests/abc467/tasks/abc468_c
 */

#include <array>
#include <cinttypes>
#include <cstdint>
#include <cstdio>

using u8 = std::uint8_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

#define LIMIT 10

constexpr std::array<u32, 11> fs{1,   1,    2,     6,      24,     120,
                                 720, 5040, 40320, 362880, 3628800};

u8 n;

std::array<u8, LIMIT> ps;
std::array<u8, LIMIT> qs;

u64 trp, trq;
u64 rp{0}, rq{0};

u64 res{0};

int main() {
  std::scanf("%" SCNu8, &n);

  for (u8 i = 0; i < n; i++)
    std::scanf("%" SCNu8, &ps[i]);

  for (u8 i = 0; i < n; i++)
    std::scanf("%" SCNu8, &qs[i]);

  for (u8 i = 0; i < n; i++) {
    trp = 0, trq = 0;

    for (u8 j = i + 1; j < n; j++) {
      if (ps[i] > ps[j])
        trp++;
      if (qs[i] > qs[j])
        trq++;
    }

    rp += trp * fs[n - 1 - i];
    rq += trq * fs[n - 1 - i];
  }

  if (rq > rp) {
    res = rq - rp - 1;
  }

  std::printf("%" PRIu64, res);

  return 0;
}
