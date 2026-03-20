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
int seg[ST*2], lazy[ST*2];

void push(int n, int nl, int nr) {
  seg[n*2] += lazy[n];
  seg[n*2+1] += lazy[n];
  lazy[n*2] += lazy[n];
  lazy[n*2+1] += lazy[n];
  lazy[n] = 0;
}

void add_range(int n, int nl, int nr, int l, int r, int v) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) { seg[n] += v; lazy[n] += v; return; }
  push(n, nl, nr);
  int m = (nl+nr)/2;
  add_range(n*2, nl, m, l, r, v);
  add_range(n*2+1, m+1, nr, l, r, v);
  seg[n] = max(seg[n*2], seg[n*2+1]);
}
void add_range(int l, int r, int v) { add_range(1, 0, ST-1, l, r, v); }

int query_max(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) return seg[n];
  push(n, nl, nr);
  int m = (nl+nr)/2;
  return max(query_max(n*2, nl, m, l, r), query_max(n*2+1, m+1, nr, l, r));
}
int query_max(int l, int r) { return query_max(1, 0, ST-1, l, r); }

////////////////////////////////
int N, K, A[ST], prv[ST], last[ST];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  int L = (K+1)/2;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    prv[i] = last[A[i]];
    last[A[i]] = i;
  }

  for (int i=1; i<=N; i++) {
    if (A[i]) add_range(prv[i], i-1, 1);
    int D = i >= L ? query_max(0, i-L) : INT_MIN;
    add_range(i, i, D);
  }

  cout << query_max(0, N) << endl;

  ////////////////////////////////
  return 0;
}
