#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct disjoint_set {
  vector<int> p, s;

  disjoint_set(int sz) {
    p.resize(sz); s.resize(sz);
    for (int i = 0; i < sz; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x;
    s[x] += s[y];
  }
};

////////////////////////////////////////////////////////////////
lld M, D;

struct Event {
  lld z, w, i; bool insert;
  bool operator<(const Event &e) const {
    return pll(z, !insert) < pll(e.z, !e.insert);
  }
};
vector<Event> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> D;
  for (int i=1; i<=M; i++) {
    lld x, y; cin >> x >> y;
    E.push_back({x+y, x-y, i, true});
    E.push_back({x+y+D, x-y, i, false});
  }

  sort(E.begin(), E.end());

  disjoint_set dsu(M+1);
  set<pll> line;

  for (auto [z, w, i, insert]: E) {
    if (insert) {
      auto it = line.lower_bound({w, i});
      if (it != line.end() && it->first <= w + D) {
        dsu.merge(i, it->second);
      }
      if (it != line.begin() && prev(it)->first >= w - D) {
        dsu.merge(i, prev(it)->second);
      }
      line.insert({w, i});
    } else {
      line.erase({w, i});
    }
  }

  int sz = 0, cnt = 0;
  for (int i=1; i<=M; i++) {
    if (dsu.p[i] == i) {
      sz = max(sz, dsu.s[i]);
      cnt++;
    }
  }

  cout << cnt << " " << sz << endl;

  ////////////////////////////////
  return 0;
}
