/*
 * https://atcoder.jp/contests/abc467/tasks/abc467_d
 */

#include <cstdio>

using ll = long long;
using i128 = __int128;

struct Point {
  ll x, y;

  Point() : x{0}, y{0} {};
  Point(ll x, ll y) : x{x}, y{y} {};
  Point(const Point &p) : x{p.x}, y{p.y} {};
};

struct Line {
  Point p1, p2;

  Line() : p1{}, p2{} {};
  Line(const Point &p1, const Point &p2) : p1{p1}, p2{p2} {};

  Line pb() const {
    ll dx = p2.x - p1.x;
    ll dy = p2.y - p1.y;

    Point mid_x2(p1.x + p2.x, p1.y + p2.y);
    Point perp_dir(-dy, dx);
    Point p2_bisector(mid_x2.x + perp_dir.x, mid_x2.y + perp_dir.y);

    return Line(mid_x2, p2_bisector);
  }
};

bool intersect(Line l1, Line l2) {
  i128 dx1 = l1.p2.x - l1.p1.x;
  i128 dy1 = l1.p2.y - l1.p1.y;

  i128 dx2 = l2.p2.x - l2.p1.x;
  i128 dy2 = l2.p2.y - l2.p1.y;

  i128 cp_dir = dx1 * dy2 - dy1 * dx2;

  if (cp_dir != 0)
    return true;

  i128 dx_point = l1.p1.x - l2.p1.x;
  i128 dy_point = l1.p1.y - l2.p1.y;

  i128 cp_collinear = dx_point * dy2 - dy_point * dx2;

  return cp_collinear == 0;
}

ll t;

ll px, py, qx, qy, rx, ry, sx, sy;
Point p, q, r, s;

Line rs_pb, qp_pb;

int main() {
  std::scanf("%lld", &t);

  while (t-- > 0) {
    std::scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &px, &py, &qx, &qy,
               &rx, &ry, &sx, &sy);

    p = {px, py};
    q = {qx, qy};
    r = {rx, ry};
    s = {sx, sy};

    rs_pb = Line{r, s}.pb();
    qp_pb = Line{q, p}.pb();

    if (intersect(rs_pb, qp_pb))
      std::printf("Yes\n");
    else
      std::printf("No\n");
  }

  return 0;
}
