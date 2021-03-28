#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 200'005;
int N, A[MAXN], coords[MAXN];
int idx[MAXN], prv[MAXN], nxt[MAXN];

void reset() {
  fill(idx, idx+N, -1);
  fill(prv, prv+N, -1);
  fill(nxt, nxt+N, N);
}

void build() {
  for (int i=0; i<N; i++) {
    if (idx[A[i]] != -1) {
      nxt[idx[A[i]]] = i;
      prv[i] = idx[A[i]];
    }
    idx[A[i]] = i;
  }
}

bool check(int l, int r) {
  if (l >= r) return true;

  int m = -1;
  for (int i=l; i<=r; i++) {
    if (prv[i] < l && nxt[i] > r) { m = i; break; }
    if (prv[l+r-i] < l && nxt[l+r-i] > r) { m = l+r-i; break; }
  }

  if (m == -1) return false;
  return check(l, m-1) && check(m+1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0; i<N; i++) {
      cin >> A[i];
      coords[i] = A[i];
    }

    sort(coords, coords+N);
    for (int i=0; i<N; i++) {
      A[i] = lower_bound(coords, coords+N, A[i]) - coords;
    }

    reset();
    build();

    cout << (check(0, N-1) ? "non-boring" : "boring") << endl;
  }

  ////////////////////////////////
  return 0;
}
