#include "template.h"

using llf = long double;

// decreasing slope, min query -> left intersection, left to right
struct Line {
  lld a, b; llf s = 0;
  llf intersection(Line l) { return (llf)(l.b - b) / (a - l.a); }
  bool operator <(const Line l) const { return s < l.s; }
};

struct CHT {
  vector<Line> lines;

  void add(Line l) {
    while (lines.size() > 0) {
      l.s = l.intersection(lines.back());
      if (lines.back().s < l.s) break; // left to right
      lines.pop_back();
    }
    lines.push_back(l);
  }

  lld query(lld x) {
    // left to right
    auto l = lower_bound(lines.begin(), lines.end(), (Line){0, 0, (llf)x});
    l--;
    return l->a * x + l->b;
  }

  void debug() {
    printf("======== CHT ========\n");
    for (Line l: lines) printf("(%lld)x + (%lld) / s = %Lf\n", l.a, l.b, l.s);
    printf("=====================\n");
  }
};
