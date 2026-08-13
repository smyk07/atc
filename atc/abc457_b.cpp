/*
 * https://atcoder.jp/contests/abc457/tasks/abc457_b
 */

#include <iostream>
#include <vector>

typedef long long ll;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n;
  std::cin >> n;

  ll l;

  std::vector<std::vector<ll>> pv;
  pv.reserve(n);

  ll x, y;

  for (ll i = 0; i < n; i++) {
    std::cin >> l;

    std::vector<ll> cv(l);

    for (auto &a : cv) {
      std::cin >> a;
    }

    pv.push_back(std::move(cv));
  }

  std::cin >> x >> y;

  std::cout << pv[x - 1][y - 1];

  return 0;
}
