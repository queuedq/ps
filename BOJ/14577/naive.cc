#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, M, S[MN], tmp[MN];
vector<lld> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> S[i];

  for (int _=0; _<M; _++) {
    lld q, i, x, l, r, t; cin >> q;
    if (q <= 2) {
      cin >> i >> x;
      if (q == 2) x = -x;
      S[i] += x;
    }
    if (q == 3) {
      cin >> l >> r;
      int cnt = 0;
      for (int j=1; j<=N; j++) {
        if (l <= S[j] && S[j] <= r) cnt++;
      }
      ans.push_back(cnt);
    }
    if (q == 4) {
      cin >> t;
      copy(S, S+N+1, tmp);
      sort(tmp+1, tmp+N+1);
      ans.push_back(tmp[t]);
    }
  }

  for (auto a: ans) cout << a << endl;

  ////////////////////////////////
  return 0;
}
