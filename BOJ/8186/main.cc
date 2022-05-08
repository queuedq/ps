#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 202020;
lld N, A[MN], L[MN], R[MN], pw[MN];

lld mod(lld x) { return (x%MOD+MOD)%MOD; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) L[i] = (L[i-1]*(N+1) + A[i]) % MOD;
  for (int i=N; i>=1; i--) R[i] = (R[i+1]*(N+1) + A[i]) % MOD;
  pw[0] = 1;
  for (int i=1; i<=N; i++) pw[i] = pw[i-1]*(N+1) % MOD;

  int mx = 0;
  vector<int> ans;
  for (int k=1; k<=N; k++) {
    set<pll> hashes;
    for (int i=k; i<=N; i+=k) {
      lld H1 = mod(L[i] - L[i-k]*pw[k]);
      lld H2 = mod(R[i-k+1] - R[i+1]*pw[k]);
      if (H1 > H2) swap(H1, H2);
      hashes.insert({H1, H2});
    }
    if (hashes.size() > mx) { mx = hashes.size(); ans.clear(); }
    if (hashes.size() == mx) ans.push_back(k);
  }

  cout << mx << " " << ans.size() << endl;
  for (int k: ans) cout << k << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
