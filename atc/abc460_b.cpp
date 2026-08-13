/*
 * There are two circles C1 and C2 on the xy-plane. In this problem, a
 * circle refers to the circumference.
 *
 * Circle C1 has its center at (X1,Y1) and radius R1.
 * Circle C2 has its center at (X2,Y2) and radius R2.
 *
 * Determine whether circles C1 and C2 have a common point. In other
 * words, determine whether there exists at least one point whose distance from
 * (X1,Y1) is R1 and whose distance from (X2,Y2) is R2.
 *
 * You are given T test cases, solve each one.
 *
 * input:
 * T
 * case 1 (X1, Y1, R1, X2, Y2, R2)
 * ...
 * case t (X1, Y1, R1, X2, Y2, R2)
 *
 * output: yes/no
 */

#include <iostream>
#include <print>

int main(void) {
  long long t;

  long long x1, y1, r1;
  long long x2, y2, r2;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    long long dsq = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));

    long long rds = (r1 - r2) * (r1 - r2);
    long long rss = (r1 + r2) * (r1 + r2);

    if (dsq >= rds && dsq <= rss)
      std::println("Yes");
    else
      std::println("No");
  }

  return 0;
}
