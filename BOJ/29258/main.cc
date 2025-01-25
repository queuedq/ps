#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, M;

lld larger() {
  // A line: y = N - t
  // B line: y = t - s
  lld s = N/M * M - M;
  if ((N+s) % 2 == 0) return (N+s) / 2;
  s += M;
  if ((N+s) % 2 == 0) return (N+s) / 2;

  // A line: y = 2N - t
  // B line: y = t - s
  s = N*2/M * M - M;
  if ((N*2+s) % 2 == 0) return (N*2+s) / 2;
  s += M;
  if ((N*2+s) % 2 == 0) return (N*2+s) / 2;

  assert(0);
}

lld smaller() {
  // B line: y = t
  // A line: y = s - t
  lld s = N;
  if (s % 2 == 0) return s / 2;

  // B line: y = M + t
  // A line: y = s - t
  s = (M-1)/N * N + N;
  if ((M+s) % 2 == 0) return (M+s) / 2;
  s += N;
  if ((M+s) % 2 == 0) return (M+s) / 2;

  assert(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N >> M;
    lld ans = N > M ? larger() : smaller();
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
