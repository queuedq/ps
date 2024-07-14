#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, T;
vector<int> S;

void calc() {
  for (int m=0; m<1<<12; m++) {
    if (__builtin_popcount(m) == 6) S.push_back(m);
  }
  assert(sz(S) == 924); // binom(12, 6)
}

void alice() {
  for (int t=0; t<T; t++) {
    int x, y; cin >> x >> y;
    int h = 0;
    for (; h<12; h++) {
      if ((S[x] >> h & 1) && !(S[y] >> h & 1)) break;
    }
    cout << (h+1) << endl;
  }
}

void bob() {
  for (int t=0; t<T; t++) {
    int q, h; cin >> q >> h; h--;
    if (S[q] >> h & 1) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int Q;
  cin >> Q >> N >> T;

  calc();
  if (Q == 1) alice();
  else bob();

  ////////////////////////////////
  return 0;
}
