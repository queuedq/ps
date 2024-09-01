#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int _;
    cin >> _ >> A[i].first >> A[i].second;
  }
  sort(A, A+N);

  priority_queue<int, vector<int>, greater<int>> pq; // currently running lessons' end time
  int ans = 0;
  for (int i=0; i<N; i++) {
    while (!pq.empty() && pq.top() <= A[i].first) pq.pop();
    pq.push(A[i].second);
    ans = max(ans, (int)pq.size());
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
