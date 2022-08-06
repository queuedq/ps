#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, A[MN], match[MN];
vector<lld> idx[MN];

struct fenwick_tree { // 1-based
  vector<lld> F;
  fenwick_tree(int n) { F.resize(n+1); }

  void add(int i, lld x) {
    for (; i<sz(F); i += i&-i) F[i] += x;
  }

  lld sum(int i) {
    lld s = 0;
    for (; i>0; i -= i&-i) s += F[i];
    return s;
  }
};

void solve(int t) {
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    idx[A[i]].push_back(i);
  }

  for (int i=1; i<=N; i++) {
    int s = sz(idx[i]);
    for (int j=0, k=s-1; j<=k; j++, k--) {
      int l = idx[i][j], r = idx[i][k];
      match[l] = r, match[r] = l;
    }
  }

  fenwick_tree F(N);
  lld ans = 0;
  for (int i=1; i<=N; i++) {
    if (match[i] > i) { // left
      F.add(i, 1); // open
    } else if (match[i] < i) { // right
      F.add(match[i], -1); // close
      ans += i - match[i];
      ans -= F.sum(i) - F.sum(match[i]);
    }
  }

  cout << "Case #" << t << endl;
  cout << ans << endl;
}

void reset() {
  for (int i=1; i<=N; i++) idx[i].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
    reset();
  }

  ////////////////////////////////
  return 0;
}
