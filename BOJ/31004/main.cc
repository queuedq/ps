#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, uniq[MN];

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int x; cin >> x;
  return x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;

  int x = 0;
  for (int i=1; i<=N; i++) {
    int y = query(1, i);
    uniq[i] = x < y;
    x = y;
  }

  x = 0;
  for (int i=N; i>=1; i--) {
    int y = query(i, N);
    uniq[i] &= x < y;
    x = y;
  }

  vector<int> ans;
  for (int i=1; i<=N; i++) {
    if (uniq[i]) ans.push_back(i);
  }

  cout << "! " << sz(ans);
  for (auto x: ans) cout << " " << x;
  cout << endl;

  ////////////////////////////////
  return 0;
}
