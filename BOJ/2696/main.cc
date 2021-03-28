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

    priority_queue<int> P;
    priority_queue<int, vector<int>, greater<int>> Q;
    int mid = A[0];
    cout << mid;

    for (int i = 1; i < M;) {
      if (A[i] >= mid) Q.push(A[i]);
      else P.push(A[i]);
      i++;
      if (A[i] >= mid) Q.push(A[i]);
      else P.push(A[i]);
      i++;

      if (P.size() > Q.size()) {
        Q.push(mid);
        mid = P.top();
        P.pop();
      }
      if (P.size() < Q.size()) {
        P.push(mid);
        mid = Q.top();
        Q.pop();
      }

      cout << (i%20 == 1 ? "\n" : " ") << floor(mid);
    }

    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
