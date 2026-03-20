#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;

  queue<int> Q;
  for (int i=1; i<=N; i++) Q.push(i);

  vector<int> ans;
  while (!Q.empty()) {
    for (int i=0; i<K-1; i++) {
      int x = Q.front(); Q.pop();
      Q.push(x);
    }
    int x = Q.front(); Q.pop();
    ans.push_back(x);
  }

  // print
  cout << "<";
  for (int i=0; i<N; i++) {
    cout << ans[i];
    if (i < N-1) cout << ", ";
  }
  cout << ">" << endl;

  ////////////////////////////////
  return 0;
}
