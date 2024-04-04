#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
 
////////////////////////////////////////////////////////////////
const int MK = 202020;
const lld INF = 1e18;
lld M, K, A[MK], dst[MK][2][2];
 
lld get_dist(int N, string S[2], int a, int b) {
  int y = a;
  if (S[y][0] == '#') return INF;
 
  int d = 0;
  for (int x=1; x<N; x++) {
    if (S[y][x] == '#') {
      if (S[!y][x-1] == '#' || S[!y][x] == '#') return INF;
      y = !y;
      d++;
    }
    d++;
  }
 
  if (y == b) return d;
  if (S[!y][N-1] != '#') return d+1;
  return INF;
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
 
  cin >> M >> K;
  for (int i=0; i<K; i++) { cin >> A[i]; A[i]--; }
 
  for (int i=0; i<M; i++) {
    string S[2];
    cin >> S[0] >> S[1];
    int N = sz(S[0]);
 
    for (int a=0; a<2; a++)
      for (int b=0; b<2; b++)
        dst[i][a][b] = get_dist(N, S, a, b);
  }
 
  lld D[2] = {0, 0};
  for (int i=0; i<K; i++) {
    lld E[2];
    E[0] = min({INF, D[0]+1 + dst[A[i]][0][0], D[1]+1 + dst[A[i]][1][0]});
    E[1] = min({INF, D[0]+1 + dst[A[i]][0][1], D[1]+1 + dst[A[i]][1][1]});
    D[0] = E[0], D[1] = E[1];
  }
 
  lld ans = min(D[0], D[1]);
  if (ans == INF) cout << -1 << endl;
  else cout << ans-1 << endl;
 
  ////////////////////////////////
  return 0;
}
