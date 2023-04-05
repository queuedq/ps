#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, K, A[MN];

struct Event {
  lld a, i;
  bool operator <(const Event &E) const { return a < E.a; }
};

void solve(int t) {
  cin >> N >> K;
  vector<Event> E = {{K, 0}};
  for (int i=0; i<N; i++) {
    cin >> A[i];
    if (A[i] < K) E.push_back({A[i], i});
  }
  sort(all(E));

  lld a = E[0].a, l = E[0].i, r = E[0].i, cnt = 0, cost = 0;
  for (int i=1; i<sz(E); i++) {
    cnt += E[i].a - a;
    cost += (E[i].a - a) * (r-l+1);
    a = E[i].a, l = min(l, E[i].i), r = max(r, E[i].i);
  }

  cout << "Case #" << t << endl;
  cout << cnt << " " << cost << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
