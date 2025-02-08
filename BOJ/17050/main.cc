#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50505;
int N, M;
string S[MN];
int bits[MN];
unordered_map<int, vector<int>> cnt; // (common part hash, bits) -> count

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    cin >> S[i];
    for (int j=0; j<M; j++) {
      if (S[i][j] != '?') bits[i] |= 1<<j;
    }
  }

  lld total = 0;
  for (int i=0; i<N; i++) {
    for (int m=0; m<1<<M; m++) { // common bits
      if ((m & bits[i]) != m) continue;

      // get common part hash
      int hash = 0;
      for (int j=0; j<M; j++) {
        if (m>>j & 1) hash |= (S[i][j]-'a'+1) << (5*j);
      }

      // get count
      auto &vec = cnt[hash];
      vec.resize(1<<M);
      for (int k=0; k<1<<M; k++) {
        if ((bits[i] & k) == m) total += vec[k];
      }

      // save count
      vec[bits[i]]++;
    }
  }

  cout << total << endl;

  ////////////////////////////////
  return 0;
}
