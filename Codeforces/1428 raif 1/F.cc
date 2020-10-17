#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e5+5;
lld N, A[MAXN], len[MAXN], itv[MAXN], lft[MAXN];
vector<lld> lenidx[MAXN];
vector<pll> B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string input;
  cin >> N >> input;

  for (int i=1; i<=N; i++) {
    A[i] = input[i-1] - '0';
    len[i] = A[i] ? len[i-1]+1 : 0;
    B.push_back({-len[i], i});
    lenidx[len[i]].push_back(i);
  }

  sort(B.begin(), B.end());

  set<int> S = {0};
  for (int i=0; i<N; i++) {
    auto [a, j] = B[i];
    lft[j] = *prev(S.lower_bound(j));
    S.insert(j);
  }

  lld rsum = 0;
  for (int l=N; l>=1; l--) {
    itv[l] = rsum;
    for (auto i: lenidx[l]) {
      itv[l] += (lft[i] == 0 ? i-l+1 : i-lft[i]) * (N-i+1);
      rsum += N-i+1;
    }
  }

  lld ans = 0;
  for (int l=1; l<=N; l++) {
    ans += l * (itv[l] - itv[l+1]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
