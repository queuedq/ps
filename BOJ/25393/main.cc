#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 1e6+5;
int N, Q;
vector<int> L[MX], R[MX];

int query(int l, int r) {
  int i = lower_bound(all(L[l]), r) - L[l].begin();
  int j = lower_bound(all(R[r]), l) - R[r].begin();
  if (i == L[l].size()) return -1;
  if (L[l][i] == r) return 1;
  if (j-1 < 0) return -1;
  return 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int l, r; cin >> l >> r;
    L[l].push_back(r);
    R[r].push_back(l);
  }
  for (int i=0; i<MX; i++) {
    sort(all(L[i]));
    sort(all(R[i]));
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int l, r; cin >> l >> r;
    cout << query(l, r) << endl;
  }

  ////////////////////////////////
  return 0;
}
