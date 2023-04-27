#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
pll P[MAXN];

lld dist(pll a, pll b) {
  lld x = a.first - b.first, y = a.second - b.second;
  return x*x + y*y;
}

pll reverse(pll a) {
  return {a.second, a.first};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> P[i].first >> P[i].second;
  }

  sort(P, P+N);

  int j = 0;
  lld best = INT_MAX;
  set<pii> cand;
  for (int i=0; i<N; i++) {
    while (P[i].first - P[j].first > sqrt(best)) {
      cand.erase(reverse(P[j]));
      j++;
    }

    if (!cand.empty()) {
      auto it = cand.lower_bound({P[i].second-sqrt(best)-1, INT_MIN});
      while (it != cand.end() && it->first <= P[i].second+sqrt(best)+1) {
        lld d = dist(P[i], reverse(*it));
        if (d < best) best = d;
        it++;
      }
    }

    cand.insert(reverse(P[i]));
  }

  cout << best << endl;

  ////////////////////////////////
  return 0;
}
