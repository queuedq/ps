#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
const int INF = 1e9;
int N, A[ST], seg[ST*2], lazy[ST*2];
vector<int> xs;
vector<int> U, D; // upper left hull, lower right hull

void add_sum(int i, int v) {
  seg[i+=ST] += v;
  for (i/=2; i>0; i/=2) seg[i] += v;
}

int query_sum(int l, int r) {
  int sum = 0;
  for (l+=ST, r+=ST; l<r; l/=2, r/=2) {
    if (l&1) sum += seg[l++];
    if (r&1) sum += seg[--r];
  }
  return sum;
}

void propagate(int n) {
  seg[n] += lazy[n];
  if (n < ST) {
    lazy[n*2] += lazy[n];
    lazy[n*2+1] += lazy[n];
  }
  lazy[n] = 0;
}

void add_max(int n, int nl, int nr, int l, int r, int v) {
  propagate(n);
  if (nr <= l || r <= nl) return;
  if (l <= nl && nr <= r) {
    lazy[n] += v;
    propagate(n);
    return;
  }
  int m = (nl+nr)/2;
  add_max(n*2, nl, m, l, r, v);
  add_max(n*2+1, m, nr, l, r, v);
  seg[n] = max(seg[n*2], seg[n*2+1]);
}

int query_max(int n, int nl, int nr, int l, int r) {
  propagate(n);
  if (nr <= l || r <= nl) return -INF;
  if (l <= nl && nr <= r) return seg[n];
  int m = (nl+nr)/2;
  return max(query_max(n*2, nl, m, l, r), query_max(n*2+1, m, nr, l, r));
}

pii find_range(int x, int y) { // point's upper hull cover range [l, r)
  int s = -1, e = sz(U);
  while (s+1 < e) {
    int m = (s+e)/2;
    if (A[U[m]] >= y) e = m;
    else s = m;
  }
  int l = e;
  int r = lower_bound(all(U), x) - U.begin();
  return {l, r};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    xs.push_back(A[i]);
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  for (int i=1; i<=N; i++) A[i] = lower_bound(all(xs), A[i]) - xs.begin();

  // upper/lower hull
  for (int i=1, cur=-1; i<=N; i++) {
    if (A[i] > cur) U.push_back(i), cur = A[i];
  }
  for (int i=N, cur=N; i>=1; i--) {
    if (A[i] < cur) D.push_back(i), cur = A[i];
  }
  reverse(all(D));

  // get inversion count
  lld inv = 0;
  for (int i=1; i<=N; i++) {
    inv += query_sum(A[i]+1, ST);
    add_sum(A[i], 1);
  }
  fill_n(seg, ST*2, 0);

  // solve
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  int i = 1, delta = -1;

  for (auto j: D) {
    for (; i<=j; i++) {
      { // inversion for lower right point
        pq.push({A[i], i});
        auto [l, r] = find_range(i, A[i]);
        add_max(1, 0, ST, l, r, 1);
      }
      { // inversion for upper left point
        pq.push({A[i]+1, i});
        auto [l, r] = find_range(i, A[i]+1);
        add_max(1, 0, ST, l, r, 1);
      }
    }

    while (pq.top().first <= A[j]) {
      auto [y, x] = pq.top(); pq.pop();
      auto [l, r] = find_range(x, y);
      add_max(1, 0, ST, l, r, -1);
    }

    auto [l, r] = find_range(j, A[j]);
    delta = max(delta, query_max(1, 0, ST, l, r));
  }

  cout << inv - delta << endl;

  ////////////////////////////////
  return 0;
}
