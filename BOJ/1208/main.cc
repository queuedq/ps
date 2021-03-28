#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 45;
const int MAX_POW = 1 << 20 + 5;
int N, S, A[MAX_N];
vector<int> sums;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < 1 << (N / 2); i++) {
    int sum = 0;
    for (int b = 0; b < N / 2; b++) {
      if (i & (1 << b)) sum += A[b];
    }
    sums.push_back(sum);
  }
  sort(sums.begin(), sums.end());

  lld ans = 0;
  for (int i = 0; i < 1 << (N - N / 2); i++) {
    int sum = 0;
    for (int b = 0; b < N - N / 2; b++) {
      if (i & (1 << b)) sum += A[b + N / 2];
    }
    int start = lower_bound(sums.begin(), sums.end(), S - sum) - sums.begin();
    int end = upper_bound(sums.begin(), sums.end(), S - sum) - sums.begin();
    ans += end - start;
  }

  cout << ans - (S == 0) << endl;

  ////////////////////////////////
  return 0;
}
