#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
int N, S, A[55];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  cin >> S;

  for (int i=1; i<=N; i++) {
    int mn=A[i], k=i;
    for (int j=i+1; j<=min(i+S, N); j++) {
      if (mn < A[j]) mn = A[j], k = j;
    }
    for (int j=k; j>i; j--) swap(A[j], A[j-1]);
    S -= k-i;
  }

  for (int i=1; i<=N; i++) cout << A[i] << " ";

  ////////////////////////////////
  return 0;
}
