#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<=N; i++) {
    vector<bool> vst(i+1);
    for (int k=1; i-k*2>=0; k++) {
      int nxt = A[i-k]*2 - A[i-k*2];
      if (0 <= nxt && nxt < i+1) {
        vst[nxt] = true;
      }
    }
    for (int j=1; j<=i+1; j++) {
      if (!vst[j]) {
        A[i] = j;
        break;
      }
    }
  }

  cout << A[N] << endl;

  ////////////////////////////////
  return 0;
}
