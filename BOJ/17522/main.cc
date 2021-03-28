#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9 + 10;
int N;
vector<pii> P;
vector<int> X, lmin, lmax, rmin, rmax;

int compress(int x) {
  return lower_bound(X.begin(), X.end(), x) - X.begin();
}

bool inRange(int d) {
  int i = 0;
  for (int j=0; j<X.size(); j++) {
    while (X[j] - X[i] > d) i++;
    int ymin = min(lmin[i], rmin[j+1]);
    int ymax = max(lmax[i], rmax[j+1]);
    if (ymin + d >= ymax) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    P.push_back({x, y});
    X.push_back(x);
  }

  sort(P.begin(), P.end());
  sort(X.begin(), X.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());

  lmin = vector(X.size()+1, INF);
  lmax = vector(X.size()+1, -INF);
  rmin = vector(X.size()+1, INF);
  rmax = vector(X.size()+1, -INF);

  for (int i=0; i<N; i++) {
    int x = compress(P[i].first)+1;
    lmin[x] = min(min(lmin[x], lmin[x-1]), P[i].second);
    lmax[x] = max(max(lmax[x], lmax[x-1]), P[i].second);
  }

  for (int i=N-1; i>=0; i--) {
    int x = compress(P[i].first);
    rmin[x] = min(min(rmin[x], rmin[x+1]), P[i].second);
    rmax[x] = max(max(rmax[x], rmax[x+1]), P[i].second);
  }

  int l = -1, r = INF * 2;
  while (r-l > 1) {
    int mid = l + (r-l)/2;
    if (inRange(mid)) r = mid;
    else l = mid;
  }

  cout << fixed << setprecision(1) << r / 2. << endl;

  ////////////////////////////////
  return 0;
}
