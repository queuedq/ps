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
  Node *l = 0, *r = 0, *p = 0;
  int v;

  Node() = default;
  Node(int v): v(v) {}
};

void rotate(Node *x) {
  Node *p = x->p, *m = 0;
  if (!p) return;

  // children
  if (x == p->l) p->l = (m = x->r), x->r = p;
  else p->r = (m = x->l), x->l = p;

  // parents
  x->p = p->p;
  p->p = x;
  if (m) m->p = p;
  if (x->p) (x->p->l == p ? x->p->l : x->p->r) = x;
}

Node *splay(Node *x) {
  while (x->p) {
    Node *p = x->p;
    Node *g = p->p;
    if (g) rotate((x == p->l) == (p == g->l)? p : x);
    rotate(x);
  }
  return x;
}

Node *rightmost(Node *x) {
  while (x->r) x = x->r;
  return splay(x);
}

vector<Node *> T; // leftmost nodes (= index)
vector<pair<Node *, Node *>> qry;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int N, Q; cin >> N >> Q;
  T.resize(N+1);
  qry.resize(Q+1);
  for (int i=1; i<=N; i++) T[i] = new Node(i); // rightmost nodes (= value)

  for (int q=1; q<=Q; q++) {
    char t; cin >> t;
    int i, j;

    if (t == 's') {
      cin >> i >> j;
      auto x = T[i], y = T[j];
      auto nx = new Node();
      auto ny = new Node();
      y->l = nx, nx->p = y; // connect nx <- y
      x->l = ny, ny->p = x; // connect ny <- x
      T[i] = nx, T[j] = ny;
      qry[q] = {nx, ny};

    } else if (t == 'f' || t == 'r') {
      cin >> i;
      auto [x, y] = qry[i];
      splay(x);
      splay(y);
      swap(x->r, y->r);
      swap(x->r->p, y->r->p);

    } else if (t == 'q') {
      cin >> i;
      splay(T[i]);
      cout << rightmost(T[i])->v << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
