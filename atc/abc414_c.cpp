/*
 * https://atcoder.jp/contests/abc467/tasks/abc414_c
 */

#include "io.hpp"
#include "types.hpp"

#include <cmath>
#include <tuple>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT{2'000'000};

u64 a, n;

u64 nl{0};
u64 min_left{1}, max_left{9};
u64 p{0};

u64 res{0};

auto build_pali = [] [[gnu::always_inline]] (u64 left_half, u8 middle, u64 len,
                                             u8 base) -> u64 {
  u64 slots = len / 2;
  u64 res = left_half;

  if (len % 2 == 1) {
    res = res * base + middle;
  }

  u64 temp = left_half;
  for (u64 i = 0; i < slots; i++) {
    res = res * base + (temp % base);
    temp /= base;
  }

  return res;
};

auto is_base_a_pali = [] [[gnu::always_inline]] (u64 p, u64 a) -> bool {
  if (p < a)
    return true;

  u8 digits[64];
  u8 len = 0;

  while (p > 0) {
    digits[len++] = p % a;
    p /= a;
  }

  for (u8 i = 0; i < len / 2; i++) {
    if (digits[i] != digits[len - 1 - i]) {
      return false;
    }
  }

  return true;
};

i32 main() {
  std::tie(a, n) = io.read<u64, 2>();

  nl = std::log10(n) + 1;

  auto check_pali = [&] [[gnu::always_inline]] (u64 p) -> bool {
    if (p > n)
      return false;

    if (is_base_a_pali(p, a)) {
      res += p;
    }

    return true;
  };

  for (u8 middle = 1; middle <= 9; ++middle) {
    u64 p = build_pali(0, middle, 1, 10);

    if (!check_pali(p))
      goto give_up;
  }

  for (u64 len = 2;; ++len) {
    if (len % 2 == 0 && len > 2) {
      min_left *= 10;
      max_left = max_left * 10 + 9;
    }

    if (len % 2 == 0) {
      for (u64 left_half = min_left; left_half <= max_left; ++left_half) {
        u64 p = build_pali(left_half, 0, len, 10);

        if (!check_pali(p))
          goto give_up;
      }
    } else {
      for (u64 left_half = min_left; left_half <= max_left; ++left_half) {
        for (u8 middle = 0; middle <= 9; ++middle) {
          u64 p = build_pali(left_half, middle, len, 10);

          if (!check_pali(p))
            goto give_up;
        }
      }
    }
  }

give_up:

  io.write(res);

  return 0;
}
