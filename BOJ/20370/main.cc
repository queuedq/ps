#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 80'005;
lld N, K;

struct Score { lld a, b; };
Score X[MN];
lld L[MN], R[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> X[i].a;
  for (int i=1; i<=N; i++) cin >> X[i].b;
  sort(X+1, X+N+1, [](Score x, Score y) { return x.b < y.b; });
  
  priority_queue<lld> pq;
  lld asum = 0, sum = 0;
  for (int i=N; i>N-K; i--) {
    asum += X[i].a;
    pq.push(X[i].a + X[i].b); sum += X[i].a + X[i].b;
  }

  R[N-K+1] = asum - sum;
  for (int i=N-K; i>N-K-K; i--) {
    asum += X[i].a;
    pq.push(X[i].a + X[i].b); sum += X[i].a + X[i].b;
    sum -= pq.top(); pq.pop();
    R[i] = asum - sum;
  }

  pq = priority_queue<lld>();
  asum = sum = 0;
  for (int i=1; i<=N-K-K; i++) {
    asum += X[i].a;
    pq.push(X[i].a); sum += X[i].a;
  }

  L[N-K-K] = 0;
  for (int i=N-K-K+1; i<=N-K; i++) {
    asum += X[i].a;
    pq.push(X[i].a); sum += X[i].a;
    sum -= pq.top(); pq.pop();
    L[i] = asum - sum;
  }

  lld ans = LLONG_MIN;
  for (int i=N-K-K; i<=N-K; i++) ans = max(ans, L[i] + R[i+1]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
