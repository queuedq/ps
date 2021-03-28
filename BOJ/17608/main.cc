#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100'005;
int N, H[MN], cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> H[i];
  int mx = 0;
  for (int i=N-1; i>=0; i--) {
    if (H[i] > mx) {
      mx = H[i];
      cnt++;
    }
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
