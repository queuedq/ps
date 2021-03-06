#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2e5+5;
int N, M, L[MN], R[MN];
string S, T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> S >> T;
  for (int i=0, j=0; j<M; j++) {
    while (S[i] != T[j]) i++;
    L[j] = i++;
  }

  for (int i=N-1, j=M-1; j>=0; j--) {
    while (S[i] != T[j]) i--;
    R[j] = i--;
  }

  int ans = 0;
  for (int j=0; j<M-1; j++) {
    ans = max(ans, R[j+1] - L[j]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
