#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N, M;
char A[MN][MN];
vector<pair<int, char>> color;
bool flip;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  int R, G, B; cin >> R >> G >> B;
  color = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
  sort(all(color));
  swap(color[0], color[2]);
  swap(color[1], color[2]);
  // cnt: large, small, med

  if (color[0].first > (N*M + 1) / 2) return cout << "NO" << endl, 0;

  if (N < M) swap(N, M), flip = 1;

  vector<pii> ord;
  for (int i=0; i<N; i++) for (int j=0; j<M; j++) if ((i+j)%2 == 0) ord.push_back({i, j});
  for (int i=0; i<N; i++) for (int j=0; j<M; j++) if ((i+j)%2 == 1) ord.push_back({i, j});

  int i = 0;
  for (auto [cnt, C]: color) {
    while (cnt--) {
      auto [x, y] = ord[i++];
      A[x][y] = C;
    }
  }

  cout << "YES" << endl;
  if (!flip) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) cout << A[i][j];
      cout << endl;
    }
  } else {
    for (int i=0; i<M; i++) {
      for (int j=0; j<N; j++) cout << A[j][i];
      cout << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
