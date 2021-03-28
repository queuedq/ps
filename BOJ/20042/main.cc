#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 2e9;
const int MN = 3005;
lld N, A[MN], maxr[MN];
vector<lld> lr[MN], rr[MN], R[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A[0] = -INF, A[N+1] = INF;
  for (int i=1; i<=N; i++) cin >> A[i];

  for (int i=1; i<=N; i++) {
    lld maxr = min(A[i]-A[i-1], A[i+1]-A[i]);;
    lr[i] = {maxr};

    for (lld s: lr[i-1]) {
      lld r = A[i]-A[i-1] - s;
      if (0 < r && r < maxr) lr[i].push_back(r);
    }

    lr[i].push_back(0);
    reverse(lr[i].begin(), lr[i].end());
  }

  for (int i=N; i>=1; i--) {
    lld maxr = min(A[i]-A[i-1], A[i+1]-A[i]);;
    rr[i] = {maxr};

    for (lld s: rr[i+1]) {
      lld r = A[i+1]-A[i] - s;
      if (0 < r && r < maxr) rr[i].push_back(r);
    }

    rr[i].push_back(0);
    reverse(rr[i].begin(), rr[i].end());
  }

  R[0] = D[0] = {0};

  for (int i=1; i<=N; i++) {
    merge(lr[i].begin(), lr[i].end(), rr[i].begin(), rr[i].end(), back_inserter(R[i]));
    R[i].erase(unique(R[i].begin(), R[i].end()), R[i].end());

    for (int j=0, k=R[i-1].size()-1; j<=R[i].size(); j++) {
      lld r = R[i][j];
      lld s = A[i]-A[i-1] - r;
      while (R[i-1][k] > s) k--;

      D[i].push_back(D[i-1][k] + r*r);
      if (j > 0) D[i][j] = max(D[i][j-1], D[i][j]);
    }
  }

  cout << D[N].back() << endl;

  ////////////////////////////////
  return 0;
}
