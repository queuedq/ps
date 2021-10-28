#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
const int MK = 105;
lld T, N, K;
vector<pll> adj[MN];
vector<lld> D[MN];

vector<lld> conv(vector<lld> &A, vector<lld> &B) {
  lld a = A.size(), b = B.size();
  vector<lld> res(min(a+b-1, K+1), 0);
  for (int i=0; i<a; i++) {
    for (int j=0; j<b; j++) {
      if (i+j > K) break;
      res[i+j] = max(res[i+j], A[i] + B[j]);
    }
  }
  return res;
}

void dp(int u, lld c) {
  D[u].push_back(0);
  if (u != 1) D[u].push_back(0); // consider visiting u
  for (auto [v, w]: adj[u]) {
    dp(v, w);
    D[u] = conv(D[u], D[v]);
  }

  for (lld i=0; i<D[u].size(); i++) {
    D[u][i] += min(i, K-i+1) * c * 2;
  }
}

void solve(int test) {
  cin >> N >> K;
  for (int i=2; i<=N; i++) {
    lld p, w; cin >> p >> w;
    adj[p].push_back({i, w});
  }

  dp(1, 0);
  cout << "Case " << test << ": " << D[1][K] << endl;

  for (int i=1; i<=N; i++) {
    adj[i].clear();
    D[i].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
