#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
const lld MOD = 1e9+7;
lld G = 1, k[ST];

struct Node {
  lld a, b; // ax+b
  bool oa = 0, ob = 0; // overflow bit

  Node(): a(1), b(0) { }
  Node(lld a, lld b): a(a), b(b) { }
  Node(lld a, lld b, bool oa, bool ob): a(a), b(b), oa(oa), ob(ob) { }

  lld apply(lld x) { return (a * x + b) % MOD; }

  Node operator +(Node x) {
    lld A = x.a * a;
    lld B = x.a * b + x.b;
    bool OA = oa || x.oa || A >= MOD;
    bool OB = ob || x.ob || B >= MOD || (b > 0 && x.oa);
    return Node(A % MOD, B % MOD, OA, OB);
  }
};

Node seg[ST*2];

Node qry(int l, int r) {
  Node L = Node(), R = Node();
  for (l += ST, r += ST+1; l < r; l /= 2, r /= 2) {
    if (l&1) L = L + seg[l++];
    if (r&1) R = seg[--r] + R;
  }
  return L + R;
}

void upd(int i, Node x) {
  seg[i += ST] = x;
  for (i /= 2; i > 0; i /= 2) seg[i] = seg[i*2] + seg[i*2+1];
}

bool check(int g, lld x) {
  Node op = qry(g+1, G-1);
  if (op.ob) return false;
  x -= op.b;
  if (x < 0) return false;
  if (x == 0) return true;
  if (op.oa || x % op.a != 0) return false;
  return true;
}

int at_room(lld x) {
  int l = -1, r = G-1;
  while (l+1 < r) {
    int mid = (l+r)/2;
    if (check(mid, x)) r = mid;
    else l = mid;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(seg, seg+ST*2, Node());
  k[0] = 1;

  int Q; cin >> Q;
  for (int q=0; q<Q; q++) {
    int t; cin >> t;
    if (t == 1) {
      cin >> k[G];

      if (k[G] == 0) upd(G, Node(2, 0));
      else upd(G, Node(1, k[G]));
      G++;

    } else if (t == 2) {
      lld g, x; cin >> g >> x;
      x--; // 0-index

      if (k[g] == 0) x = x*2+1;
      Node op = qry(g+1, G-1);
      cout << op.apply(x) << endl;

    } else {
      lld x; cin >> x;

      cout << at_room(x) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
