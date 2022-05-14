#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
const int O = MN/2;
lld N, K, A[MN][MN];
vector<pii> ans;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve(int N, int K) {
  if (K < N-1 || K%2 != 0) return;
  if (K-(N-1)*4 >= N-3) return solve(N-2, K-(N-1)*4);

  int x=O-N/2, y=O, d=0;
  for (K-=N-1; K>0; K-=2) {
    int xx = x+dx[d], yy = y+dy[d];
    if (xx < O-N/2 || xx > O+N/2 || yy < O-N/2 || yy > O+N/2) {
      d = (d+1)%4;
      xx = x+dx[d]*(N/2+1), yy = y+dy[d]*(N/2+1);
    }
    x = xx, y = yy;
  }

  d = (d+1)%4;
  for (int i=0; i<N/2; i++) {
    int xx = x+dx[d], yy = y+dy[d];
    if (A[x][y] - A[xx][yy] > 1) ans.push_back({A[x][y], A[xx][yy]});
    x = xx, y = yy;
  }
  d = (d+1)%4;
  while (!(x==O && y==O)) {
    int xx = x+dx[d], yy = y+dy[d];
    if (A[x][y] - A[xx][yy] > 1) ans.push_back({A[x][y], A[xx][yy]});
    x = xx, y = yy;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int x=O-9999/2, y=O-9999/2, d=0;
  for (int i=9999*9999; i>=1; i--) {
    A[x][y] = i;
    int xx = x+dx[d], yy = y+dy[d];
    if (xx < O-9999/2 || xx > O+9999/2 || yy < O-9999/2 || yy > O+9999/2 || A[xx][yy]) {
      d = (d+1)%4;
      xx = x+dx[d], yy = y+dy[d];
    }
    x = xx, y = yy;
  }

  // int N = 9;
  // for (int i=0; i<N; i++) {
  //   for (int j=0; j<N; j++) {
  //     cout << std::setfill(' ') << std::setw(2) << A[O-N/2+i][O-N/2+j] << " ";
  //   }
  //   cout << endl;
  // }

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    ans.clear();
    cin >> N >> K;
    solve(N, K);
    if (ans.size() == 0) {
      cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << t << ": " << ans.size() << endl;
      for (auto [a, b]: ans) cout << (N*N+1-a) << " " << (N*N+1-b) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
