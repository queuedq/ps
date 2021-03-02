#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 300'005;
const int MC = 10'005;
int N, C, M, A[MN];
vector<int> idx[MC];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> C;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    idx[A[i]].push_back(i);
  }
  cin >> M;

  for (int i=0; i<M; i++) {
    int l, r; cin >> l >> r;
    int X = 0;

    for (int t=0; t<100; t++) {
      int c = A[l + rand() % (r-l+1)];
      int cnt =
        upper_bound(idx[c].begin(), idx[c].end(), r) -
        lower_bound(idx[c].begin(), idx[c].end(), l);
      if (cnt > (r-l+1)/2) { X = c; break; }
    }

    if (X) cout << "yes " << X << endl;
    else cout << "no" << endl;
  }

  ////////////////////////////////
  return 0;
}
