#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50005;
int N, t, B[MN], D[MN][2], A[MN]; // D[i][j]: j is possible for A[i]

void solve(int test) {
  string S;
  cin >> N >> t >> S;
  for (int i=0; i<N; i++) B[i] = S[i] - '0';
  for (int i=0; i<N; i++) D[i][0] = D[i][1] = false;

  for (int i=N-1; i>=N-t; i--) D[i][0] = D[i][1] = true;
  for (int i=N-1-t; i>=0; i--) {
    if (B[i+t] == 0) {
      D[i][0] = true;
      D[i][1] = false;
    } else {
      D[i][0] = i+t+t < N ? D[i+t+t][1] : false;
      D[i][1] = true;
    }
  }

  for (int i=0; i<t; i++) A[i] = D[i][0] ? 0 : 1;
  for (int i=t; i<N; i++) {
    if (B[i-t] == 0) {
      A[i] = 0;
    } else {
      if (i-t-t >= 0 && A[i-t-t] == 1 && D[i][0]) A[i] = 0;
      else A[i] = 1;
    }
  }

  cout << "Case #" << test << endl;
  for (int i=0; i<N; i++) cout << A[i];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
