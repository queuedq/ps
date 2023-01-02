#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, A[3][MN], vst[MN], ans[MN];
int idx[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int k=0; k<3; k++) {
    for (int i=1; i<=N; i++) cin >> A[k][i];
    idx[k] = N;
  }

  for (int i=N; i>=1; i--) {
    int S[3];
    for (int k=0; k<3; k++) S[k] = A[k][idx[k]];
    sort(S, S+3);
    
    ans[i] = S[1]; // element that appears >= twice
    vst[ans[i]] = 1;
    
    for (int k=0; k<3; k++) {
      while (vst[A[k][idx[k]]]) idx[k]--;
    }
  }

  for (int i=1; i<=N; i++) cout << ans[i] << " ";

  ////////////////////////////////
  return 0;
}
