#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
int N, L;
int par[MN], full[MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=1; i<=L; i++) par[i] = i;

  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    x = find(x), y = find(y);
    
    if (full[x] && full[y]) cout << "SMECE" << endl;
    else {
      cout << "LADICA" << endl;
      if (x == y) full[x] = 1;
      else {
        par[y] = x;
        full[x] |= full[y];
      }
    }
  }

  ////////////////////////////////
  return 0;
}
