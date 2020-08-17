#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 30;
lld N, Q, A[MAXN][MAXN];

pii move(pii pos, int d) { // d=0: down, d=1: right
  if (d == 0) pos.first++;
  else pos.second++;
  return pos;
}

bool oob(pii pos) {
  return pos.first > N || pos.second > N;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      if (j%2) A[i][j] = 0;
      else A[i][j] = 1LL << (i+j-2);
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  cin >> Q;
  for (int q=0; q<Q; q++) {
    lld X; cin >> X;

    pii pos = {1, 1};
    cout << pos.first << " " << pos.second << endl;

    while (pos != pii(N, N)) {
      if (oob(move(pos, 0))) {
        pos = move(pos, 1);
        cout << pos.first << " " << pos.second << endl;
        continue;
      }
      if (oob(move(pos, 1))) {
        pos = move(pos, 0);
        cout << pos.first << " " << pos.second << endl;
        continue;
      }
      if (((1LL<<(pos.first+pos.second-1)) & X) == A[pos.first+1][pos.second]) {
        pos = move(pos, 0);
      } else {
        pos = move(pos, 1);
      }
      cout << pos.first << " " << pos.second << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
