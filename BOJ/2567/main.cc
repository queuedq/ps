#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool paper[102][102];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    for (int x=a+1; x<=a+10; x++) {
      for (int y=b+1; y<=b+10; y++) paper[x][y] = true;
    }
  }

  int ans = 0;
  for (int x=1; x<=100; x++) {
    for (int y=1; y<=100; y++) {
      if (!paper[x][y]) continue;
      for (int d=0; d<4; d++) {
        if (!paper[x+dx[d]][y+dy[d]]) ans++;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
