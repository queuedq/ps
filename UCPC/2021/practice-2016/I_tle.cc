#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5005;
const int ST = 1<<14;
int N;
vector<int> xs, ys;

struct Poster { int x1, y1, x2, y2; };
Poster P[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> P[i].x1 >> P[i].y1 >> P[i].x2 >> P[i].y2;
    xs.push_back(P[i].x1);
    xs.push_back(P[i].x2);
    ys.push_back(P[i].y1);
    ys.push_back(P[i].y2);
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  for (int i=1; i<=N; i++) {
    P[i].x1 = lower_bound(xs.begin(), xs.end(), P[i].x1) - xs.begin();
    P[i].x2 = lower_bound(xs.begin(), xs.end(), P[i].x2) - xs.begin();
    P[i].y1 = lower_bound(ys.begin(), ys.end(), P[i].y1) - ys.begin();
    P[i].y2 = lower_bound(ys.begin(), ys.end(), P[i].y2) - ys.begin();
  }

  ////////////////

  vector<lld> ans(N+1);
  for (int x=0; x<xs.size(); x++) {
    vector<pii> E;
    <int> pq;
    vector<bool> contained(N);

    for (int i=1; i<=N; i++) {
      auto [x1, y1, x2, y2] = P[i];
      if (x1 <= x && x < x2) {
        E.push_back({y1, i});
        E.push_back({y2, -i});
      }
    }
    sort(E.begin(), E.end());

    int y0 = 0;
    for (auto [y, i]: E) {
      while (!pq.empty() && !contained[pq.top()]) pq.pop();

      if (!pq.empty()) {
        int k = pq.top();
        ans[k] += (lld)(xs[x+1] - xs[x]) * (ys[y] - ys[y0]);
      }

      if (i > 0) {
        pq.push(i);
        contained[i] = true;
      } else {
        contained[-i] = false;
      }

      y0 = y;
    }
  }

  for (int i=1; i<=N; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
