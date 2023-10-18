#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
int N, adj[MN][MN], T[MN], vst[MN];

bool match(int u) {
  if (vst[u]) return false;
  vst[u] = true;

  for (int v=1; v<=N; v++) {
    if (!adj[u][v]) continue;
    if (!T[v] || match(T[v])) {
      T[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      char c; cin >> c;
      adj[i][j] = c-'0';
    }
  }

  for (int k=1; k<=N; k++) {
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=N; j++) {
        if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
      }
    }
  }

  int cnt = 0;
  for (int i=1; i<=N; i++) {
    fill(vst, vst+N+1, 0);
    cnt += match(i);
  }

  cout << N - cnt << endl;

  ////////////////////////////////
  return 0;
}
