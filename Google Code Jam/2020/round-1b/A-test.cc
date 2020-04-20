#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int C = 20;
const int N = 40;
int vst[N][N];

struct State {
  int x, y, jump, cnt;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  queue<State> Q;
  Q.push({C, C, 1, 0});

  while (!Q.empty()) {
    auto [x, y, jump, cnt] = Q.front(); Q.pop();
    if (x < 0 || x >= N || y < 0 || y >= N) continue;
    if (vst[x][y] == 0) vst[x][y] = cnt;
    Q.push({x+jump, y, jump*2, cnt+1});
    Q.push({x-jump, y, jump*2, cnt+1});
    Q.push({x, y+jump, jump*2, cnt+1});
    Q.push({x, y-jump, jump*2, cnt+1});
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << vst[j][i];
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
