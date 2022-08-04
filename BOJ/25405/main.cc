#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld INF = 3e9;
lld N, M, K, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  cin >> M >> K;
  sort(A+1, A+N+1);
  A[N+1] = INF;

  // m: processed M / h: height of [l, r] / p: (h+1)-heights in [l, r]
  lld l = K, r = K, m = 0, h = A[K], p = 0;
  while (m < M) {
    // expand [l, r]
    while (l > 1 && A[l-1]+m == h) l--;
    while (r < N) {
      if (A[r+1] == h) r++;
      else if (A[r+1] == h+1) r++, p++;
      else break;
    }

    lld w = r-l+1, x = K-l+1; // +x/w per step
    // merge with left
    lld t1 = (l == 1 || r == K) ? INF : (w*(h-A[l-1]-m) + p) / (w-x);
    // merge with right
    lld t2 = (w*(A[r+1]-h) - p) / x;

    lld t = min({t1, t2, M-m});
    h += (x*t + p) / w, p = (x*t + p) % w;
    m += t;
  }

  int i = 1;
  for (; i<l; i++) cout << A[i]+M << " ";
  for (; i<=r-p; i++) cout << h << " ";
  for (; i<=r; i++) cout << h+1 << " ";
  for (; i<=N; i++) cout << A[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
