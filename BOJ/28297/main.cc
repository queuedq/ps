#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
const double PI = acos(-1);
int N, par[MN];
double x[MN], y[MN], r[MN];

struct Edge {
  int i, j; double w;
  bool operator <(Edge E) const { return w < E.w; }
};
vector<Edge> E;

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> x[i] >> y[i] >> r[i];
  for (int i=0; i<N; i++) par[i] = i;

  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      double dx = x[j]-x[i];
      double dy = y[j]-y[i];
      double dr = r[j]-r[i];
      
      double d = sqrt(dx*dx + dy*dy);
      if (d <= r[i]+r[j]) E.push_back({i, j, 0});
      else {
        double l = sqrt(d*d - dr*dr);
        double th = asin(dr/d);
        double sum = (PI - th*2) * r[i] + (PI + th*2) * r[j] + l*2;
        E.push_back({i, j, sum});
      }
    }
  }

  sort(all(E));

  double ans = 0;
  for (auto [i, j, w]: E) {
    i = find(i), j = find(j);
    if (i == j) continue;
    par[j] = i;
    ans += w;
  }

  cout << setprecision(10) << ans << endl;

  ////////////////////////////////
  return 0;
}
