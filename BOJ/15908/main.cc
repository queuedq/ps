#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN], B[MN], psum[MN], D[MN], E[MN];
// D[i]: possible starting at i
// E[i]: D[i] + ... + D[N+1]

bool solve(int x) { // B[i] <= x removable
  fill(psum+1, psum+N+1, 0);
  fill(D+1, D+N+1, 0);
  fill(E+1, E+N+1, 0);

  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + (B[i] > x);

  D[N+1] = E[N+1] = 1;
  for (int i=N; i>=1; i--) {
    int l = i + A[i], r = N+2;
    while (l+1 < r) {
      int m = (l+r)/2;
      if (psum[m-1] - psum[i] + 1 <= A[i]) l = m; // must contain A[i]
      else r = m;
    }
    
    int s = i + A[i], e = l;

    if (s > N+1) D[i] = 0;
    else D[i] = E[s] - E[e+1] > 0;
    if (B[i] <= x) D[i] |= D[i+1];
    E[i] = E[i+1] + D[i];
  }

  return D[1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];

  int l = -1, r = 101010;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (solve(m)) r = m;
    else l = m;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
