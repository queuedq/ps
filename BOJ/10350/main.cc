#include <bits/stdc++.h>
using namespace std;
using lld = long long;

const int MN = 10101;
lld N, A[MN], S[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=1; i<=N*2; i++) S[i] = S[i-1] + A[(i-1)%N];

  lld ans = 0;
  for (int i=0; i<N; i++) {
    for (int j=i; j<i+N; j++) {
      if (S[i] > S[j]) ans += (S[i]-S[j] + S[N]-1) / S[N];
    }
  }
  cout << ans << "\n";
  return 0;
}
