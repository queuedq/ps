#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MV = 105;
lld V, P, L, A[MV];
lld cost[MV][MV*2]; // start, end
lld D[MV][MV][MV]; // count, start, end
lld E[MV][MV][MV]; // previous index

lld dist(lld a, lld b) {
  return min(abs(a - b), L - abs(a - b));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> V >> P >> L;
  for (int i=0; i<V; i++) cin >> A[i];

  for (int i=0; i<V; i++) {
    for (int j=i+1; j<V+i+1; j++) {
      for (int k=i; k<j; k++) {
        cost[i][j%V] += min(dist(A[i], A[k%V]), dist(A[j%V], A[k%V]));
      }
    }
  }

  for (int j=0; j<V; j++) {
    for (int k=0; k<V; k++) D[1][j][k] = INF;
    D[1][j][j] = 0;
  }

  for (int i=2; i<=P; i++) {
    for (int j=0; j<V; j++) {
      for (int k=j; k<V+j; k++) {
        D[i][j][k%V] = INF;
        for (int l=j; l<k; l++) {
          lld d = D[i-1][j][l] + cost[l%V][k%V];
          if (d < D[i][j][k]) {
            D[i][j][k] = d;
            E[i][j][k] = l;
          }
        }
      }
    }
  }

  lld mn = INF;
  pii idx = {0, 0};
  for (int j=0; j<V; j++) {
    for (int k=j; k<V+j; k++) {
      lld d = D[P][j][k%V] + cost[k%V][j];
      if (d < mn) {
        mn = d;
        idx = {j, k};
      }
    }
  }

  vector<int> ans;
  auto [j, k] = idx;
  for (int i=P; i>0; i--) {
    ans.push_back(k);
    k = E[i][j][k];
  }
  sort(ans.begin(), ans.end());

  cout << mn << endl;
  for (auto a: ans) cout << A[a] << " ";

  ////////////////////////////////
  return 0;
}
