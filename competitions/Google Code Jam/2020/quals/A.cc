#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 105;
int N, A[MAXN][MAXN];

tuple<int, int, int> calc() {
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> A[i][j];
  }

  int k = 0, r = 0, c = 0;

  for (int i=0; i<N; i++) k += A[i][i];

  for (int i=0; i<N; i++) {
    set<int> row, column;
    for (int j=0; j<N; j++) {
      row.insert(A[i][j]);
      column.insert(A[j][i]);
    }
    if ((int)row.size() < N) r++;
    if ((int)column.size() < N) c++;
  }

  return {k, r, c};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i=1; i<=T; i++) {
    int k, r, c;
    tie(k, r, c) = calc();
    cout << "Case #" << i << ": " << k << " " << r << " " << c << endl;
  }

  ////////////////////////////////
  return 0;
}
