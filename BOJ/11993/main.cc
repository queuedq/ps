#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int s = 0, sum = 0;
  for (int i=0; i<N*2; i++) {
    if (sum < 0) { s = i%N; sum = 0; }
    sum += A[i%N]-1;
  }
  
  int l = s;
  lld ans = 0;
  for (int i=s; i<N+s; i++) {
    while (A[l%N] == 0) l++;
    ans += (i-l) * (i-l);
    A[l%N]--;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
