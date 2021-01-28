#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100'005;
int N, Q, par[MN], sz[MN];
vector<pii> E;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N; i++) { par[i] = i; sz[i] = 1; }

  for (int i=1; i<=N; i++) {
    int s, e, _; cin >> s >> e >> _;
    E.push_back({s, -i}); // insert first
    E.push_back({e, i}); // then delete
  }

  sort(E.begin(), E.end());

  set<int> S;
  for (int i=0; i<E.size(); i++) {
    if (E[i].second < 0) { // insert
      if (!S.empty()) merge(-E[i].second, *S.begin());
      S.insert(-E[i].second);
    } else { // delete
      S.erase(E[i].second);
    }
  }

  for (int i=0; i<Q; i++) {
    int a, b; cin >> a >> b;
    cout << (find(a) == find(b)) << endl;
  }

  ////////////////////////////////
  return 0;
}
