/*
 * You are given positive integers N and M.
 *
 * If the following operation is repeated while the value of M is not 0, find
 * the number of operations performed.
 *
 * Let x be the remainder when N is divided by M. Replace the value of M with x.
 *
 * It can be proved that M becomes 0 after a finite number of operations.
 *
 * Output number of iterations
 */

#include <iostream>
#include <print>

int main(void) {
  int n;
  int m;
  int x;
  int ans = 0;

  std::cin >> n;
  std::cin >> m;

  while (m != 0) {
    x = n % m;
    m = x;
    ans++;
  }

  std::print("{}", ans);

  return 0;
}
