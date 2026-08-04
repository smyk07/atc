/*
 * https://atcoder.jp/contests/abc467/tasks/abc467_b
 */

#include <array>
#include <cstdio>

using ll = long long;

ll t;
ll a, b;

std::array<char, 5> s = {'l', 'a', 'r', 'p', '\0'};

ll x = 10000;
ll y = 10000;
ll res;

int main() {
  std::scanf("%lld", &t);

  for (ll i = 0; i < t; i++) {
    std::scanf("%lld %lld %4s", &a, &b, s.data());

    if (s[0] == 'k') {
      x -= b;
    } else {
      x -= b - (b - a);
    }

    y -= b - (b - a);
  }

  res = y - x;

  std::printf("%lld", res);

  return 0;
}
