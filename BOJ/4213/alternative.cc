#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// select which groups to not split (connect), find max num of connections
// A: complete group of plates / a: incomplete group of plates
// Don't connect like this: a-"b"-c (b cannot be completed)
// At most one connections for each adjacent diam pairs: a-b / a-b impossible
// Scan each diam pairs, DP to choose which stack to make connection

bool solve(int test) {
  int N; cin >> N;
  if (cin.fail()) return false;
  vector<vector<int>> diam(N);
  vector<int> xs;
  for (int i=0; i<N; i++) {
    int h; cin >> h;
    diam[i].resize(h);
    for (int j=0; j<h; j++) {
      cin >> diam[i][j];
      xs.push_back(diam[i][j]);
    }
  }

  // compress
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  int M = sz(xs);

  for (int i=0; i<N; i++) {
    for (auto &d: diam[i]) d = lower_bound(all(xs), d) - xs.begin();
  }

  // get groups
  vector<vector<int>> cnt(N, vector<int>(M+1));
  vector<int> tot(M+1);
  int splits = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<sz(diam[i]); j++) {
      cnt[i][diam[i][j]]++;
      tot[diam[i][j]]++;
      if (j > 0 && diam[i][j-1] != diam[i][j]) splits++;
    }
  }

  // DP
  // D[i][s]: connect ith pair (= (i-1)-i pair) at sth stack
  // E[i]: don't connect ith pair
  vector<vector<int>> D(M+1, vector<int>(N));
  vector<int> E(M+1);

  for (int i=1; i<=M; i++) {
    // reset
    for (int s=0; s<N; s++) D[i][s] = E[i-1];
    E[i] = E[i-1];

    for (int s=0; s<N; s++) { // cur
      if (cnt[s][i-1] > 0 && cnt[s][i] > 0) { // connectable
        D[i][s] = E[i-1] + 1;
        for (int t=0; t<N; t++) { // prev
          if (t == s && cnt[s][i-1] < tot[i-1]) continue; // skip A-b-C
          D[i][s] = max(D[i][s], D[i-1][t] + 1);
        }
      }

      E[i] = max(E[i], D[i-1][s]);
    }
  }

  splits -= E[M];
  int ans = splits + (N+splits-1);
  cout << "Case " << test << ": " << ans << endl;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int t=1; ; t++) {
    if (!solve(t)) break;
  }

  ////////////////////////////////
  return 0;
}
