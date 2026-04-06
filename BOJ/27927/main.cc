#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9+5;
int N, M;

struct Event {
  int t, i, dt;
  bool operator<(const Event &X) const { return t < X.t; }
};
vector<Event> evt;

void add(set<pii> &I, multiset<int> &L, pii itv) {
  auto [l, r] = itv;
  if (l > r) return;
  I.insert(itv);
  L.insert(r-l+1);
}

void remove(set<pii> &I, multiset<int> &L, set<pii>::iterator it) {
  auto [l, r] = *it;
  I.erase(it);
  L.erase(L.find(r-l+1));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    int s, e; cin >> s >> e;
    evt.push_back({s, i, 1});
    evt.push_back({e+1, i, -1});
  }

  sort(all(evt));

  // solve
  set<pii> I;
  I.insert({-1, -1});
  I.insert({N+2, N+2});
  multiset<int> L;
  int pt = 0;
  int max_len = 0, max_cnt = 0;

  for (auto [t, i, dt]: evt) {
    // update max interval
    if (pt < t) {
      if (!L.empty()) {
        int len = *L.rbegin();
        if (len == max_len) max_cnt += t - pt;
        else if (len > max_len) max_len = len, max_cnt = t - pt;
      }
      pt = t;
    }

    // process events
    if (dt == 1) { // add
      int l = i, r = i;
      auto nit = I.lower_bound({i, INF});
      auto pit = prev(nit);

      // merge with prev/next
      if (pit->second == i-1) l = pit->first, remove(I, L, pit);
      if (nit->first == i+1) r = nit->second, remove(I, L, nit);
      add(I, L, {l, r});

    } else { // remove
      auto it = I.lower_bound({i, INF});
      it = prev(it);
      assert(it->first <= i && i <= it->second);

      // split into two
      int l1 = it->first, r1 = i-1;
      int l2 = i+1, r2 = it->second;
      remove(I, L, it);
      add(I, L, {l1, r1});
      add(I, L, {l2, r2});
    }
  }

  cout << max_len << " " << max_cnt << endl;

  ////////////////////////////////
  return 0;
}
