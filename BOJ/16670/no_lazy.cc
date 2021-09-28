#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20;

struct Node {
  lld end, sum;
  Node operator +(Node x) { return {max(end + x.sum, x.end), sum + x.sum}; }
};

Node seg[ST*2];

void update(int i, Node x) {
  seg[i+=ST] = x;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

Node query(int l, int r) { // [l, r]
  Node L = {0, 0}, R = {0, 0};
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) L = L + seg[l++];
    if (r&1) R = seg[--r] + R;
  }
  return L + R;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int Q; cin >> Q;
  vector<pll> joins(Q);

  for (int q=0; q<Q; q++) {
    char type; cin >> type;

    if (type == '+') {
      lld t, d; cin >> t >> d;
      update(t, {t+d, d});
      joins[q] = {t, d};
    } else if (type == '-') {
      int i; cin >> i;
      auto [t, d] = joins[i-1];
      update(t, {0, 0});
    } else {
      lld t; cin >> t;
      cout << max(query(0, t).end - t, 0LL) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
