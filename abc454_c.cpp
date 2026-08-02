/*
 * https://atcoder.jp/contests/abc454/tasks/abc454_c
 */

#include <cstdio>
#include <unordered_map>

int n, m;
int item;

std::unordered_map<int, bool> imap;

int items = 1;

int main(void) {
  scanf("%d %d", &n, &m);

  for (; m > 0; m--) {
    scanf("%d", &item);
    scanf("%d", &item);
    if (!imap[item]) {
      imap[item] = true;
      items++;
    }
  }

  printf("%d", items);

  return 0;
}
