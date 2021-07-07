#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
int N, A[MN], h[MN], B[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> h[i];
  sort(h, h+N);

  int s = 0, e = N-1;
  for (int i=1; i<N-1; i++) {
    bool l = A[i-1] < A[i], r = A[i] < A[i+1];
    if (!l && r) B[i] = h[s++];
    if (l && !r) B[i] = h[e--];
  }

  if (A[0] < A[1]) B[0] = h[s++];
  else B[0] = h[e--];
  if (A[N-2] < A[N-1]) B[N-1] = h[e--];
  else B[N-1] = h[s++];

  for (int i=1; i<N-1; i++) {
    bool l = A[i-1] < A[i], r = A[i] < A[i+1];
    if (l && r) B[i] = h[s++];
    if (!l && !r) B[i] = h[e--];
  }

  lld ans = 0;
  for (int i=0; i<N-1; i++) ans += abs(B[i+1] - B[i]);
  cout << ans << endl;
  for (int i=0; i<N; i++) cout << B[i] << " ";

  ////////////////////////////////
  return 0;
}
