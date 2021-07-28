#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 250'005;
int N, A[MN], B[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> B[i];
  
  lld ans1 = 0;
  for (int i=0, j=0; i<N; i++) {
    if (A[i] > N/2) {
      while (B[j] > (N+1)/2) j++;
      ans1 += abs(i - j);
      j++;
    }
  }

  lld ans2 = 0;
  for (int i=0, j=0; i<N; i++) {
    if (A[i] > (N+1)/2) {
      while (B[j] > N/2) j++;
      ans2 += abs(i - j);
      j++;
    }
  }

  cout << min(ans1, ans2) << endl;

  ////////////////////////////////
  return 0;
}
