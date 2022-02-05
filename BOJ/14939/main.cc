#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 12;
int N = 10, cnt, ans = -1;
bool A[MN][MN], B[MN][MN];

void press(int i, int j) {
  cnt++;
  B[i][j] = !B[i][j];
  B[i-1][j] = !B[i-1][j];
  B[i+1][j] = !B[i+1][j];
  B[i][j-1] = !B[i][j-1];
  B[i][j+1] = !B[i][j+1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=1; i<=N; i++) {
    string S; cin >> S;
    for (int j=1; j<=N; j++) A[i][j] = S[j-1] == 'O';
  }

  for (int m=0; m<1<<N; m++) {
    cnt = 0;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) B[i][j] = A[i][j];

    for (int j=1; j<=N; j++) {
      if (m>>(j-1) & 1) press(1, j);
    }

    for (int i=2; i<=N; i++) {
      for (int j=1; j<=N; j++) {
        if (B[i-1][j]) press(i, j);
      }
    }

    bool ok = true;
    for (int j=1; j<=N; j++) {
      if (B[N][j]) ok = false;
    }
    
    if (ok) ans = max(ans, cnt);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
