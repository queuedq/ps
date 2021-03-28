#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
const int MAXX = 1e5+5;
int N, K;

struct Pos {
  int x, y, f, i;
  bool operator <(Pos p) const { return x == p.x ? y < p.y : x < p.x; }
} A[MAXN];
pii start;

int Dx[MAXX], Dy[MAXX], Ex[MAXX], Ey[MAXX];
int prv[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    int x, y, f; cin >> x >> y >> f;
    A[i] = {x, y, f, i+1};
  }
  sort(A, A+N);

  int p; int score;
  for (int i=0; i<N; i++) {
    auto [x, y, f, idx] = A[i];
    int D = idx == 1 ? f : -1;

    if (Dx[y] >= K && Dx[y] - K + f > D) {
      D = Dx[y] - K + f;
      prv[i] = Ex[y];
    }

    if (Dy[x] >= K && Dy[x] - K + f > D) {
      D = Dy[x] - K + f;
      prv[i] = Ey[x];
    }

    if (D > Dx[y]) { Dx[y] = D; Ex[y] = i; }
    if (D > Dy[x]) { Dy[x] = D; Ey[x] = i; }

    if (idx == N) { p = i; score = D; break; }
  }

  vector<int> ans;
  for (; A[p].i != 1; p = prv[p]) ans.push_back(p);
  ans.push_back(p);

  cout << score << endl;
  cout << ans.size() << endl;
  reverse(ans.begin(), ans.end());
  for (auto p: ans) cout << A[p].x << " " << A[p].y << endl;

  ////////////////////////////////
  return 0;
}
