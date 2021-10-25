#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 1e4+5;
const int INF = 1e9;
int N, M, N1, N2;
vector<pii> A[2], B[2], R[2][_N];
int cnt[2][_N], ans[_N];
int D[_N][_N][2], E[_N][_N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    char d; int x; cin >> d >> x;
    if (d == 'U') A[0].push_back({x, i});
    else A[1].push_back({x, i});
  }
  for (int i=1; i<=M; i++) {
    char d; int x; cin >> d >> x;
    if (d == 'U') B[0].push_back({x, i});
    else B[1].push_back({x, i});
  }
  
  A[0].push_back({0, 0}); A[1].push_back({0, 0});
  sort(all(A[0])); sort(all(A[1]));
  sort(all(B[0])); sort(all(B[1]));
  int N1 = (int)A[0].size()-1, N2 = (int)A[1].size()-1;

  for (int k: {0, 1}) {
    int i = 0, j = 0;
    auto &a = A[k], &b = B[k];
    for (; i < (int)a.size()-1; i++) {
      for (; j < b.size() && b[j] < a[i+1]; j++) R[k][i].push_back(b[j]);
      cnt[k][i] = R[k][i].size();
    }
    for (; j < b.size(); j++) R[k][i].push_back(b[j]);
    cnt[k][i] = R[k][i].size();
  }

  // DP
  for (int i=0; i<=N1; i++) {
    for (int j=0; j<=N2; j++) {
      D[i][j][0] = D[i][j][1] = (i == 0 && j == 0) ? 0 : INF;
      if (i > 0) { D[i][j][1] = (D[i-1][j][0] <= cnt[0][i-1]) ? 1 : (D[i-1][j][1] + 1); }
      if (j > 0) { D[i][j][0] = (D[i][j-1][1] <= cnt[1][j-1]) ? 1 : (D[i][j-1][0] + 1); }
      // cout << i << " " << j << " " << D[i][j][0] << " " << D[i][j][1] << endl;
    }
  }

  if (D[N1][N2][0] > cnt[0][N1] && D[N1][N2][1] > cnt[1][N2]) {
    return cout << -1 << endl, 0;
  }

  // traceback
  int i=N1, j=N2, d=1; // d: which direction to match from
  while (i > 0 || j > 0) {
    if (D[i][j][0] <= cnt[0][i] && d != 0) {
      ans[A[1][j].Y] = R[0][i][D[i][j][0]-1].Y;
      if (D[i][j][0] == 1) d = 0; // no B left in R[0][i]
      j--;
    } else {
      ans[A[0][i].Y] = R[1][j][D[i][j][1]-1].Y;
      if (D[i][j][1] == 1) d = 1; // no B left in R[1][j]
      i--;
    }
  }

  for (int i=1; i<=N; i++) cout << ans[i] << " ";

  ////////////////////////////////
  return 0;
}
