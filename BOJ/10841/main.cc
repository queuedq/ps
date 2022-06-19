#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
int N, H, L[MN], D[MN][MN];
// D[i][j]: select i-th rect and <=j-th rect

struct Rect {
  int p, l, r, h, k;
  bool operator <(const Rect &R) const { return r < R.r; }
};
vector<Rect> A;

bool overlap(const Rect &P, const Rect &Q) {
  if (P.r <= Q.l || Q.r <= P.l) return 0;
  return P.p == Q.p || P.h + Q.h > H;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> H;
  for (int i=0; i<N; i++) {
    int p, l, r, h, k; cin >> p >> l >> r >> h >> k;
    A.push_back({p, l, r, h, k});
  }
  A.push_back({0, 0, 0, 0, 0});
  sort(all(A));

  for (int i=1; i<=N; i++) {
    // index j of last rect with A[j].r <= A[i].l
    L[i] = upper_bound(all(A), (Rect){0, 0, A[i].l, 0, 0}) - A.begin() - 1;
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    D[i][0] = A[i].k;
    for (int j=1; j<i; j++) {
      D[i][j] = D[i][j-1];
      if (!overlap(A[i], A[j])) {
        D[i][j] = max({D[i][j],
          D[i][L[j]] + A[j].k,
          D[j][L[i]] + A[i].k,
        });
      }
    }

    for (int j=i; j<=N; j++) D[i][j] = D[i][j-1];
    ans = max(ans, D[i][N]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
