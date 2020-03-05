#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, L;
pii A[MAXN];
vector<lld> coords;
lld D[2][MAXN*2];

int compress(lld x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

lld cost(int i) {
  return abs(A[i].first-A[i].second) + L;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) {
    cin >> A[i].first >> A[i].second;
    coords.push_back(A[i].first);
    coords.push_back(A[i].second);
  }
  sort(A, A+N);
  sort(coords.begin(), coords.end());

  ////////

  lld ans = 0;
  for (int i=0; i<N; i++) {
    int t = compress(A[i].first);
    int b = compress(A[i].second);

    lld tt = max(D[0][t], D[1][b]+cost(i));
    lld bb = max(D[1][b], D[0][t]+cost(i));
    D[0][t] = tt;
    D[1][b] = bb;

    ans = max(ans, max(tt, bb));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
