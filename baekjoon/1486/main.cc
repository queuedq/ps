#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point {
  int x, y;
  bool operator <(Point p) const { return pii(x, y) < pii(p.x, p.y); }
};

const int INF = 1e9;
const int MAXN = 30;
int N, M, T, D, H[MAXN][MAXN];
int D1[MAXN][MAXN], D2[MAXN][MAXN];
bool vst[MAXN][MAXN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

Point move(Point p, int d) { return {p.x + dx[d], p.y + dy[d]}; }
bool oob(Point p) { return p.x < 0 || p.x >= N || p.y < 0 || p.y >= M; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> T >> D;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (int j=0; j<M; j++) {
      H[i][j] = s[j];
      if ('A' <= H[i][j] && H[i][j] <= 'Z') H[i][j] -= 'A';
      else H[i][j] = H[i][j] - 'a' + 26;

      D1[i][j] = INF;
      D2[i][j] = INF;
    }
  }

  priority_queue<pair<int, Point>, vector<pair<int, Point> >, greater<pair<int, Point> > > pq;
  pq.push({0, {0, 0}});
  while (!pq.empty()) {
    auto [t, p] = pq.top(); pq.pop();
    if (vst[p.x][p.y]) continue;
    vst[p.x][p.y] = true;
    D1[p.x][p.y] = t;

    int h = H[p.x][p.y];
    for (int d=0; d<4; d++) {
      Point q = move(p, d);
      if (oob(q)) continue;

      int hh = H[q.x][q.y], tt = t;
      if (abs(hh - h) > T) continue;
      if (hh <= h) tt++;
      else tt += (hh-h) * (hh-h);

      pq.push({tt, q});
    }
  }

  for (int i=0; i<N; i++) fill(vst[i], vst[i]+M, false);
  pq.push({0, {0, 0}});
  while (!pq.empty()) {
    auto [t, p] = pq.top(); pq.pop();
    if (vst[p.x][p.y]) continue;
    vst[p.x][p.y] = true;
    D2[p.x][p.y] = t;

    int h = H[p.x][p.y];
    for (int d=0; d<4; d++) {
      Point q = move(p, d);
      if (oob(q)) continue;

      int hh = H[q.x][q.y], tt = t;
      if (abs(hh - h) > T) continue;
      if (hh >= h) tt++;
      else tt += (hh-h) * (hh-h);

      pq.push({tt, q});
    }
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (D1[i][j] + D2[i][j] <= D) ans = max(ans, H[i][j]);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
