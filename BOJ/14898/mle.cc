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
int N, Q, A[ST], prv[ST], last[ST];
vector<int> xs;

struct Node {
  int v;
  Node *l, *r;
  Node() = default;
  Node(Node *l, Node *r): l(l), r(r), v(l->v + r->v) {}
  Node(int v): v(v) {}
};
Node* root[ST];

Node* build(int s, int e) {
  if (s == e) return new Node();
  int m = (s+e)/2;
  return new Node(build(s, m), build(m+1, e));
}

Node* add(Node *n, int s, int e, int i, int v) {
  if (s == e) return new Node(n->v + v);
  int m = (s+e)/2;
  if (i <= m) return new Node(add(n->l, s, m, i, v), n->r);
  else return new Node(n->l, add(n->r, m+1, e, i, v));
}

int sum(Node *n, int s, int e, int l, int r) {
  if (r < s || e < l) return 0;
  if (l <= s && e <= r) return n->v;
  int m = (s+e)/2;
  return sum(n->l, s, m, l, r) + sum(n->r, m+1, e, l, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) { cin >> A[i]; xs.push_back(A[i]); }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  for (int i=1; i<=N; i++) {
    A[i] = lower_bound(all(xs), A[i]) - xs.begin();
    prv[i] = last[A[i]];
    last[A[i]] = i;
  }

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
