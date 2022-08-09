#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50505;
int N, M, S, W[MN], par[MN], cnt[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (cnt[x] < cnt[y]) swap(x, y);
  par[y] = x;
  cnt[x] += cnt[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  // strat: W[i] >= 2 is winning pos, so avoid it
  cin >> N >> M >> S;

  bool big = 0; // whether W[i] >= 2 exists
  for (int i=1; i<=N; i++) {
    cin >> W[i];
    big |= W[i] >= 2;
    par[i] = i;
    cnt[i] = 1;
  }

  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v;
    if (W[u] == 1 && W[v] == 1) merge(u, v);
  }

  if (W[S] >= 2) cout << "hwy" << endl;
  else cout << ((cnt[find(S)] + big) % 2 ? "hwy" : "sjh") << endl;

  ////////////////////////////////
  return 0;
}
