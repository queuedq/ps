#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e6+5;
int N, par[MAXN], sz[MAXN], cnt[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=2; i<=N; i++) cin >> par[i];
  for (int i=N; i>=1; i--) {
    sz[i]++;
    cnt[sz[i]]++;
    sz[par[i]] += sz[i];
  }

  for (int k=1; k<=N; k++) {
    if (N % k) continue;
    int g = N/k, tot = 0;
    for (int i=g; i<=N; i+=g) tot += cnt[i];
    if (tot == k) cout << k << ' ';
  }

  ////////////////////////////////
  return 0;
}
