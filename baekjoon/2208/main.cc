#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e6 + 5;
int N, M, A[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  int S = 0, T = 0, minT = 0, ans = INT_MIN;
  for (int i = 1; i <= N; i++) {
    S += A[i];
    if (i >= M) {
      T += A[i - M];
      minT = min(minT, T);
      ans = max(ans, S - minT);
    }
  }

  cout << max(ans, 0) << endl;

  ////////////////////////////////
  return 0;
}
