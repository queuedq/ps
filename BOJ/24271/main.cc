#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, Q, seg[ST*2];

void upd(int i, int v) {
  seg[i+=ST] ^= v;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] ^ seg[i*2+1];
}

int qry(int i, int x) {
  int res=0, n=1;
  for (int b=18-1; b>=0; b--) {
    int xb = x>>b & 1;
    if (i>>b & 1) {
      res ^= seg[n*2 + xb];
      n = n*2 + !xb;
    } else {
      n = n*2 + xb;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> seg[i+ST];
  for (int i=ST-1; i>0; i--) seg[i] = seg[i*2] ^ seg[i*2+1];

  cin >> Q;
  for (int q=0; q<Q; q++) {
    int type; cin >> type;
    if (type == 1) {
      int l, r, x; cin >> l >> r >> x;
      if (x >= ST) { cout << 0 << endl; continue; }
      cout << (qry(l, x) ^ qry(r+1, x)) << endl;
    } else {
      int i, x; cin >> i >> x;
      upd(i, x);
    }
  }

  ////////////////////////////////
  return 0;
}
