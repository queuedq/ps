#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MN = 1e6;
lld N, A[MN], S[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  A[1] = 1, A[2] = 2;
  S[1] = 1, S[2] = 3;
  for (int i=2; i<MN; i++) {
    S[i] = S[i-1] + A[i];
    for (lld j=S[i-1]+1; j<=min(S[i], MN-1); j++) A[j] = i;
  }

  cin >> N;
  for (int i=0;; i++) {
    if (S[i] >= N) { cout << i << endl; return 0; }
  }

  ////////////////////////////////
  return 0;
}
