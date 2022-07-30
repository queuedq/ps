#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 305, INF = 1e9;
int N, D[MN*MN];

struct Parens {
  int dx, low, len;
  bool operator <(const Parens &P) const {
    if (dx >= 0 && P.dx >= 0) { return -low < -P.low; }
    if (dx < 0 && P.dx < 0) { return dx-low > P.dx-P.low; }
    return dx >= 0;
  }
} P[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    string S; cin >> S;
    int dx = 0, low = 0;
    for (int j=0; j<S.size(); j++) {
      dx += (S[j] == '(') ? 1 : -1;
      low = min(low, dx);
    }
    P[i] = {dx, low, sz(S)};
  }

  sort(P+1, P+N+1);

  fill(D+1, D+N*300+1, -INF);
  for (int i=1; i<=N; i++) {
    auto [dx, low, len] = P[i];

    if (dx >= 0) {
      for (int j=N*300-dx; j>=-low; j--)
        D[j+dx] = max(D[j+dx], D[j] + len);
    } else {
      for (int j=-low; j<=N*300; j++)
        D[j+dx] = max(D[j+dx], D[j] + len);
    }
  }

  cout << D[0] << endl;

  ////////////////////////////////
  return 0;
}
