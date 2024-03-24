#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MN = 1030;

struct Robot { int r, c, d; };

ostream& operator<<(ostream &os, const Robot &R) {
  return os << "{" << R.r << ", " << R.c << ", " << R.d << "}";
}

Robot R;
int H, W;
int A[MN][MN], B[MN][MN];
int vst[MN][MN], par[MN*MN*4], dst[MN*MN*4];

bool oob(int r, int c) {
  return r < 0 || r >= H || c < 0 || c >= W;
}

int to_int(Robot R) {
  if (oob(R.r, R.c)) return H * W * 4;
  return (R.r * W + R.c) * 4 + R.d;
}

Robot to_robot(int x) {
  int d = x % 4; x /= 4;
  int c = x % W; x /= W;
  int r = x;
  return {r, c, d};
}

int find(int x) {
  if (par[x] == x) return x; 
  int y = find(par[x]);
  dst[x] += dst[par[x]];
  return par[x] = y;
}

Robot get_next(Robot R, int rule[MN][MN]) {
  auto [r, c, d] = R;
  d = (d + rule[r][c]) % 4;
  r += dr[d], c += dc[d];
  return {r, c, d};
}

void input_rule(int arr[MN][MN]) {
  for (int i=0; i<H; i++) {
    string S; cin >> S;
    for (int j=0; j<W; j++) arr[i][j] = S[j] - '0';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> H >> W >> R.r >> R.c >> R.d;
  input_rule(A);
  input_rule(B);

  for (int i=0; i<=H*W*4; i++) par[i] = i;

  lld ans = 0;
  while (1) {
    if (!vst[R.r][R.c]) {
      vst[R.r][R.c] = 1;

      for (int d=0; d<4; d++) { // connect next
        int x = to_int({R.r, R.c, d});
        int y = to_int(get_next({R.r, R.c, d}, B));
        if (find(y) != x) par[x] = y, dst[x] = 1;
      }

      R = get_next(R, A);
      ans++;
      if (oob(R.r, R.c)) break;

    } else {
      Robot S = to_robot(find(to_int(R)));
      if (oob(S.r, S.c) || vst[S.r][S.c]) break; // no more cleaning

      ans += dst[to_int(R)];
      R = S;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
