#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2e5+5;
int N, K, A[MN], s[MN], ms[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];

  int l=0, r=MN;
  while (l+1 < r) {
    int m = (l+r)/2;
    for (int i=1; i<=N; i++) {
      s[i] = s[i-1] + (A[i]>=m ? 1 : -1);
      ms[i] = min(ms[i-1], s[i]);
    }
    bool ok = false;
    for (int i=K; i<=N; i++) {
      if (s[i] - ms[i-K] >= 1) { ok = true; break; }
    }
    if (ok) l = m;
    else r = m;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
