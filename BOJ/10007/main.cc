#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, N, cnt[1010101], L[1010101], D[1010101], E[1010101];

struct Point {
  lld x, y;
  bool operator <(const Point &P) const { return y * P.x < P.y * x; }
  bool operator ==(const Point &P) const { return y * P.x == P.y * x; }
  bool operator <=(const Point &P) const { return y * P.x <= P.y * x; }
};

struct Line {
  Point P, Q;
  bool operator <(const Line &L) const { return Q < L.Q; }
};
vector<Line> lines;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K >> N;
  vector<Point> ps;
  for (int i=0; i<N; i++) {
    Point P, Q;
    cin >> P.x >> P.y >> Q.x >> Q.y;
    if (Q < P) swap(P, Q);
    ps.push_back(P);
    ps.push_back(Q);
    lines.push_back({P, Q});
  }
  sort(ps.begin(), ps.end());
  ps.erase(unique(ps.begin(), ps.end()), ps.end());
  sort(lines.begin(), lines.end());
  int M = ps.size();

  priority_queue<int> pq;
  L[M] = INT_MAX;
  for (int i=M-1, j=N-1; i>=0; i--) {
    L[i] = L[i+1];
    while (!pq.empty() && pq.top() > i) pq.pop();
    while (j >= 0 && ps[i] <= lines[j].Q) {
      int p = lower_bound(ps.begin(), ps.end(), lines[j].P) - ps.begin();
      pq.push(p);
      L[i] = min(L[i], p);
      j--;
    }
    cnt[i] = pq.size();
  }
  
  for (int k=0; k<K; k++) {
    for (int i=0; i<M; i++) D[i] = E[L[i]] + cnt[i];
    for (int i=1; i<=M; i++) E[i] = max(E[i-1], D[i-1]);
  }

  cout << E[M] << endl;

  ////////////////////////////////
  return 0;
}
