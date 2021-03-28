#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXW = 10005;
int D[2][MAXW];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, M; cin >> N >> M;
  for (int i=0; i<N; i++) {
    int V, C, K; cin >> V >> C >> K;

    for (int r=0; r<V; r++) {
      deque<pii> dq;
      
      for (int j=0; j*V+r <= M; j++) {
        int w = j*V+r, c = j*C;
        int d = D[~i&1][w] - c;

        while (!dq.empty() && dq.back().first < d) dq.pop_back();
        while (!dq.empty() && dq.front().second < j-K) dq.pop_front();
        
        dq.push_back({d, j});
        D[i&1][w] = dq.front().first + c;
      }
    }
  }

  int ans = 0;
  for (int i=0; i<=M; i++) ans = max(ans, D[~N&1][i]);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
