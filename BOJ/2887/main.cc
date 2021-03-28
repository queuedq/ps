#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N, par[MN];

struct Point {
  lld x, y, z, i;
} A[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  par[find(x)] = find(y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld x, y, z; cin >> x >> y >> z;
    A[i] = {x, y, z, i};
    par[i] = i;
  }

  vector<pair<lld, pii>> edge;

  sort(A, A+N, [&](Point a, Point b) { return a.x < b.x; });
  for (int i=0; i<N-1; i++) edge.push_back({A[i+1].x - A[i].x, {A[i].i, A[i+1].i}});
  
  sort(A, A+N, [&](Point a, Point b) { return a.y < b.y; });
  for (int i=0; i<N-1; i++) edge.push_back({A[i+1].y - A[i].y, {A[i].i, A[i+1].i}});
  
  sort(A, A+N, [&](Point a, Point b) { return a.z < b.z; });
  for (int i=0; i<N-1; i++) edge.push_back({A[i+1].z - A[i].z, {A[i].i, A[i+1].i}});

  sort(begin(edge), end(edge));
  lld ans = 0;
  for (int i=0; i<size(edge); i++) {
    auto [a, b] = edge[i].second;
    if (find(a) == find(b)) continue;
    ans += edge[i].first;
    merge(a, b);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
