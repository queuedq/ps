#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Node {
  // i: this node decides i-th bit
  // len: length of the interval
  // flips: lazy-propgated flips
  // cnt: # values in this interval
  // p: parent
  // l: i-th bit is 0
  // r: i-th bit is 1
  int i, len, flips = 0, cnt = 0;
  Node *p = 0, *l = 0, *r = 0;

  Node(int i): i(i), len(1<<(i+1)) {}
  Node(Node *p): i(p->i-1), len(1<<(i+1)), p(p) {}

  Node *left() { return l ? l : (l = new Node(this)); }
  Node *right() { return r ? r : (r = new Node(this)); }

  void insert(int v) { // only for initialization
    cnt++;
    if (i == -1) return;

    if ((v>>i & 1) == 0) left()->insert(v);
    else right()->insert(v);
  }

  void propagate() {
    if (i == -1) return;

    // apply flip
    if (flips>>i & 1) swap(l, r);
    flips &= ~(1<<i);

    // propagate flips to children
    if (l) l->flips ^= flips;
    if (r) r->flips ^= flips;
    flips = 0;
  }

  void cut() {
    if (!p) return;
    if (p->l == this) p->l = 0;
    if (p->r == this) p->r = 0;
    p->update_cnt();
    p = 0;
  }

  void update_cnt() {
    cnt = 0;
    if (l) cnt += l->cnt;
    if (r) cnt += r->cnt;
    if (p) p->update_cnt();
  }

  static Node *merge(Node *x, Node *y, bool upd=true) { // merge x <- y and delete y
    if (!x) return y;
    if (!y) return x;
    x->propagate(), y->propagate();
  
    x->cnt += y->cnt;
    if (upd && x->p) x->p->update_cnt();
  
    x->l = merge(x->l, y->l, false);
    if (x->l) x->l->p = x;
    x->r = merge(x->r, y->r, false);
    if (x->r) x->r->p = x;
  
    delete y;
    return x;
  }
};

int N, Q;
Node *root;
vector<pair<Node *, int>> flip_nodes; // nodes to apply flip-merges later

void find_flips(Node *x, int path, int l, int r, int k) {
  x->propagate();
  int nl = path, nr = path + x->len - 1;
  
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) {
    if (x->i >= k) x->flips ^= (1<<k); // lazy
    else x->cut(), flip_nodes.push_back({x, path}); // cut and save for merge
    return;
  }

  if (x->l) find_flips(x->l, path, l, r, k);
  if (x->r) find_flips(x->r, path | 1 << x->i, l, r, k);
}

void apply_flip(Node *x, int path, int k) { // apply flip-merges
  Node *y = root;
  path ^= 1<<k;

  while (y->i > x->i) {
    y->propagate();
    int bit = path >> y->i & 1;
    if (bit == 0) y = y->left();
    else y = y->right();
  }

  Node::merge(y, x);
}

void flip(int l, int r, int k) {
  find_flips(root, 0, l, r, k);
  for (auto [x, path]: flip_nodes) apply_flip(x, path, k);
  flip_nodes.clear();
}

int find_nth(Node *x, int n, int path=0) {
  if (x->i == -1) return path;
  x->propagate();
  
  int lcnt = x->l ? x->l->cnt : 0;
  if (n <= lcnt) return find_nth(x->l, n, path);
  return find_nth(x->r, n - lcnt, path | 1 << x->i);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  root = new Node(19);
  
  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    int v; cin >> v;
    root->insert(v);
  }

  for (int q=0; q<Q; q++) {
    int t, l, r, k; cin >> t;
    if (t == 1) {
      cin >> l >> r >> k;
      flip(l, r, k);
    } else {
      cin >> k;
      int ans = find_nth(root, k);
      cout << ans << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
