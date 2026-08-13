/*
 * You are given an integer X between 1 and 10, inclusive.
 *
 * Output the string obtained by deleting only the X-th character from the
 * string HelloWorld.
 */

#include <iostream>
#include <print>

int main(void) {
  int x;
  std::cin >> x;

  std::string s{"HelloWorld"};
  s.erase(x - 1, 1);

  std::print("{}", s);

  return 0;
}
