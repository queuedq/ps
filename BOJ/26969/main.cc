#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N, A, B, D[MN][MN], E[MN][MN];

struct Friend {
  int p, c, x;
  bool operator<(Friend F) const { return x > F.x; }
};
Friend F[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> A >> B;
  for (int i=1; i<=N; i++) {
    cin >> F[i].p >> F[i].c >> F[i].x;
  }
  sort(F+1, F+N+1);

  for (int i=1; i<=N; i++) { // prefix: mooney
    auto [p, c, x] = F[i];
    for (int w=0; w<=A; w++) {
      D[i][w] = D[i-1][w];
      if (w >= c) D[i][w] = max(D[i][w], D[i-1][w-c] + p);
    }
  }

  for (int i=N; i>=1; i--) { // suffix: ice cream cone
    auto [p, c, x] = F[i];
    for (int w=0; w<=B; w++) {
      E[i][w] = E[i+1][w];
      if (w >= c*x) E[i][w] = max(E[i][w], E[i+1][w-c*x] + p);
    }
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    auto [p, c, x] = F[i];
    for (int t=0; t<=c; t++) {
      int a = t, b = (c-t) * x;
      if (a <= A && b <= B) ans = max(ans, D[i-1][A-a] + p + E[i+1][B-b]);
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
