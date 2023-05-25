#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int MK = 205;
lld N, K, A[MN], S[MN], D[MN], ans[MK];
int E[MK][MN];

struct Line {
  lld a, b, idx;
  double inter = -INFINITY;
  bool operator <(const Line &L) const { return inter < L.inter; }

  double get_inter(Line L) const {
    // a x + b = L.a x + L.b
    return (double)(L.b - b) / (a - L.a);
  }
};
deque<Line> lines;

void add(Line L) {
  while (sz(lines) >= 2) {
    if (lines.back().inter < L.get_inter(lines.back())) break;
    lines.pop_back();
  }
  if (sz(lines) > 0) L.inter = L.get_inter(lines.back());
  lines.push_back(L);
}

pll get_min(lld x) {
  while (sz(lines) >= 2) {
    if (x < lines[1].inter) break;
    lines.pop_front();
  }
  return {lines[0].a * x + lines[0].b, lines[0].idx};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) {
    S[i] = S[i-1] + A[i];
    D[i] = S[i] * S[i];
  }

  // D[k][i] = min(D[k-1][j] + (S[i] - S[j]) ^ 2)
  //         = min(D[k-1][j] + S[i]^2 + S[j]^2 - 2 S[i] S[j])
  // line: (-2 S[j]) x + (D[k-1][j] + S[j]^2)
  for (int k=1; k<=K; k++) {
    lines.clear();
    add({0, 0, 0});

    for (int i=1; i<=N; i++) {
      lld prv = D[i];
      auto [mn, j] = get_min(S[i]);
      D[i] = mn + S[i] * S[i];
      E[k][i] = j;

      add({-2 * S[i], prv + S[i] * S[i], i});
    }
  }

  for (int k=K, i=N; k>=1; k--) ans[k] = i = E[k][i];

  cout << (S[N] * S[N] - D[N]) / 2 << endl;
  for (int k=1; k<=K; k++) cout << ans[k] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
