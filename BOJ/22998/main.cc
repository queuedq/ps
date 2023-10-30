#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = (1<<18)+1;
int D[MK], E[MK];

void trace(int K, int base, vector<int> &ans) {
  if (K == 1) return;

  if (E[K] == 0) {
    trace(K-1, base+1, ans);
    ans.push_back(base);
  } else {
    trace(K/E[K], base, ans);
    trace(E[K], base+D[K/E[K]], ans);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  D[1] = 0;
  for (int i=2; i<MK; i++) {
    D[i] = D[i-1]+1, E[i] = 0; // at bottom

    for (int d=2; d<=31; d++) { // group at top
      int val = D[i/d] + D[d];
      if (i%d == 0 && val < D[i])
        D[i] = min(D[i], val), E[i] = d;
    }
  }

  int T; cin >> T;
  while (T--) {
    int K; cin >> K;

    vector<int> ans;
    trace(K+1, 1, ans);

    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
