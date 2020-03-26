#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
int N, S, D[MAXN];
pii A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  for (int i=1; i<=N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  sort(A+1, A+N+1);

  for (int i=1; i<=N; i++) {
    D[i] = D[i-1];
    int j = lower_bound(A+1, A+N+1, pii(A[i].first-S+1, 0)) - A;
    D[i] = max(D[i], D[j-1] + A[i].second);
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
