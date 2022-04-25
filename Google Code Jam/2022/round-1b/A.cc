#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN];

int solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int i=0, j=N-1, mx=0, ans=0;
  while (i <= j) {
    if (A[i] <= A[j]) {
      if (A[i] >= mx) ans++;
      mx = max(mx, A[i]);
      i++;
    } else {
      if (A[j] >= mx) ans++;
      mx = max(mx, A[j]);
      j--;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    int answer = solve();
    cout << "Case #" << t << ": " << answer << endl;
  }

  ////////////////////////////////
  return 0;
}
