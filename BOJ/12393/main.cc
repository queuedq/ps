#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 500;
lld N, S[MN];

void solve(int T) {
  unordered_map<lld, int> sums;
  vector<vector<int>> sub;

  cin >> N;
  for (int i=0; i<N; i++) cin >> S[i];

  int a, b; // equal sets

  for (int i=0; ; i++) {
    sub.push_back({});
    lld sum = 0;
    for (int j=0; j<6; j++) {
      int k = rand() % N;
      if (count(sub[i].begin(), sub[i].end(), k) == 0) {
        sub[i].push_back(k);
        sum += S[k];
      }
    }
    sort(sub[i].begin(), sub[i].end());
    
    if (sums.count(sum) && sub[sums[sum]] != sub[i]) {
      a = sums[sum];
      b = i;
      break;
    }
    sums[sum] = i;
  }

  cout << "Case #" << T << ":" << endl;
  for (auto k: sub[a]) cout << S[k] << " ";
  cout << endl;
  for (auto k: sub[b]) cout << S[k] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  srand(time(0));
  int T; cin >> T;
  for (int i=1; i<=T; i++) solve(i);

  ////////////////////////////////
  return 0;
}
