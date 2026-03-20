#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50010;
const int K = 5;
int N, A[MN], prv[MN][K], D[20][MN][1<<K];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // input
  vector<pii> weapons;
  for (int d=0; d<K; d++) {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
      int a; cin >> a;
      weapons.push_back({a, d});
    }
  }
  N = sz(weapons);
  sort(all(weapons));
  for (int i=1; i<=N; i++) A[i] = weapons[i-1].second;

  // calc prv
  int last[K] = {};
  for (int i=1; i<=N+1; i++) {
    for (int d=0; d<K; d++) prv[i][d] = last[d];
    last[A[i]] = i;
  }

  // calc good intervals
  for (int S=0; S<1<<K; S++) {
    int L[K], R[K];
    for (int d=0; d<K; d++) L[d] = N+1, R[d] = prv[N+1][d];
    
    for (int i=N, j=N; i>=1; i--) {
      L[A[i]] = i; // update range

      while (1) {
        int best = 0, mx = 0; // best weapon candidate
        for (int d=0; d<K; d++) {
          if (S>>d & 1 && L[d] > mx) best = d, mx = L[d];
        }
        bool ok = 1; // check if best is actually best
        for (int d=0; d<K; d++) {
          if (S>>d & 1 && d != best) ok &= R[d] < mx;
        }
        if (ok) break; // found good interval [i, j]

        // otherwise, reduce j
        R[A[j]] = prv[j][A[j]];
        j--;
      }

      D[0][i][S] = j;
    }
  }

  // dp
  for (int k=0; k<20; k++) fill(D[k][N+1], D[k][N+1]+(1<<K), N);

  for (int k=1; k<20; k++) {
    for (int i=1; i<=N; i++) {
      for (int S=0; S<1<<K; S++) {
        D[k][i][S] = N;
        int j = D[k-1][i][S] + 1;
        for (int T=S; T>0; T=(T-1)&S) {
          D[k][i][S] = min(D[k][i][S], D[k-1][j][T]);
        }
      }
    }

    // for (int i=1; i<=N; i++) cout << D[k][i][(1<<K)-1] << " "; cout << endl;
  }

  int ans = -1;
  for (int k=0; k<20; k++) {
    if (D[k][1][(1<<K)-1] == N) { ans = k; break; }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
