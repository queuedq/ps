#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
lld N, M, A[MN][MN], r[MN*MN], c[MN*MN], a[MN*MN];
vector<pll> ans;

void add(int k, lld v) {
  a[k] += v, a[k+1] += v;
  ans.push_back({k, v});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cin >> A[i][j];
  }

  // zig zag order
  int k = 0;
  for (int i=0; i<N; i++) {
    if (i%2 == 0)
      for (int j=0; j<M; j++, k++) r[k] = i, c[k] = j, a[k] = A[i][j];
    else
      for (int j=M-1; j>=0; j--, k++) r[k] = i, c[k] = j, a[k] = A[i][j];
  }

  // check possibility
  lld s[2] = {0, 0};
  for (k=0; k<N*M; k++) s[k%2] += a[k];
  if (s[0] != s[1]) { cout << -1 << endl; return 0; }

  // construct
  for (k=0; k<N*M-1; k++) {
    if (a[k] == 0) continue;
    if (a[k] <= a[k+1]) add(k, -a[k]);
    else { add(k+1, a[k]-a[k+1]); add(k, -a[k]); }
  }

  cout << sz(ans) << endl;
  for (auto [k, v]: ans) {
    cout << r[k]+1 << ' ' << c[k]+1 << ' '
         << r[k+1]+1 << ' ' << c[k+1]+1 << ' '
         << v << endl;
  }

  ////////////////////////////////
  return 0;
}
