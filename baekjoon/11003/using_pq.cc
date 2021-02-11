#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e6+5;
int N, L, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) cin >> A[i];

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i=0; i<N; i++) {
    pq.push({A[i], i});
    while (!pq.empty() && pq.top().second <= i-L) pq.pop();
    cout << pq.top().first << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
