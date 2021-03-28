#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 200'005;
int N;
pii probs[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    int d, s; cin>>d>>s;
    probs[i] = {d, s};
  }

  sort(probs, probs+N);

  for (int i = 0; i < N; i++) {
    auto [d, s] = probs[i];
    while (pq.size() < d) { pq.push(0); }
    if (s > pq.top()) {
      pq.pop();
      pq.push(s);
    }
  }

  int ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
