/*
 * https://atcoder.jp/contests/abc458/tasks/abc458_c
 */

#include <cstdio>
#include <cstring>

typedef long long ll;

int main(void) {

  char s[500000];

  scanf("%s", s);
  int len = strlen(s);
  ll res = 0;

  for (int i = 0; i < len; i++) {
    if (s[i] == 'C') {
      res += (len - i) > (i + 1) ? (i + 1) : (len - i);
    }
  }

  printf("%lld", res);

  return 0;
}
