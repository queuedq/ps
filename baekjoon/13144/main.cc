#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, A[MN], last[MN], L[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  fill(last, last+MN, -1);
  for (int i=0; i<N; i++) {
    cin >> A[i];
    L[i] = last[A[i]];
    last[A[i]] = i;
  }

  lld ans = 0;
  for (int i=0, j=0; j<N; j++) {
    while (i <= L[j]) i++;
    ans += j-i+1;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
