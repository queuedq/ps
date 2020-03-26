#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int M, K, A[22], win[5'000'000], vst[5'000'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> K;
  for (int i=0; i<K; i++) cin >> A[i];
  int B = A[K-1];

  int hash = 0;

  for (int i=0; i<B; i++) {
    win[i] = false;
    for (int j=0; j<K; j++) {
      if (i >= A[j] && !win[i-A[j]]) win[i] = true;
    }
    hash = (hash*2+win[i]) % (1<<B);
  }

  int period = 0, start = 0;

  for (int i=B; ; i++) {
    win[i] = false;
    for (int j=0; j<K; j++) {
      if (i >= A[j] && !win[i-A[j]]) win[i] = true;
    }
    hash = (hash*2+win[i]) % (1<<B);
    if (vst[hash]) {
      period = i-vst[hash];
      start = vst[hash];
      break;
    }
    vst[hash] = i;
  }

  int ans = 0;
  for (int i = start; i < start+period; i++) ans += !win[i];
  ans *= (M-start+1) / period;
  for (int i = start; i < start + (M-start+1) % period; i++) ans += !win[i];
  for (int i = 1; i < start; i++) ans += !win[i];

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
