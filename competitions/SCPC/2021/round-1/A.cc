#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, D[MN], par[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  par[y] = x;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    for (int i=0; i<N; i++) par[i] = i;
    
    int ans = N;
    for (int i=0; i<N; i++) {
      cin >> D[i];
      if (i+D[i] < N) ans -= merge(i, i+D[i]);
    }
    
    cout << "Case #" << t << endl;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
