#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int N, K, A[MN], vst[MN], nxt[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<K; i++) cin >> A[i];

  fill(vst, vst+K+1, K+1);
  for (int i=K-1; i>=0; i--) {
    nxt[i] = vst[A[i]];
    vst[A[i]] = i;
  }

  int ans = 0;
  vector<int> S, T;
  for (int i=0; i<K; i++) {
    int j = find(S.begin(), S.end(), A[i]) - S.begin();
    if (j < S.size()) {
      T[j] = nxt[i];
      continue;
    }
    if (S.size() < N) {
      S.push_back(A[i]);
      T.push_back(nxt[i]);
      continue;
    }
    
    j = max_element(T.begin(), T.end()) - T.begin();
    S[j] = A[i];
    T[j] = nxt[i];
    ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
