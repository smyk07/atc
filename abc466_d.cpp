/*
 * https://atcoder.jp/contests/abc467/tasks/abc466_d
 */

#include <cstdio>
#include <vector>

using i64 = long long;

i64 n, m;

struct Grid {
private:
  i64 n;
  std::vector<i64> rows;
  std::vector<i64> cols;

public:
  i64 count{};

  Grid(i64 n) : n{n}, rows(n, -1), cols(n, -1) {};

  void insert(i64 r, i64 c) {
    if (r < 0 || r >= n || c < 0 || c >= n)
      return;

    rows[r] = c;
    cols[c] = r;
    count++;
  }

  void remove_row(i64 r) {
    if (r < 0 || r >= n)
      return;

    if (rows[r] != -1) {
      i64 c = rows[r];
      cols[c] = -1;
      rows[r] = -1;
      count--;
    }
  }

  void remove_col(i64 c) {
    if (c < 0 || c >= n)
      return;

    if (cols[c] != -1) {
      i64 r = cols[c];
      rows[r] = -1;
      cols[c] = -1;
      count--;
    }
  }

  void operate(i64 r, i64 c) {
    remove_row(r);
    remove_col(c);

    insert(r, c);
  }
};

i64 r, c;

int main() {
  std::scanf("%lld %lld", &n, &m);

  Grid g{n};

  while (m-- > 0) {
    std::scanf("%lld %lld", &r, &c);
    g.operate(r - 1, c - 1);
  }

  std::printf("%lld", g.count);

  return 0;
}
