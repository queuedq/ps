#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  auto cmp = [](pii a, pii b) { // large value, small index
    return pii(a.first, -a.second) < pii(b.first, -b.second);
  };
  priority_queue<pii, vector<pii>, decltype(cmp)> A(cmp), B(cmp);

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A.push({a, i});
  }
  cin >> M;
  for (int j=0; j<M; j++) {
    int b; cin >> b;
    B.push({b, j});
  }

  int i = -1, j = -1;
  vector<int> ans;
  while (1) {
    while (!A.empty() && !B.empty()) {
      if (A.top().second < i) A.pop();
      else if (B.top().second < j) B.pop();
      else if (A.top().first > B.top().first) A.pop();
      else if (A.top().first < B.top().first) B.pop();
      else break;
    }
    if (A.empty() || B.empty()) break;
    ans.push_back(A.top().first);
    i = A.top().second, j = B.top().second;
    A.pop(), B.pop();
  }

  cout << sz(ans) << endl;
  for (auto x: ans) cout << x << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
