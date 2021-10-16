#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int O = 2005;

int N, Q, cnt[O*2][O*2];

struct fenwick {
  int bit[O*2][O*2];

  void upd(int x, int y, int v) {
    for (int i=O+x; i<O*2; i+=i&-i) {
      for (int j=O+y; j<O*2; j+=j&-j) {
        bit[i][j] += v;
      }
    }
  }

  int qry(int x, int y) {
    int res = 0;
    for (int i=O+x; i>0; i-=i&-i) {
      for (int j=O+y; j>0; j-=j&-j) {
        res += bit[i][j];
      }
    }
    return res;
  }
} F1, F2, F3;
//     2 1 1
//   2 2 1 1
// 2 2 c 1 1
// 2 3 3 3
// 3 3 3

void upd(fenwick &F, int x, int y, int r) {
  F.upd(x+1, y, 1);
  F.upd(x+1, y+r+1, -1);
  F.upd(x+r+1, y, -1);
  F.upd(x+r+1, y+r+1, 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<Q; i++) {
    int q, x, y, r; cin >> q;
    if (q == 1) {
      cin >> x >> y >> r;
      cnt[O+x][O+y]++;
      upd(F1, x, y, r);
      upd(F2, y-x, -x, r);
      upd(F3, -y, x-y, r);
    } else {
      cin >> x >> y;
      cout << cnt[O+x][O+y] + F1.qry(x, y) + F2.qry(y-x, -x) + F3.qry(-y, x-y) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
