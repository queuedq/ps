#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int O = 1010;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int N, vcnt;
int vst[O*3][O*3], cnt[O*3][O*3];

void visit(int x, int y) {
  if (vst[O+x][O+y]) return;
  vst[O+x][O+y] = 1;
  vcnt++;
  for (int d=0; d<4; d++) {
    int nx = x + dx[d], ny = y + dy[d];
    cnt[O+nx][O+ny]++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;

  for (int i=1; i<=N; i++) {
    int x, y; cin >> x >> y;

    queue<pii> Q;
    visit(x, y);
    Q.push({x, y});

    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();
      
      // find comfortable cows
      for (int d=0; d<4; d++) {
        int nx = x+dx[d], ny = y+dy[d];
        if (vst[O+nx][O+ny] && cnt[O+nx][O+ny] == 3) Q.push({nx, ny});
      }

      // make uncomfortable
      if (cnt[O+x][O+y] == 3) {
        for (int d=0; d<4; d++) {
          int nx = x+dx[d], ny = y+dy[d];
          visit(nx, ny);
          Q.push({nx, ny});
        }
      }
    }

    cout << vcnt - i << endl;
  }

  ////////////////////////////////
  return 0;
}
