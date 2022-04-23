#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[5050], D[5050];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  int mx = 0;
  for (int i=0; i<N; i++) {
    D[i] = 1;
    for (int j=0; j<i; j++) {
      if (A[i] % A[j] == 0) D[i] = max(D[i], D[j] + 1);
    }
    mx = max(mx, D[i]);
  }

  cout << N - mx << endl;

  ////////////////////////////////
  return 0;
}
