#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
const lld INF = 1e18;
lld N, P, A[MN], D[MN];

struct Info {
  lld l, r, h, val;
  // val = D[l-1] + h - l (cost = h + i-l, so i will be added later)
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> P;
  for (int i=1; i<=N; i++) cin >> A[i];

  deque<Info> dq;
  multiset<lld> S;
  for (int i=1; i<=N; i++) {
    // push
    int L = i;
    while (!dq.empty() && dq.back().h <= A[i]) {
      auto [l, r, h, val] = dq.back();
      S.erase(S.find(val));
      dq.pop_back();
      L = l;
    }
    dq.push_back({L, i, A[i], D[L-1] + A[i] - L});
    S.insert(D[L-1] + A[i] - L);

    // pop
    while (!dq.empty()) {
      auto &[l, r, h, val] = dq.front();
      if (h + i-l > P) l = h + i - P; // cost = h + i-l should be <= P
      if (l <= r) { // update val
        S.erase(S.find(val));
        S.insert(val = D[l-1] + h - l);
        break;
      }
      S.erase(S.find(val));
      dq.pop_front();
    }

    // dp
    D[i] = *S.begin() + i;
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
