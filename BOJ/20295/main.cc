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
int N, M, candy[MN], dsu[6][MN], cnt[6];
int fri[MN], want[MN];
vector<pii> edges;

int find(int k, int x) {
  if (dsu[k][x] == x) return x;
  return dsu[k][x] = find(k, dsu[k][x]);
}

void merge(int k, int x, int y) {
  x = find(k, x), y = find(k, y);
  dsu[k][y] = x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> candy[i];
    cnt[candy[i]]++;
  }
  for (int k=1; k<=5; k++) {
    for (int i=1; i<=N; i++) dsu[k][i] = i;
  }
  for (int i=1; i<=N-1; i++) {
    int u, v; cin >> u >> v;
    for (int k=1; k<=5; k++) {
      if (candy[u] != k && candy[v] != k) merge(k, u, v);
    }
  }

  // queries
  cin >> M;
  for (int i=1; i<=M; i++) cin >> fri[i] >> want[i];
  
  cout << (cnt[want[1]] ? "PLAY" : "CRY") << endl;
  for (int i=2; i<=M; i++) {
    int u = fri[i-1], v = fri[i];
    if (candy[u] == want[i] || candy[v] == want[i] || find(want[i], u) != find(want[i], v)) {
      cout << "PLAY" << endl;
    } else {
      cout << "CRY" << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
