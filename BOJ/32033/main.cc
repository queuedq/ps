#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e12;
lld N, t, offset;
map<lld, lld> S; // S[x] = k: group of length t-k starting at x-offset
priority_queue<pll, vector<pll>, greater<pll>> pq; // (d, x): dist of group x and next(x) is d-t

lld length(lld x) { return t - S[x]; }

lld dist(lld x) {
  auto it = S.lower_bound(x);
  if (next(it) == S.end()) return INF;
  return next(it)->first - x - (t-S[x]);
}

bool contained(lld x) {
  auto it = S.upper_bound(x);
  if (it == S.begin()) return 0;
  lld y = prev(it)->first;
  return x < y + length(y);
}

void merge(lld x) {
  auto it = S.lower_bound(x);
  if (dist(x) == 0) {
    lld len = length(next(it)->first);
    S.erase(next(it));
    S[x] -= len;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;

  S[0] = -1;
  lld ans = 1;

  for (int q=0; q<N; q++) {
    char type; cin >> type;
    if (type == 'L') {
      offset++;
      t++;
      ans += S.size();

    } else if (type == 'R') {
      t++;
      ans += S.size();

    } else if (type == 'C') {
      lld x; cin >> x;
      x += offset;
      if (contained(x)) continue;

      S[x] = t-1;
      auto it = S.lower_bound(x);
      if (next(it) != S.end()) pq.push({dist(x) + t, x});
      if (it != S.begin()) {
        lld y = prev(it)->first;
        pq.push({dist(y) + t, y});
      }
      ans++;

    } else if (type == 'Q') {
      cout << ans << endl;
    }

    while (!pq.empty() && pq.top().first - t == 0) {
      auto [d, x] = pq.top(); pq.pop();
      if (S.count(x) && dist(x) == 0) {
        merge(x);
        if (dist(x) < INF) pq.push({dist(x) + t, x});
      }
    }

    // cout << q << ": ";
    // for (auto [x, k]: S) cout << "[" << x-offset << "," << x-offset + t-k - 1 << "] ";
    // cout << endl;
  }

  ////////////////////////////////
  return 0;
}
