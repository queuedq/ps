#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, L, W[MN], H[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=1; i<=N; i++) cin >> H[i] >> W[i];

  deque<pll> dq;
  multiset<lld> S;
  lld wsum = 0;

  for (int i=1; i<=N; i++) {
    // insert
    pll last = {i, i};
    while (!dq.empty() && H[dq.back().Y] <= H[i]) {
      pll I = dq.back();
      last = {I.X, i};
      dq.pop_back();
      S.erase(H[I.Y] + D[I.X-1]);
    }
    dq.push_back(last);
    S.insert(H[last.Y] + D[last.X-1]);
    wsum += W[i];

    // delete
    while (!dq.empty() && wsum > L) {
      pll I = dq.front();
      if (I.X == I.Y) {
        dq.pop_front();
        S.erase(H[I.Y] + D[I.X-1]);
      } else {
        pll J = {I.X+1, I.Y};
        dq.front() = J;
        S.erase(H[I.Y] + D[I.X-1]);
        S.insert(H[J.Y] + D[J.X-1]);
      }
      wsum -= W[I.X];
    }

    D[i] = *S.begin();
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
