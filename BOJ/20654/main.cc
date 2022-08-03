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
lld N, M;

vector<lld> ps;
int idx(lld p) { return lower_bound(all(ps), p) - ps.begin(); }

struct Drink {
  lld d, p, l;
  bool operator <(const Drink &X) const { return d > X.d; }
};
Drink A[ST];

struct Node {
  lld P=0, L=0; // P: price sum, L: liters sum
  Node *l=0, *r=0;
  Node() = default;
  Node(lld P, lld L): P(P), L(L) {}
  Node(Node* l, Node *r): l(l), r(r) { P = l->P + r->P, L = l->L + r->L; }
};
Node *root[ST];

Node* build(int s, int e) {
  if (s == e) return new Node();
  int m = (s+e)/2;
  return new Node(build(s, m), build(m+1, e));
}

Node* add(Node *n, int nl, int nr, int i, Drink &X) {
  if (nl == nr) return new Node(n->P + X.p * X.l, n->L + X.l);
  int m = (nl+nr)/2;
  if (i <= m) return new Node(add(n->l, nl, m, i, X), n->r);
  else return new Node(n->l, add(n->r, m+1, nr, i, X));
}

lld query(Node *n, lld L) { // L liters min price
  lld ret = 0;
  while (n->l) {
    if (L <= n->l->L) n = n->l;
    else { ret += n->l->P; L -= n->l->L; n = n->r; }
  }
  return ret + n->P/n->L * L;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> A[i].d >> A[i].p >> A[i].l;
    ps.push_back(A[i].p);
  }
  sort(A+1, A+N+1);
  sort(all(ps));

  root[0] = build(0, ST-1);
  for (int i=1; i<=N; i++) root[i] = add(root[i-1], 0, ST-1, idx(A[i].p), A[i]);

  for (int q=0; q<M; q++) {
    lld g, L; cin >> g >> L;
    lld l = 0, r = N+1; // r: possible
    while (l+1 < r) {
      lld t = (l+r)/2;
      if (root[t]->L >= L && query(root[t], L) <= g) r = t;
      else l = t;
    }
    if (r == N+1) cout << -1 << endl;
    else cout << A[r].d << endl;
  }

  ////////////////////////////////
  return 0;
}
