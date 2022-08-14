#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20;
const int MX = (1<<20) + (1<<20)*21*2 + 5;
int N, Q, prv[ST];

struct Node { int l, r, v; };
Node pool[MX];
int idx, root[ST];

int new_node(int l, int r, int v) { pool[idx++] = {l, r, v}; return idx-1; }
int new_node(int l, int r) { return new_node(l, r, pool[l].v + pool[r].v); }
int new_node(int v) { return new_node(0, 0, v); }
int new_node() { return new_node(0, 0, 0); }

int build(int s, int e) {
  if (s == e) return new_node();
  int m = (s+e)/2;
  return new_node(build(s, m), build(m+1, e), 0);
}

int add(int n, int s, int e, int i, int v) {
  if (s == e) return new_node(pool[n].v + v);
  int m = (s+e)/2;
  if (i <= m) return new_node(add(pool[n].l, s, m, i, v), pool[n].r);
  else return new_node(pool[n].l, add(pool[n].r, m+1, e, i, v));
}

int sum(int n, int s, int e, int l, int r) {
  if (r < s || e < l) return 0;
  if (l <= s && e <= r) return pool[n].v;
  int m = (s+e)/2;
  return sum(pool[n].l, s, m, l, r) + sum(pool[n].r, m+1, e, l, r);
}

void init() {
  cin >> N;
  vector<int> A(N+1), xs;
  for (int i=1; i<=N; i++) { cin >> A[i]; xs.push_back(A[i]); }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  vector<int> last(N+1);
  for (int i=1; i<=N; i++) {
    A[i] = lower_bound(all(xs), A[i]) - xs.begin();
    prv[i] = last[A[i]];
    last[A[i]] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  init();

  root[0] = build(0, ST-1);
  for (int i=1; i<=N; i++) {
    root[i] = add(root[i-1], 0, ST-1, i, 1);
    root[i] = add(root[i], 0, ST-1, prv[i], -1);
  }

  cin >> Q;
  int ans = 0, x, l, r;
  for (int i=1; i<=Q; i++) {
    cin >> x >> r;
    l = x + ans;
    ans = sum(root[r], 0, ST-1, l, r);
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
