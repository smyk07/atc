/*
 * https://atcoder.jp/contests/abc457/tasks/abc457_a
 */

#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;
  std::cin >> n;

  long long a;
  std::vector<long long> v(n);

  for (auto &x : v) {
    std::cin >> x;
  }

  long long x;
  std::cin >> x;

  std::cout << v[x - 1];

  return 0;
}
