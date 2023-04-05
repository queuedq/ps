#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, C, A[105];

bool solve(int i, int c) {
  if (i == N-1) return c == 0;
  sort(A+i, A+N);
  int j = min(i+c, N-1);
  bool ok = solve(i+1, c-j+i);
  reverse(A+i, A+j+1);
  return ok;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N >> C;
    C -= N-1; // sum of j-i instead of j-i+1
    for (int i=0; i<N; i++) A[i] = i+1;
    bool ok = C >= 0 && solve(0, C);
    cout << "Case #" << t << ": ";
    if (ok) {
      for (int i=0; i<N; i++) cout << A[i] << " ";
      cout << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
