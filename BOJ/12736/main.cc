#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 6e5+5;
lld N, M, P[MAXN], C[MAXN];

struct Slopes {
  lld y, s;
  priority_queue<lld> p;

  Slopes(): y(0), s(0) {}
  Slopes(lld x, lld s=-1): y(x), s(s) { p.push(x); p.push(x); }

  int size() { return p.size(); }

  void add(Slopes &S) {
    if (size() < S.size()) swap(*this, S);
    y += S.y;
    s += S.s;
    while (!S.p.empty()) {
      p.push(S.p.top()); S.p.pop();
    }
  }

  void convolute(lld x) {
    assert(p.size() >= 2);
    y += x;
    while (p.size() > -s+1) p.pop();
    lld a = p.top(); p.pop();
    lld b = p.top(); p.pop();
    p.push(a+x);
    p.push(b+x);
  }
} S[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=2; i<=N+M; i++) {
    cin >> P[i] >> C[i];
  }

  for (int i=N+M; i>=2; i--) {
    if (i > N) S[i] = Slopes(C[i]);
    else S[i].convolute(C[i]);
    S[P[i]].add(S[i]);
  }

  S[1].convolute(0);
  S[1].p.pop();
  lld y = S[1].y;
  while (!S[1].p.empty()) {
    y -= S[1].p.top(); S[1].p.pop();
  }

  cout << y << endl;

  ////////////////////////////////
  return 0;
}
