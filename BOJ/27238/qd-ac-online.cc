#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;

struct Node { Node *l, *r; lld v; };

Node *new_node(Node *l, Node *r, lld v) { Node *n = new Node{l, r, v}; return n; }
Node *new_node(Node *l, Node *r) { return new_node(l, r, l->v + r->v); }

Node *build(int s, int e) {
  if (s == e) return new_node(0, 0, 0);
  int m = (s+e)/2;
  return new_node(build(s, m), build(m+1, e), 0);
}

Node *add(Node *n, int s, int e, int i, lld v) {
  if (s == e) return new_node(0, 0, n->v + v);
  int m = (s+e)/2;
  if (i <= m) return new_node(add(n->l, s, m, i, v), n->r);
  else return new_node(n->l, add(n->r, m+1, e, i, v));
}

lld sum(Node *n, int s, int e, int l, int r) {
  if (r < s || e < l) return 0;
  if (l <= s && e <= r) return n->v;
  int m = (s+e)/2;
  return sum(n->l, s, m, l, r) + sum(n->r, m+1, e, l, r);
}

lld sum2d(Node *tree[], int x1, int x2, int y1, int y2) {
  return sum(tree[x2], 0, ST-1, y1, y2) - sum(tree[x1-1], 0, ST-1, y1, y2);
}

int N, L, M, C[ST], A[ST], B[ST];
Node *t1[ST], *t2[ST];
// f(l) = r: after last visit of l, rightmost visit is r
vector<pii> F1, F2; // stack of (l, r) where f decreases at l
lld ans[ST];

void go(int i, bool typ) {
  int s = typ ? C[i-1] : N-C[i-1]+1;
  int e = typ ? C[i] : N-C[i]+1;
  Node **tree = typ ? t1 : t2;
  vector<pii> &F = typ ? F1 : F2;

  if (e < s) { // leftward
    int l2 = s;
    while (F.back().first >= e) {
      auto [l, r] = F.back();
      ans[i] += sum2d(tree, l, l2-1, 0, r); // l1 <= a < l2, b <= f(a)
      l2 = l;
      F.pop_back();
    }
    if (sz(F) > 1) { // otherwise, further than leftmost pos
      ans[i] += sum2d(tree, e, l2-1, 0, F.back().second);
    }
    F.push_back({e, e});

  } else { // rightward
    int l2 = e;
    while (F.back().second <= e) {
      auto [l, r] = F.back();
      ans[i] += sum2d(tree, l, l2-1, r+1, e); // l1 <= a < l2, f(a) < b <= e
      l2 = l;
      F.pop_back();
    }
    F.push_back({l2, e});

  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> L >> M;
  for (int i=0; i<L; i++) cin >> C[i];
  C[L] = C[0];

  vector<vector<int>> E1(ST), E2(ST); // events for PST
  for (int i=1; i<=M; i++) {
    cin >> A[i] >> B[i];
    if (A[i] < B[i]) E1[A[i]].push_back(B[i]);
    else E2[N-A[i]+1].push_back(N-B[i]+1);
  }
  
  // build PST
  t1[0] = build(0, ST-1);
  t2[0] = build(0, ST-1);
  for (int a=1; a<=N; a++) {
    t1[a] = t1[a-1];
    t2[a] = t2[a-1];
    for (auto b: E1[a]) t1[a] = add(t1[a], 0, ST-1, b, 1);
    for (auto b: E2[a]) t2[a] = add(t2[a], 0, ST-1, b, 1);
  }

  // handle queries
  F1.push_back({0, ST});
  F1.push_back({C[0], C[0]});
  F2.push_back({0, ST});
  F2.push_back({N-C[0]+1, N-C[0]+1});
  for (int i=1; i<=L; i++) {
    go(i, 1);
    go(i, 0);
  }

  lld sum = 0;
  for (int i=1; i<=L; i++) {
    sum += ans[i];
    cout << sum << endl;
  }

  ////////////////////////////////
  return 0;
}
