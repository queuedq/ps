#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 300'005;
lld N, M, K, A[MN], S[MN];
lld LS[MN], RS[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=M; i++) { int x; cin >> x; A[x] = 1; }
  for (int i=1; i<=N; i++) S[i] = S[i-1] + A[i];

  lld lh = (M+K)/2, rh = (M+K) - lh;

  // left sum
  int s = lh+1;
  for (int i=lh; i>=1; i--) {
    if (!A[i]) { s = i; LS[lh] += i-1; }
  }

  for (int i=lh+1; i<=N; i++) {
    if (S[i] > lh) break;
    LS[i] = LS[i-1];
    if (!A[i]) LS[i] += lh; // add one
    LS[i] -= S[s-1] + (lh-S[i]); // remove one
    do { s++; } while (A[s]);
  }

  // right sum
  int e = N-rh;
  for (int i=N-rh+1; i<=N; i++) {
    if (!A[i]) { e = i; RS[N-rh+1] += N-i; }
  }

  for (int i=N-rh; i>=1; i--) {
    if (S[N]-S[i-1] > rh) break;
    RS[i] = RS[i+1];
    if (!A[i]) RS[i] += rh; // add one
    RS[i] -= (S[N]-S[e]) + (rh-(S[N]-S[i-1])); // remove one
    do { e--; } while (A[e]);
  }

  // ans
  lld ans = LLONG_MAX;
  for (int i=lh; i<=N-rh; i++) {
    if (S[i] <= lh && S[N]-S[i] <= rh) {
      ans = min(ans, (M*2+K-1)*K/2 - 2*(LS[i]+RS[i+1]));
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
