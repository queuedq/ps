#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, H[MN], idx[MN], island[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> H[i];
  iota(idx+1, idx+N+1, 1);
  sort(idx+1, idx+N+1, [&](int i, int j){ return H[i] > H[j]; });
  
  int ans = 0, cnt = 0;

  for (int i=1; i<=N; i++) {
    int j = idx[i];
    bool L = island[j-1];
    bool R = island[j+1];
    island[j] = true;

    if (L && R) cnt--;
    else if (!L && !R) cnt++;
    
    if (i == N || H[j] != H[idx[i+1]]) ans = max(ans, cnt);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
