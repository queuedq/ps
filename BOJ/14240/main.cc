#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 2e5+5, MAXSUM = MAXN * 1e7;
lld N, A[MAXN], sum[MAXN], score[MAXN];

// decreasing slope, max query -> right intersection, right to left
struct Line {
  lld a, b; llf s = MAXSUM;
  llf intersection(Line l) { return (llf)(l.b - b) / (a - l.a); }
  bool operator <(const Line l) const { return s < l.s; }
};

struct CHT {
  vector<Line> lines;

  void add(Line l) {
    while (lines.size() > 0) {
      l.s = l.intersection(lines.back());
      if (l.s < lines.back().s) break; // right to left
      lines.pop_back();
    }
    lines.push_back(l);
  }

  lld query(lld x) {
    // right to left
    auto l = lower_bound(lines.rbegin(), lines.rend(), (Line){0, 0, (llf)x});
    return l->a * x + l->b;
  }

  void debug() {
    printf("======== CHT ========\n");
    for (Line l: lines) printf("(%lld)x + (%lld) / s = %Lf\n", l.a, l.b, l.s);
    printf("=====================\n");
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    sum[i] = sum[i-1] + A[i];
    score[i] = score[i-1] + A[i]*i;
  }

  CHT cht;
  lld maxScore = 0;

  for (int i=1; i<=N; i++) {
    cht.add({-(i-1), sum[i-1]*(i-1) - score[i-1]});
    maxScore = max(maxScore, score[i] + cht.query(sum[i]));
  }

  cout << maxScore << endl;

  ////////////////////////////////
  return 0;
}
