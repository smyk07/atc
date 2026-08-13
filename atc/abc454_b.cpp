/*
 * https://atcoder.jp/contests/abc454/tasks/abc454_b
 */

#include <cstdio>

int n, m;
int ncounter;

int cloth;
bool clothes[100];

bool rep_clothes = false;
bool has_duplicate = false;

int main(void) {
  scanf("%d %d", &n, &m);
  ncounter = n;

  for (int i = 0; i < n; i++) {
    scanf("%d", &cloth);
    if (clothes[cloth]) {
      has_duplicate = true;
    }
    clothes[cloth] = true;
  }

  if (has_duplicate || m < n)
    goto q1no;

  printf("Yes\n");
  goto q2;

q1no:
  printf("No\n");

q2:

  for (int i = 1; i <= m; i++) {
    if (!clothes[i]) {
      printf("No\n");
      goto exit;
    }
  }

  printf("Yes\n");

exit:
  return 0;
}
