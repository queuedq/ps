#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
lld N, K, r[MN], psum[MN], D[8][MN];

struct Line {
  lld a, b; llf s;
  llf inter(Line l) { return (llf)(l.b-b) / (a-l.a); }
  bool operator <(const Line &l) const { return s < l.s; }
};
vector<Line> lines;

void add_line(Line l) {
  while (!lines.empty()) {
    l.s = l.inter(lines.back());
    if (lines.back().s < l.s) break;
    lines.pop_back();
  }
  lines.push_back(l);
}

lld query(lld x) {
  auto l = upper_bound(lines.begin(), lines.end(), (Line){0, 0, (llf)x}) - 1;
  return l->a * x + l->b;
}

lld dp() {
  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + r[i];

  for (int k=1; k<=K-1; k++) {
    lines.clear();
    for (int i=1; i<=N; i++) {
      add_line({i-1, D[k-1][i-1] - (i-1)*psum[i-1]});
      D[k][i] = query(psum[i]);
    }
  }

  lld ans = 0;
  for (int i=1; i<=N; i++) ans += (i-1)*r[i];
  return ans - D[K-1][N];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> r[i];

  lld ans = LLONG_MAX;
  for (int i=0; i<N; i++) {
    ans = min(ans, dp());
    rotate(r+1, r+2, r+N+1);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
