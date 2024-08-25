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
int N, A[ST];
vector<int> xs;

// PST
struct Node { int sum; Node *l, *r; };
Node *seg[ST];

Node *init(int len) {
  auto n = new Node{};
  if (len == 1) return n;
  n->l = init(len/2);
  n->r = init(len/2);
  return n;
}

Node *add(Node *n, int nl, int nr, int i, int v) {
  if (i < nl || nr < i) return n;
  if (nl == nr) return new Node{n->sum+v, 0, 0};
  int m = (nl+nr)/2;
  return new Node{
    n->sum + v,
    add(n->l, nl, m, i, v),
    add(n->r, m+1, nr, i, v),
  };
}

int query(Node *n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) return n->sum;
  int m = (nl+nr)/2;
  return query(n->l, nl, m, l, r) + query(n->r, m+1, nr, l, r);
}

// DnC opt
vector<int> U, D; // upper/lower hull
int delta = -1;

void solve(int s, int e, int l, int r) {
  if (e < s) return;
  int m = (s+e)/2, i = U[m];

  int best = -2, opt = r;
  for (int k=l; k<=r; k++) {
    int j = D[k];
    if (j <= i) continue;

    int inv = -1;
    if (A[i] >= A[j]) {
      inv = A[i] > A[j];
      inv += query(seg[j-1], 0, ST-1, A[j], A[i]-1) - query(seg[i], 0, ST-1, A[j], A[i]-1);
      inv += query(seg[j-1], 0, ST-1, A[j]+1, A[i]) - query(seg[i], 0, ST-1, A[j]+1, A[i]);
    }
    if (inv > best) best = inv, opt = k;
  }

  delta = max(delta, best);

  solve(s, m-1, l, opt);
  solve(m+1, e, opt, r);
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

  // build PST
  lld inv = 0;
  seg[0] = init(ST);
  for (int i=1; i<=N; i++) {
    inv += query(seg[i-1], 0, ST-1, A[i]+1, ST-1);
    seg[i] = add(seg[i-1], 0, ST-1, A[i], 1);
  }

  // upper/lower hull
  int cur = -1;
  for (int i=1; i<=N; i++) {
    if (A[i] > cur) U.push_back(i), cur = A[i];
  }
  cur = N;
  for (int i=N; i>=1; i--) {
    if (A[i] < cur) D.push_back(i), cur = A[i];
  }
  reverse(all(D));

  // solve
  solve(0, sz(U)-1, 0, sz(D)-1);
  cout << inv - delta << endl;

  ////////////////////////////////
  return 0;
}
