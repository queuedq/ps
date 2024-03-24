#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<10;
const int MW = 5050;
int N, W, Q[6];

struct User { int s, e, p[6]; };
User U[ST];
vector<int> xs;
vector<int> seg[ST*2];

int D[ST][MW], k;
lld ans;

void add(int l, int r, int i) {
  for (l+=ST, r+=ST; l<r; l/=2, r/=2) {
    if (l&1) seg[l++].push_back(i);
    if (r&1) seg[--r].push_back(i);
  }
}

void solve(int n, int nl, int nr) {
  // dp
  for (auto i: seg[n]) {
    k++;
    for (int w=0; w<=W; w++) {
      D[k][w] = D[k-1][w];
      for (int j=0; j<6; j++) {
        if (w >= Q[j]) D[k][w] = max(D[k][w], D[k-1][w-Q[j]] + U[i].p[j]);
      }
    }
  }

  // recurse
  if (n >= ST) {
    int x = n - ST;
    if (x+1 < sz(xs)) ans += (lld)D[k][W] * (xs[x+1] - xs[x]);
  } else {
    int m = (nl+nr)/2;
    solve(n*2, nl, m);
    solve(n*2+1, m, nr);
  }

  // rollback
  k -= sz(seg[n]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> W;
  for (int j=0; j<6; j++) cin >> Q[j];
  for (int i=0; i<N; i++) {
    User &user = U[i];
    cin >> user.s >> user.e;
    for (int j=0; j<6; j++) cin >> user.p[j];
    xs.push_back(user.s);
    xs.push_back(user.e);
  }

  // compress
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  for (auto &[s, e, p]: U) {
    s = lower_bound(all(xs), s) - xs.begin();
    e = lower_bound(all(xs), e) - xs.begin();
  }
  
  // init seg
  for (int i=0; i<N; i++) add(U[i].s, U[i].e, i);

  // solve
  solve(1, 0, ST);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
