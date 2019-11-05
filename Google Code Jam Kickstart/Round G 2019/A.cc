#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 100005
int T;
int N, M, Q, P[MAX_N], R[MAX_N];
int D[MAX_N];

void divisors(int n) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (n == i * i) {
        D[i]++;
      } else {
        D[i]++;
        D[n / i]++;
      }
    }
  }
}

lld calc() {
  // Reset
  for (int i = 0; i <= MAX_N; i++) {
    D[i] = 0;
  }

  // Input
  cin >> N >> M >> Q;
  for (int i = 0; i < M; i++) {
    cin >> P[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> R[i];
  }

  for (int i = 0; i < M; i++) {
    divisors(P[i]);
  }
  lld result = 0;
  for (int i = 0; i < Q; i++) {
    result += N / R[i] - D[R[i]];
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
