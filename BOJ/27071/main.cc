#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld MOD = 998'244'353;

lld pow(lld x, lld e) {
  if (e == 0) return 1;
  lld y = pow(x, e/2);
  return (y*y % MOD) * (e%2 ? x : 1) % MOD;
}

lld inv(lld x) {
  return pow(x, MOD-2);
}

////////////////////////////////////////////////////////////////
const int MN = 405;
int N, M, par[MN];
map<int, vector<pii>> edg;
lld fac[MN], ans = 1;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  par[y] = x;
}

int compress(vector<int> &v, int x) {
  return lower_bound(all(v), x) - v.begin();
}

lld cofactor(vector<vector<lld>> mat) {
  int n = sz(mat);
  lld res = 1;

  for (int c=1; c<n; c++) {
    for (int r=c; r<n; r++) {
      if (mat[r][c] != 0) {
        swap(mat[c], mat[r]);
        if (r != c) res *= -1;
        break;
      }
    }
    if (mat[c][c] == 0) return 0;
    
    for (int r=c+1; r<n; r++) {
      lld s = mat[r][c] * inv(mat[c][c]) % MOD;
      for (int i=c; i<n; i++)
        mat[r][i] = (mat[r][i] - mat[c][i] * s) % MOD;
    }
  }

  for (int c=1; c<n; c++) res = (res * mat[c][c]) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v, w; cin >> u >> v >> w;
    edg[w].push_back({u, v});
  }

  fac[0] = 1;
  for (int i=1; i<=N; i++) {
    par[i] = i;
    fac[i] = fac[i-1] * i % MOD;
  }

  for (auto &[w, we]: edg) {
    // build compressed graph
    for (auto &[u, v]: we) u = find(u), v = find(v);

    // find components
    map<int, vector<pii>> comp;
    for (auto [u, v]: we) merge(u, v);
    for (auto [u, v]: we) comp[find(u)].push_back({u, v});

    int cnt = 0; // num edges of weight w to add

    for (auto [r, c]: comp) {
      // build matrix
      vector<int> S;
      for (auto [u, v]: c) S.push_back(u), S.push_back(v);
      sort(all(S));
      S.erase(unique(all(S)), S.end());
      
      int n = sz(S);
      cnt += n-1;
      
      vector<vector<lld>> mat(n);
      for (int i=0; i<n; i++) mat[i].resize(n);

      for (auto [u, v]: c) {
        u = compress(S, u), v = compress(S, v);
        mat[u][u]++, mat[v][v]++;
        mat[u][v]--, mat[v][u]--;
      }

      ans = (ans * cofactor(mat)) % MOD;
    }

    ans = (ans * fac[cnt]) % MOD;
  }

  ans = (ans+MOD) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
