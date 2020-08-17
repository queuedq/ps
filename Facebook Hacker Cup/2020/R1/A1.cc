#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 1e6+5;
const lld MOD = 1e9+7;
lld T, N, K, W, L[MAXN], H[MAXN];

void calc(int test) {
  cin >> N >> K >> W;
  lld A, B, C, D;

  for (int i=1; i<=K; i++) cin >> L[i];
  cin >> A >> B >> C >> D;
  for (int i=K+1; i<=N; i++) L[i] = (A*L[i-2] + B*L[i-1] + C) % D + 1;

  for (int i=1; i<=K; i++) cin >> H[i];
  cin >> A >> B >> C >> D;
  for (int i=K+1; i<=N; i++) H[i] = (A*H[i-2] + B*H[i-1] + C) % D + 1;

  ////////////////////////////////

  lld ans = 1, perim = 0;
  priority_queue<pll> pq;

  for (int i=1; i<=N; i++) {
    while (!pq.empty() && pq.top().second + W < L[i]) pq.pop();

    if (pq.empty()) {
      perim += W*2 + H[i]*2;
    } else {
      auto [h, l] = pq.top();
      perim += (L[i]-L[i-1]) * 2;
      if (H[i] > h) perim += (H[i]-h) * 2;
    }

    pq.push({H[i], L[i]});
    perim %= MOD;
    ans = ans * perim % MOD;
  }

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int t=1; t<=T; t++) calc(t);

  ////////////////////////////////
  return 0;
}
