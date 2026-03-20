#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, A[MN];
int D[MN], cnt[MN];
vector<int> adj[MN], divisor[MN];
lld ans;

void dfs(int u) {
  ans += D[A[u]];
  for (auto d: divisor[A[u]]) {
    if (d != A[u]) ans += cnt[d];
  }

  for (auto d: divisor[A[u]]) D[d]++;
  cnt[A[u]]++;

  for (auto v: adj[u]) dfs(v);

  for (auto d: divisor[A[u]]) D[d]--;
  cnt[A[u]]--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=1; i<MN; i++) {
    for (int j=i; j<MN; j+=i) {
      divisor[j].push_back(i);
    }
  }

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=2; i<=N; i++) {
    int P; cin >> P;
    adj[P].push_back(i);
  }

  dfs(1);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
