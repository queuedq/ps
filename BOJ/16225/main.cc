#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N;
pii A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].second;
  for (int i=0; i<N; i++) cin >> A[i].first;

  sort(A, A+N);
  reverse(A, A+N);

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<N; i+=2) {
    pq.push(A[i].second);
    pq.pop();
    pq.push(A[i+1].second);
  }

  lld ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
