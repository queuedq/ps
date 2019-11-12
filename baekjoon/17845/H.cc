#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////
#define MAX_N 10005
#define MAX_K 1005
int N, K;
lld I[MAX_K], T[MAX_K];
lld score[MAX_N];

void input() {
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> I[i] >> T[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  for (int i = 0; i < K; i++) {
    for (int j = N; j >= 0; j--) {
      int prev = j - T[i];
      if (prev < 0) { continue; }
      score[j] = max(score[j], score[prev] + I[i]);
    }
  }

  lld m = 0;
  for (int i = 0; i <= N; i++) {
    m = max(score[i], m);
  }
  cout << m << endl;

  ////////////////////////////////
  return 0;
}
