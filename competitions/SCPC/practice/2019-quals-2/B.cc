#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5005;
int N, A[MAXN], B[MAXN];

int solve() {
  int ans = 0, base = 0;

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) {
    cin >> B[i];
    if (A[i] == B[i]) base++;
  }

  for (int i=0; i<N; i++) {
    int score = base;
    for (int j=0; j<N; j++) {
      if (i-j < 0 || i+j >= N) break;
      if (A[i-j] == B[i-j]) score--;
      if (A[i+j] == B[i+j]) score--;
      if (A[i-j] == B[i+j]) score++;
      if (A[i+j] == B[i-j]) score++;
      ans = max(ans, score);
    }

    score = base;
    for (int j=0; j<N; j++) {
      if (i-j < 0 || i+j+1 >= N) break;
      if (A[i-j] == B[i-j]) score--;
      if (A[i+j+1] == B[i+j+1]) score--;
      if (A[i-j] == B[i+j+1]) score++;
      if (A[i+j+1] == B[i-j]) score++;
      ans = max(ans, score);
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << endl;
    cout << solve() << endl;
  }

  ////////////////////////////////
  return 0;
}
