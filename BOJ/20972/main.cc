#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, A[MN][MN], R[MN][2], C[MN][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> A[i][j];
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) R[i][j%2] += A[i][j];
    for (int j=0; j<N; j++) C[i][j%2] += A[j][i];
  }

  int ans1 = 0, ans2 = 0;
  for (int i=0; i<N; i++) {
    ans1 += max(R[i][0], R[i][1]);
    ans2 += max(C[i][0], C[i][1]);
  }
  cout << max(ans1, ans2) << endl;

  ////////////////////////////////
  return 0;
}
