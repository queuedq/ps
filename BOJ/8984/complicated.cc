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
vector<int> sticks[2][MAXN*2];
lld D[2][MAXN];

int compress(lld x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

lld cost(int i) {
  return abs(A[i].first-A[i].second) + L;
}

lld dp(int end, int i) {
  if (D[end][i] != -1) return D[end][i];

  D[end][i] = cost(i);
  int t = compress(A[i].first);
  int b = compress(A[i].second);
  int tidx = lower_bound(sticks[0][t].begin(), sticks[0][t].end(), i) - sticks[0][t].begin();
  int bidx = lower_bound(sticks[1][b].begin(), sticks[1][b].end(), i) - sticks[1][b].begin();

  if (end == 0) {
    if (tidx != 0) {
      int tprv = sticks[0][t][tidx-1];
      D[0][i] = max(D[0][i], D[0][tprv]);
    }
    if (bidx != 0) {
      int bprv = sticks[1][b][bidx-1];
      D[0][i] = max(D[0][i], dp(1, bprv) + cost(i));
    }
  } else {
    if (bidx != 0) {
      int bprv = sticks[1][b][bidx-1];
      D[1][i] = max(D[1][i], D[1][bprv]);
    }
    if (tidx != 0) {
      int tprv = sticks[0][t][tidx-1];
      D[1][i] = max(D[1][i], dp(0, tprv) + cost(i));
    }
  }

  return D[end][i];
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

  for (int i=0; i<N; i++) {
    int t = compress(A[i].first);
    int b = compress(A[i].second);
    sticks[0][t].push_back(i);
    sticks[1][b].push_back(i);
  }

  ////////

  fill(D[0], D[0]+N, -1);
  fill(D[1], D[1]+N, -1);

  lld ans = -1;
  for (int i=0; i<N; i++) {
    ans = max(ans, dp(0, i));
    ans = max(ans, dp(1, i));
  }

  cout << ans << endl;

  // for (int i=0; i<N; i++) {
  //   cout<<"stick "<<i<<": "<<A[i].first<<" "<<A[i].second<<" "<<cost(i)<<endl;
  //   cout<<"dp    "<<i<<": "<<D[0][i]<<" "<<D[1][i]<<endl;
  // }

  ////////////////////////////////
  return 0;
}
