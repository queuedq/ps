#include <bits/stdc++.h>
#include <queue>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
lld N, d, h[MN];

vector<lld> S; // slope changes
lld D0;

void extend() {
  int i = 0;
  for (; i<sz(S)/2; i++) S[i] -= d;
  for (; i<sz(S); i++) S[i] += d;
}

void add(lld t) {
  D0 += abs(t - S[0]);

  t = min(max(t, S[0]), S.back());
  S.push_back(t);
  S.push_back(t);
  sort(all(S));
}

void solve() {
  cin >> N >> d;
  for (int i=1; i<=N; i++) cin >> h[i];

  S = {h[1], h[1]};
  D0 = 0;
  for (int i=2; i<=N; i++) {
    extend();
    add(h[i]);
  }

  if (h[N] < S[0] || h[N] > S.back()) {
    cout << "impossible" << endl;
    return;
  }

  lld D = D0, slope = -sz(S)/2;
  for (int i=1; i<sz(S); i++) {
    slope++;
    D += slope * (S[i]-S[i-1]);
    if (S[i] == h[N]) break;
  }

  cout << D << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve();

  ////////////////////////////////
  return 0;
}
