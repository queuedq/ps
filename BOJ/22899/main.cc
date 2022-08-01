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
int N, K, A[MN], B[MN];
vector<int> P[MN], cnt[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) {
    cin >> B[i];
    P[A[i]].push_back(B[i]);
  }
  for (int i=1; i<=N; i++) {
    sort(all(P[i]));
    for (int j=0; j<sz(P[i]); j++) cnt[j+1].push_back(P[i][j]);
  }

  lld sum = 0;
  priority_queue<int> pq;
  for (int i=1; i<=N; i++) {
    for (auto b: cnt[i]) {
      sum += b, pq.push(b);
      if (pq.size() > K) sum -= pq.top(), pq.pop();
    }
    if (pq.size() < K) cout << -1 << ' ';
    else cout << sum << ' ';
  }

  ////////////////////////////////
  return 0;
}
