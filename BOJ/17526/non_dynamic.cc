#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Line {
  lld a, b; llf s = 0;
  llf inter(Line l) { return (llf)(l.b - b) / (a - l.a); }
  bool operator <(const Line &l) const { return s < l.s; }
};
vector<Line> lines;

void add(Line l) {
  while (!lines.empty()) {
    l.s = l.inter(lines.back());
    if (lines.back().s < l.s) break;
    lines.pop_back();
  }
  lines.push_back(l);
}

lld get(lld x) {
  auto l = upper_bound(lines.begin(), lines.end(), (Line){0, 0, (llf)x}) - 1;
  return l->a * x + l->b;
}

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, x[MN], p[MN], s[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) cin >> x[i];
  for (int i=N-2; i>=0; i--) x[i] += x[i+1];
  for (int i=0; i<N-1; i++) cin >> p[i] >> s[i];

  D[0] = 0;
  add({0, 0});
  for (int i=N-2; i>=0; i--) {
    D[i] = get(s[i]) + s[i]*x[i] + p[i];
    add({-x[i], D[i]});
  }

  cout << D[0] << endl;

  ////////////////////////////////
  return 0;
}
