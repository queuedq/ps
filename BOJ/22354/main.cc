#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, A[MN];
string S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  for (int i=0; i<N; i++) cin >> A[i];

  lld mx = A[0];
  vector<lld> B;
  for (int i=1; i<N; i++) {
    if (S[i-1] != S[i]) {
      B.push_back(mx);
      mx = A[i];
    } else {
      mx = max(mx, A[i]);
    }
  }
  B.push_back(mx);

  int K = B.size();
  if (K <= 2) { cout << 0 << endl; return 0; }
  
  sort(B.begin()+1, B.end()-1);
  lld ans = 0;
  for (int i=0; i<(K-1)/2; i++) ans += B[K-2-i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
