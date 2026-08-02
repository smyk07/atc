/*
 * You are given N strings S1, S2, ... , SN consisting of lowercase English
 * letters.
 *
 * Define N digits C1, C2, ... , CN as follows:
 *
 * If the first character of Si is one of a, b, c, then Ci = 2
 * If the first character of Si is one of d, e, f, then Ci = 3
 * If the first character of Si is one of g, h, i, then Ci = 4
 * If the first character of Si is one of j, k, l, then Ci = 5
 * If the first character of Si is one of m, n, o, then Ci = 6
 * If the first character of Si is one of p, q, r, s, then Ci = 7
 * If the first character of Si is one of t, u, v, then Ci = 8
 * If the first character of Si is one of w, x, y, z, then Ci = 9
 *
 * Output the string obtained by concatenating C1, C2, ... , CN in this
 * order.
 *
 * 1 <= N <= 10
 * N is an integer.
 * Si is a string of length between 1 and 10, inclusive, consisting of lowercase
 * English letters.
 */

#include <iostream>
#include <print>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;

  std::cin >> n;

  char c;
  std::string res;

  while (n-- != 0 && std::cin >> c) {
    switch (c) {
    case 'a':
    case 'b':
    case 'c':
      res.push_back('2');
      break;
    case 'd':
    case 'e':
    case 'f':
      res.push_back('3');
      break;
    case 'g':
    case 'h':
    case 'i':
      res.push_back('4');
      break;
    case 'j':
    case 'k':
    case 'l':
      res.push_back('5');
      break;
    case 'm':
    case 'n':
    case 'o':
      res.push_back('6');
      break;
    case 'p':
    case 'q':
    case 'r':
    case 's':
      res.push_back('7');
      break;
    case 't':
    case 'u':
    case 'v':
      res.push_back('8');
      break;
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      res.push_back('9');
      break;
    }

  loop:
    char nc = std::cin.peek();
    if (nc == '\n' || nc == ' ')
      goto next;
    std::cin.get();
    goto loop;
  next:
  }

  std::println("{}", res);

  return 0;
}
