#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 3005, MAX_M = 3005;
int N, M, S, E, T;
int A[MAX_N][MAX_M], ban[MAX_N], ASum[MAX_N][MAX_M];
deque<pii> movable[MAX_N], stay[MAX_N];

void input() {
  cin >> N >> M >> S >> E >> T;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    cin >> ban[i];
  }

  // Calc ASum
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      ASum[i][j] = ASum[i][j-1] + A[i][j];
    }
  }
}

int nowCost(pii p, int i, int now) {
  return p.first + ASum[i][now] - ASum[i][p.second];
}

void calc() {
  // Calc
  for (int now = 1; now <= M; now++) {
    vector<pii> costs;
    if (now == 1) {
      for (int i = 1; i <= N; i++) costs.push_back({0, i});
    } else {
      for (int i = 1; i <= N; i++) {
        if (movable[i].size() == 0) continue;
        int cost = nowCost(movable[i].front(), i, now-1);
        costs.push_back({cost, i});
      }
      sort(costs.begin(), costs.end());
    }

    for (int i = 1; i <= N; i++) {
      // Move from another institue
      if (costs.size() > 0) {
        assert(costs.size() == N);
        int k = 0;
        while (costs[k].second == i || costs[k].second == ban[i]) k++;
        stay[i].push_back({costs[k].first + (now > 1 ? T : 0) + A[i][now], now});
      }

      // Stay
      if (stay[i].size() > 0) {
        pii ready = stay[i].front();
        if (now - ready.second + 1 >= S) {
          stay[i].pop_front();
          while (movable[i].size() > 0) {
            if (nowCost(movable[i].back(), i, now) > nowCost(ready, i, now)) movable[i].pop_back();
            else break;
          }
          movable[i].push_back(ready);
        }
      }

      // Remove movables
      while (movable[i].size() > 0) {
        if (now - movable[i].front().second + 1 > E) movable[i].pop_front();
        else break;
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 1; i <= N; i++) {
    int cost = INT_MAX;
    for (auto s: stay[i]) cost = min(cost, nowCost(s, i, M));
    if (movable[i].size() > 0) cost = min(cost, nowCost(movable[i].front(), i, M));
    ans = min(ans, cost);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  calc();

  ////////////////////////////////
  return 0;
}
