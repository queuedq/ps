#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 20
#define MAX_POW 60000 // 3**10
#define MAX_SUM 20000000005L
int T;
int N;
lld H, A[MAX_N], B[MAX_N];
vector<pll> S1;


lld pow(lld a, int e) {
  lld result = 1;
  for (int i = 0; i < e; i++) {
    result *= a;
  }
  return result;
}

lld calc() {
  // Reset
  S1.clear();
  S2.clear();

  // Input
  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  for (lld i = 0; i < pow(3, N / 2); i++) {
    lld ii = i;
    lld sum = 0;
    for (int b = 0; b < N / 2; b++) {
      sum += X(ii % 3, b);
      ii /= 3;
    }
    S1.push_back(sum);
  }

  for (lld i = 0; i < pow(3, N - N / 2); i++) {
    lld ii = i;
    lld sum = 0;
    for (int b = N / 2; b < N; b++) {
      sum += X(ii % 3, b);
      ii /= 3;
    }
    S2[sum]++;
  }

  lld total = 0;
  for (auto it = S1.begin(); it != S1.end(); it++) {
    lld k = *it;
    total += S2[H - k];
  }

  return total;
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
