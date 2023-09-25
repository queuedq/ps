#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, L, P;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    A[i] = {a, b};
  }
  cin >> L >> P;
  sort(A, A+N);

  priority_queue<int> pq;
  int i = 0;
  while (i < N && A[i].first <= P) pq.push(A[i++].second);

  int ans = 0;
  while (P < L) {
    if (pq.empty()) { cout << -1 << endl; return 0; }
    int x = pq.top(); pq.pop();
    P += x;
    while (i < N && A[i].first <= P) pq.push(A[i++].second);
    ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
