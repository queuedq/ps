#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, par[MN], sz[MN], W[MN]; // W[i]: weight of edge (i, par[i])
vector<lld> ans;
map<int, int> cnt[MN];

struct Edge { int a, b, z; };
Edge edges[MN];
int ord[MN];

pii find(int x) {
  if (x == par[x]) return {x, 0};
  auto [r, w] = find(par[x]);
  par[x] = r;
  W[x] ^= w;
  return {r, W[x]};
}

int merge(int x, int y, int z) { // returns newly created boring pairs
  auto [xr, xw] = find(x);
  auto [yr, yw] = find(y);
  if (sz[xr] < sz[yr]) { swap(xr, yr); swap(xw, yw); }

  par[yr] = xr;
  sz[xr] += sz[yr];
  W[yr] = xw ^ yw ^ z;

  int diff = 0; // number of new boring pairs
  for (auto [w, c]: cnt[yr]) {
    diff += cnt[xr][w ^ W[yr]] * c;
    cnt[xr][w ^ W[yr]] += c;
  }

  cnt[yr].clear();

  return diff;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    par[i] = i;
    sz[i] = 1;
    cnt[i][0] = 1;
  }

  for (int i=1; i<=N-1; i++) {
    cin >> edges[i].a >> edges[i].b >> edges[i].z;
  }
  for (int i=1; i<=N-1; i++) cin >> ord[i];

  ans.push_back(0);
  for (int i=N-1; i>=1; i--) {
    auto e = edges[ord[i]];
    int diff = merge(e.a, e.b, e.z);
    ans.push_back(ans.back() + diff);
  }

  reverse(all(ans));
  for (auto a: ans) {
    cout << a << endl;
  }

  ////////////////////////////////
  return 0;
}
