#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
int N, A[ST], seg[ST*2];
vector<int> xs;

void add(int i, int v) {
  seg[i+=ST] += v;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int query(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) return seg[n];
  int m = (nl+nr+1)/2;
  return query(n*2, nl, m-1, l, r) + query(n*2+1, m, nr, l, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    xs.push_back(A[i]);
  }

  // compress
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  for (int i=0; i<N; i++) {
    A[i] = lower_bound(xs.begin(), xs.end(), A[i]) - xs.begin();
  }

  // inversion counting
  lld ans = 0;
  for (int i=0; i<N; i++) {
    ans += query(1, 0, ST-1, A[i]+1, ST-1); // count elements > A[i]
    add(A[i], 1); // increment A[i] count
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
