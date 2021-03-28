#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e7+5;
lld N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  N = 1e7;

  A[1] = 1;
  int j = 1, k = 1;
  for (int i=2; i<=N; i++) {
    A[i] = min(A[j]*2+1, A[k]*3+1);
    while (A[j]*2+1 <= A[i]) j++;
    while (A[k]*3+1 <= A[i]) k++;
  }

  int T; cin >> T;
  while (T--) {
    cin >> N;
    cout << A[N] << endl;
  }

  ////////////////////////////////
  return 0;
}
