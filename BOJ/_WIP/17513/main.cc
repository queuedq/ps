#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
const lld MOD = 1e9+7;
lld G = 1, k[ST], g0 = 0;

struct Node {
  lld a, b; // ax+b
  bool o; // overflow bit

  Node(): a(1), b(0), o(0) { }
  Node(lld a, lld b): a(a), b(b), o(0) { }
  Node(lld a, lld b, bool o): a(a), b(b), o(o) { }

  lld apply(lld x) { return (a * x + b) % MOD; }

  Node operator +(Node x) {
    lld A = x.a * a;
    lld B = x.a * b + x.b;
    bool O = o || x.o || A >= MOD || B >= MOD;
    return Node(A % MOD, B % MOD, O);
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
  if (op.o) return false;
  x -= op.b;
  if (x < 0) return false;
  if (x % op.a != 0) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(seg, seg+ST*2, Node());

  int Q; cin >> Q;
  for (int q=0; q<Q; q++) {
    int t; cin >> t;
    if (t == 1) {
      cin >> k[G];

      if (k[G] == 0) {
        upd(G, Node(2, 0));
      } else {
        upd(G, Node(1, k[G]));
        g0 = G; // manage group at pos 0 b/c overflow check does not work here
      }
      G++;
    } else if (t == 2) {
      lld g, x; cin >> g >> x;

      x--; // 0-index
      if (k[g] == 0) x = x*2+1;
      Node op = qry(g+1, G-1);
      cout << op.apply(x) << endl;
    } else {
      lld x; cin >> x;
      if (x == 0) {
        cout << g0 << endl;
      } else {
        int l = -1, r = G-1;
        while (l+1 < r) {
          int mid = (l+r)/2;
          if (check(mid, x)) r = mid;
          else l = mid;
        }
        cout << r << endl;
      }
    }
  }

  ////////////////////////////////
  return 0;
}
