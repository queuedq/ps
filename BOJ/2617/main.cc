#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
vector<int> lt[100], gt[100];
bool vst[100];

void dfs_lt(int u) {
  if (vst[u]) return;
  vst[u] = true;
  for (auto v: lt[u]) dfs_lt(v);
}

void dfs_gt(int u) {
  if (vst[u]) return;
  vst[u] = true;
  for (auto v: gt[u]) dfs_gt(v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b; // weight of a > weight of b
    lt[a].push_back(b);
    gt[b].push_back(a);
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    bool ok = true;

    fill(vst+1, vst+N+1, false);
    dfs_lt(i);
    if (count(vst+1, vst+N+1, true) > (N+1)/2) ok = false;

    fill(vst+1, vst+N+1, false);
    dfs_gt(i);
    if (count(vst+1, vst+N+1, true) > (N+2)/2) ok = false;

    if (!ok) ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
