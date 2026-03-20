#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
lld N, M, x[MN], tot, nxt[MN], vst[MN];
pii A[MN];
vector<pll> S, E;
vector<int> ans[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> x[i];
  for (int i=1; i<=M; i++) {
    int s, e; cin >> s >> e;
    A[i] = {s, e};
    S.push_back({s, i});
    E.push_back({e, i});
    tot += abs(x[e]-x[s]);
  }
  sort(all(S));
  sort(all(E));

  for (int i=0; i<M; i++) {
    nxt[E[i].second] = S[i].second;
    tot += abs(x[E[i].first] - x[S[i].first]);
  }

  for (int i=1; i<=M; i++) {
    if (vst[i]) continue;
    int s = A[i].first;
    vst[i] = 1;
    ans[s].push_back(i);
    for (int j=nxt[i]; j!=i; j=nxt[j]) {
      vst[j] = 1;
      ans[s].push_back(j);
    }
  }

  cout << tot << endl;
  for (int i=1; i<=N; i++) {
    cout << ans[i].size() << " ";
    for (auto j: ans[i]) cout << j << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
