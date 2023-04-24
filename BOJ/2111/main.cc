#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct BigInt {
  vector<int> d;

  BigInt(int x) { while (x) d.push_back(x % 10), x /= 10; }

  BigInt& operator *=(const BigInt &X) {
    vector<int> res(sz(d) + sz(X.d));
    for (int i=0; i<sz(d); i++)
      for (int j=0; j<sz(X.d); j++)
        res[i+j] += d[i] * X.d[j];
    
    int carry = 0;
    for (int i=0; i<sz(res); i++) {
      res[i] += carry;
      carry = res[i] / 10;
      res[i] %= 10;
    }

    while (!res.empty() && res.back() == 0) res.pop_back();
    d = res;
    return *this;
  }
};

ostream& operator <<(ostream &os, BigInt &X) {
  for (int i=sz(X.d)-1; i>=0; i--) os << X.d[i];
  return os;
}

////////////////////////////////////////////////////////////////
const int MN = 20202;
int N, M;
vector<int> adj[MN];
int idx, dfn[MN], up[MN], down[MN], dep[MN], ok = 1;
vector<int> cyc;

int dfs(int u, int p, int d) {
  dfn[u] = ++idx;
  dep[u] = d;
  int cnt = 0;
  
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (dfn[v]) {
      if (dfn[v] < dfn[u]) { // back edge
        cyc.push_back(d-dep[v]+1);
        up[u]++, down[v]++;
      }
      continue;
    }
    cnt += dfs(v, u, d+1);
  }

  cnt += up[u] - down[u];
  if (cnt > 1) ok = 0;
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int k; cin >> k;
    vector<int> path(k);
    for (int j=0; j<k; j++) cin >> path[j];
    for (int j=0; j<k-1; j++) {
      int u = path[j], v = path[j+1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  // bcc
  dfs(1, 0, 0);
  for (int u=1; u<=N; u++) { if (!dfn[u]) ok = 0; }
  if (!ok) { cout << 0 << endl; return 0; }

  // count
  BigInt ans(1);
  for (auto c: cyc) ans *= c+1;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
