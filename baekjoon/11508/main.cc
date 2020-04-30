#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, C[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> C[i];

  sort(C, C+N, greater<int>());

  int ans = 0;
  for (int i=0; i<N; i++) {
    if ((i+1) % 3) ans += C[i];
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
