#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
const int MQ = 101010;
const lld INF = 2e18;
lld N, M, C, Q, A[MN][MN], idx[MN];
pll P[MQ];
lld ans[MQ];

struct Event {
  lld t, x, v;
  bool operator <(Event E) const { return pll(x, t) < pll(E.x, E.t); }
};
vector<Event> E1, E2;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> C;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cin >> A[i][j];
    sort(A[i], A[i]+M);
  }
  cin >> Q;
  for (int i=0; i<Q; i++) cin >> P[i].first, P[i].second = i;
  sort(P, P+Q);
  
  // init
  set<pll> S;
  lld sum = 0;
  for (int i=0; i<N; i++) {
    idx[i] = M-1;
    S.insert({A[i][M-1], i});
    sum += A[i][M-1];
  }

  // roll
  while (1) {
    lld x = S.begin()->first;
    lld y = next(S.begin())->first;
    lld z = prev(S.end())->first;

    lld user = min(C, z-x); // min event user (in greedy manner)
    lld diff = z - min(x+C, y); // base diff

    // for P: sum + user < P <= sum + C
    //   cost = diff + (P - sum - user)
    E1.push_back({1, sum+user, diff-sum-user});
    E1.push_back({2, sum+C, diff-sum-user});

    // for P: P <= sum + user
    //   cost = diff
    E2.push_back({1, -1, diff});
    E2.push_back({2, sum+user, diff});

    // cout << x << " " << y << " " << z << " " << sum << endl;
    // cout << "E1: " << sum+user << " " << sum+C << ": " << diff-sum-user << endl;
    // cout << "E2: " << -1 << " " << sum+user << ": " << diff << endl;

    // update set
    auto it = prev(S.end());
    int i = it->second;
    if (idx[i] == 0) break;
    idx[i]--;
    S.erase(it);
    S.insert({A[i][idx[i]], i});
    sum += A[i][idx[i]] - z;
  }
  
  // range mins
  sort(all(E1));
  sort(all(E2));

  multiset<lld> S1, S2;
  int k1 = 0, k2 = 0;
  for (int i=0; i<Q; i++) {
    auto [p, q] = P[i];
    while (k1 < sz(E1) && E1[k1].x < p) {
      auto [t, x, v] = E1[k1];
      if (t == 1) S1.insert(v);
      else S1.erase(S1.find(v));
      k1++;
    }
    while (k2 < sz(E2) && E2[k2].x < p) {
      auto [t, x, v] = E2[k2];
      if (t == 1) S2.insert(v);
      else S2.erase(S2.find(v));
      k2++;
    }

    ans[q] = INF;
    if (!S1.empty()) ans[q] = min(ans[q], *S1.begin() + p);
    if (!S2.empty()) ans[q] = min(ans[q], *S2.begin());
  }

  for (int q=0; q<Q; q++) cout << (ans[q] == INF ? -1 : ans[q]) << endl;

  ////////////////////////////////
  return 0;
}
