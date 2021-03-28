#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
lld N, M, a, b;
pll X[MAXN], Y[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> X[i].first >> X[i].second;
  cin >> M;
  for (int i=0; i<M; i++) cin >> Y[i].first >> Y[i].second;
  cin >> a >> b;

  lld l = 0, r = -1, sum = 0, ans = 0;
  for (int i=0; i<N; i++) {
    while (r < M && Y[r+1].first <= X[i].first+b) {
      r++;
      sum += Y[r].second;
    }
    while (l < M && Y[l].first < X[i].first+a) {
      sum -= Y[l].second;
      l++;
    }
    ans += sum * X[i].second;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
