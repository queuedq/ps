#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, A[MN], B[MN], ans[MN];

bool solve() {
  // handle all zero case
  bool all_zero = 1;
  for (int i=0; i<N; i++) all_zero &= A[i] == 0;
  if (all_zero) return true; // keep ans[i] = 0

  // count left-/right-facing sparrows
  int L = 0, R = 0;
  for (int i=0; i<N; i++) {
    if (A[i] == 0) L++;
    else { L += A[i]; break; }
  }
  for (int i=N-1; i>=0; i--) {
    if (A[i] == 0) R++;
    else { R += A[i]; break; }
  }

  if (L+R != N) return false;

  // decide from left
  int l = L, r = 0;
  for (int i=0; i<N; i++) {
    if (l == r) break; // cannot decide further
    if (A[i] == l) ans[i] = 1, r++;
    else if (A[i] == r) ans[i] = 0, l--;
    else return false;
  }

  // decide from right
  l = 0, r = R;
  for (int i=N-1; i>=0; i--) {
    if (l == r) break; // cannot decide further
    if (A[i] == r) ans[i] = 0, l++;
    else if (A[i] == l) ans[i] = 1, r--;
    else return false;
  }

  // count and check
  l = 0, r = 0;
  for (int i=0; i<N; i++) {
    if (ans[i] == 1) r++;
    else B[i] = r;
  }
  for (int i=N-1; i>=0; i--) {
    if (ans[i] == 0) l++;
    else B[i] = l;
  }

  for (int i=0; i<N; i++) {
    if (A[i] != B[i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  bool ok = solve();

  if (!ok) cout << -1 << endl;
  else {
    for (int i=0; i<N; i++) cout << ans[i] << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
