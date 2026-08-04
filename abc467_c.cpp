/*
 * https://atcoder.jp/contests/abc467/tasks/abc467_c
 */

#include <array>
#include <cstdint>
#include <cstdio>

using ll = long long;

ll n;

std::array<std::uint8_t, 200000> as, bs;

std::uint8_t tp{0};

ll evendiff{0};

int main() {
  std::scanf("%lld %*lld", &n); // ignoring m since its just 2

  for (ll i = 0; i < n; i++)
    std::scanf("%hhu", &as[i]);

  for (ll i = 0; i < n - 1; i++)
    std::scanf("%hhu", &bs[i]);

  // (T_i-1 + T_i) \bmod 2 = B_i-1
  // T_i = (B_i−1 + T_i−1) \bmod 2
  // T_i = B_i-1 \oplus T_i-1           <- modulo can become XOR wow TIL

  for (ll i = 0; i < n; i++) {
    if ((as[i] % 2) != tp)
      evendiff++;

    if (i < n - 1)
      tp = bs[i] ^ tp;
  }

  std::printf("%lld", std::min(evendiff, n - evendiff));

  return 0;
}
