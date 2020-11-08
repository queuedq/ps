#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
lld N;
struct Data {
  lld v, l;
  bool operator <(Data d) const { return v < d.v; }
} A[MN];

lld pmn[MN], pmx[MN], nmn[MN], nmx[MN];

bool ok(lld e) { // e: error * 2
  if (A[0].v == 0 && A[0].l * 2 > e) return false;

  lld V1 = 0;

  for (int i=0; i<N; i++) {
    V1 = A[i].v;
    if (A[i].l * 2 > e) break;
    if (i == N-1) return true;
  }

  lld mn = INT_MAX, mx = 0;
  for (int i=0; i<N; i++) {
    if (A[i].v < V1) continue;
    mn = min(mn, A[i].l);
    mx = max(mx, A[i].l);
    pmn[i] = mn;
    pmx[i] = mx;
  }

  mn = INT_MAX, mx = 0;
  for (int i=N-1; i>=0; i--) {
    if (A[i].v < V1) break;
    mn = min(mn, A[i].l);
    mx = max(mx, A[i].l);
    nmn[i] = mn;
    nmx[i] = mx;
  }

  if (pmx[N-1] - pmn[N-1] <= e) return true;
  for (int i=0; i<N-1; i++) {
    if (A[i].v < V1) continue;
    if (pmx[i] - pmn[i] <= e &&
      nmx[i+1] - nmn[i+1] <= e &&
      pmx[i] <= nmn[i+1] + e
    ) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].v >> A[i].l;
  sort(A, A+N);

  lld l = -1, r = INT_MAX;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (ok(m)) r = m;
    else l = m;
  }

  cout << fixed << setprecision(1) << (double)r / 2 << endl;

  ////////////////////////////////
  return 0;
}
