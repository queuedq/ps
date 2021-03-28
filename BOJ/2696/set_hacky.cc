#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    int M; cin >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    cout << M/2+1 << endl;

    set<double> S;
    S.insert(A[0]);
    auto mid = S.begin();
    cout << *mid;

    for (int i = 1; i < M;) {
      int d = 0;

      d += A[i] + i*1e-6 > *mid ? 1 : -1;
      S.insert(A[i] + i*1e-6);
      i++;
      d += A[i] + i*1e-6 > *mid ? 1 : -1;
      S.insert(A[i] + i*1e-6);
      i++;

      if (d > 0) mid++;
      if (d < 0) mid--;

      cout << (i%20 == 1 ? "\n" : " ") << floor(*mid);
    }

    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
