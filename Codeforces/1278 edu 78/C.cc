#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 2e5 + 5;
int N, A[MAX_N], S[MAX_N];
int L[MAX_N], R[MAX_N];

int calc() {
  cin >> N;
  for (int i = 0; i < 2*N; i++) {
    cin >> A[i];
    if (A[i] == 2) A[i] = -1;
  }

  // Calc S
  S[0] = 0;
  int minS = 0, maxS = 0;
  for (int i = 1; i <= 2*N; i++) {
    S[i] = S[i-1] + A[i-1];
    minS = min(minS, S[i]);
    maxS = max(maxS, S[i]);
  }
  for (int i = 0; i <= 2*N; i++) S[i] -= minS; // min is 0 now
  maxS -= minS; minS = 0;

  // Calc L, R: nearest index of sum
  for (int i = minS; i <= maxS; i++) { L[i] = -1; R[i] = INT_MAX; }

  for (int i = 0; i <= N; i++) {
    L[S[i]] = max(L[S[i]], i);
  }

  for (int i = N; i <= 2*N; i++) {
    R[S[i]] = min(R[S[i]], i);
  }

  // for (int i = 0; i <= 2*N; i++) cout << S[i] << " ";
  // cout << endl;
  // for (int i = 0; i <= maxS; i++) {
  //   cout << L[i] << " " << R[i] << endl;
  // }

  // Calc ans
  int gap = S[2*N] - S[0];
  int ans = INT_MAX;
  for (int i = minS; i <= maxS; i++) {
    if (i + gap < minS || i + gap > maxS) continue;
    int l = L[i], r = R[i + gap];
    // cout << l << " " << r << endl;
    if (l == -1 || r == INT_MAX) continue;
    ans = min(ans, r - l);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
