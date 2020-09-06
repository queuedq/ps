#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using plll = pair<lld, pair<lld, lld>>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
lld N, K, Q, A[MAXN], S[MAXN], upd[MAXN];

void solve() {
  cin >> N >> K >> Q;
  for (int i=1; i<=N; i++) cin >> A[i];

  priority_queue<plll> L; // sum, idx, query
  priority_queue<plll, vector<plll>, greater<plll>> R;
  lld l = 0, r = 0, sum = 0;

  for (int i=1; i<=K; i++) sum += A[i];
  S[1] = sum; upd[1] = 0;
  L.push({sum, {1, 0}}); l++;

  for (int i=K+1; i<=N; i++) {
    sum += A[i] - A[i-K];
    S[i-K+1] = sum; upd[i-K+1] = 0;
    L.push({sum, {i-K+1, 0}}); l++;
  }

  while (l > r) {
    R.push(L.top()); r++;
    L.pop(); l--;
  }

  plll mid = R.top();
  cout << mid.first << " ";

  for (int q=1; q<=Q; q++) {
    lld i, a; cin >> i >> a;
    for (int j = max(1LL, i-K+1); j <= min(N-K+1, i); j++) {
      if (plll(S[j], {j, upd[j]}) >= mid) r--;
      else l--;

      S[j] += a - A[i]; upd[j] = q;

      if (plll(S[j], {j, q}) >= mid) {
        R.push({S[j], {j, q}}); r++;
      } else {
        L.push({S[j], {j, q}}); l++;
      }
    }

    while (l+1 < r) {
      auto [s, meta] = R.top();
      auto [j, u] = meta;
      if (upd[j] != u) { R.pop(); continue; }

      L.push(R.top()); l++;
      R.pop(); r--;
    }

    while (l > r) {
      auto [s, meta] = L.top();
      auto [j, u] = meta;
      if (upd[j] != u) { L.pop(); continue; }

      R.push(L.top()); r++;
      L.pop(); l--;
    }

    assert(l == r || l+1 == r);
    assert(l >= 0 && r >= 1);
    assert(l + r == N-K+1);

    while (true) {
      auto [s, meta] = R.top();
      auto [j, u] = meta;
      if (upd[j] != u) R.pop();
      else break;
    }

    mid = R.top();
    if (q < Q) cout << mid.first << " ";
    else cout << mid.first << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << endl;
    solve();
  }

  ////////////////////////////////
  return 0;
}
