#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Line {
  lld a, b; llf s = 0;
  llf inter(Line l) { return (llf)(l.b - b) / (a - l.a); }
};
deque<Line> lines;

void add(Line l) {
  while (!lines.empty()) {
    l.s = l.inter(lines.back());
    if (lines.back().s < l.s) break;
    lines.pop_back();
  }
  lines.push_back(l);
}

lld get(lld x) {
  while (lines.size() > 1 && next(lines.begin())->s < x) lines.pop_front();
  Line l = lines.front();
  return l.a * x + l.b;
}

const int MN = 1010101;
lld N, a, b, c, x[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> a >> b >> c;
  for (int i=1; i<=N; i++) { cin >> x[i]; x[i] += x[i-1]; }

  D[0] = 0;
  add({0, 0});
  for (int i=1; i<=N; i++) {
    D[i] = get(x[i]) + a*x[i]*x[i] + b*x[i] + c;
    add({-2*a*x[i], D[i] + a*x[i]*x[i] - b*x[i]});
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
