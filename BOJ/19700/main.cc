#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, cnt[MN], ans;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].first >> A[i].second;
  sort(A, A+N);

  cnt[1] = 1;
  for (int i=N-2; i>=0; i--) {
    auto [h, k] = A[i];
    int l = 0, r = N;
    while (l+1 < r) {
      int m = (l+r)/2;
      if (cnt[m] < k) r = m;
      else l = m;
    }
    cnt[r]++;
    ans = max(ans, r);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
