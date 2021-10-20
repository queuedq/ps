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

  while (true) {
    int N, A, B; cin >> N >> A >> B;
    if (N == 0) break;
    
    vector<int> diff;
    int sum = 0;
    for (int i=0; i<N; i++) {
      int k, da, db; cin >> k >> da >> db;
      sum += da * k;
      for (int j=0; j<k; j++) diff.push_back(db - da);
    }

    int K = diff.size();
    sort(diff.begin(), diff.end());

    int i = 0;
    for (; i<K-A; i++) sum += diff[i];
    for (; i<min(K, B) && diff[i]<0; i++) sum += diff[i];

    cout << sum << endl;
  }

  ////////////////////////////////
  return 0;
}
