#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<lld> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    lld a; cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end());

  lld best = LLONG_MAX;
  vector<lld> ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      int q = lower_bound(A.begin(), A.end(), -A[i]-A[j]) - A.begin();
      int p = q - 1;
      while (p == i || p == j) { p--; }
      while (q == i || q == j) { q++; }
      if (p >= 0) {
        lld score = abs(A[i]+A[j]+A[p]);
        if (score < best) {
          ans = {A[i], A[j], A[p]};
          best = score;
        }
      }
      if (q < N) {
        lld score = abs(A[i]+A[j]+A[q]);
        if (score < best) {
          ans = {A[i], A[j], A[q]};
          best = score;
        }
      }
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

  ////////////////////////////////
  return 0;
}
