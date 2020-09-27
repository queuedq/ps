#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
using Edge = pair<double, pair<double, double>>;

const int MAXN = 1005;
int n;
double w, x[MAXN], y[MAXN], r[MAXN], dst[MAXN][MAXN];
bool vst[MAXN];
vector<double> edge;

void dfs(int u, int i) {
  vst[u] = true;
  for (int v=0; v<n+2; v++) {
    if (vst[v]) continue;
    if (edge[i] > dst[u][v]) dfs(v, i);
  }
}

double calc() {
  edge.clear();

  cin >> w >> n;
  for (int i=0; i<n; i++) cin >> x[i] >> y[i] >> r[i];

  for (int i=0; i<n+2; i++) {
    for (int j=0; j<i; j++) {
      if (i >= n && j >= n) dst[i][j] = dst[j][i] = w;
      else if (i == n) dst[i][j] = dst[j][i] = max(x[j]-r[j], 0.);
      else if (i == n+1) dst[i][j] = dst[j][i] = max(w-x[j]-r[j], 0.);
      else {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        dst[i][j] = dst[j][i] = max(sqrt(dx*dx + dy*dy) - r[i] - r[j], 0.);
      }
      edge.push_back(dst[i][j]);
    }
  }

  sort(edge.begin(), edge.end());
  edge.resize(unique(edge.begin(), edge.end()) - edge.begin());

  lld l = 0, r = edge.size();
  while (l+1 < r) {
    lld m = (l+r)/2;
    fill(vst, vst+n+2, false);
    dfs(n, m);
    if (vst[n+1]) r = m;
    else l = m;
  }

  return edge[l] / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cout << fixed << setprecision(9) << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
