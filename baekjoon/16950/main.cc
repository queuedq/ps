#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'005;
int N, M, K, par[MN];
vector<pair<int, pii>> edge;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  par[y] = x;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    char c; int f, t; cin >> c >> f >> t;
    edge.push_back({c == 'B', {f, t}});
  }

  sort(edge.begin(), edge.end());

  vector<pii> blue;
  int C0 = 0;
  for (int i=1; i<=N; i++) par[i] = i;
  for (int i=0; i<M; i++) {
    auto [c, e] = edge[i];
    if (merge(e.X, e.Y)) {
      C0 += c;
      if (c == 1) blue.push_back(e);
    }
  }

  int C1 = 0;
  for (int i=1; i<=N; i++) par[i] = i;
  for (int i=M-1; i>=0; i--) {
    auto [c, e] = edge[i];
    if (merge(e.X, e.Y)) C1 += c;
  }

  if (K < C0 || C1 < K) { cout << 0 << endl; return 0; }

  vector<pii> T;
  for (int i=1; i<=N; i++) par[i] = i;
  for (auto e: blue) {
    if (merge(e.X, e.Y)) {
      T.push_back(e);
      K--;
    }
  }
  for (int i=M-1; i>=0; i--) {
    if (K == 0) break;
    auto [c, e] = edge[i];
    if (merge(e.X, e.Y)) {
      T.push_back(e);
      K--;
    }
  }
  for (int i=0; i<M; i++) {
    auto [c, e] = edge[i];
    if (merge(e.X, e.Y)) {
      T.push_back(e);
    }
  }

  for (auto [u, v]: T) {
    cout << u << " " << v << endl;
  }

  ////////////////////////////////
  return 0;
}
