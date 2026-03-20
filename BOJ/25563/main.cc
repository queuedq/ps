#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 1<<20;
int N, K, A[MX];
lld cnt[MX], sub[MX], super[MX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }

  for (int i=0; i<MX; i++) {
    sub[i] = super[i] = cnt[i];
  }

  // zeta transform
  for (int k=0; k<20; k++) {
    int mask = (1<<k);
    for (int i=0; i<MX; i++) {
      if (i & mask) sub[i] += sub[i ^ mask];
      else super[i] += super[i ^ mask];
    }
  }

  // convolution
  for (int i=0; i<MX; i++) {
    sub[i] = sub[i] * sub[i];
    super[i] = super[i] * super[i];
  }

  // inverse zeta transform
  for (int k=0; k<20; k++) {
    int mask = (1<<k);
    for (int i=0; i<MX; i++) {
      if (i & mask) sub[i] -= sub[i ^ mask];
      else super[i] -= super[i ^ mask];
    }
  }

  lld ans_and = super[K];
  lld ans_or = sub[K];

  // xor: naive approach
  lld ans_xor = 0;
  for (int i=0; i<MX; i++) ans_xor += cnt[i] * cnt[i^K];

  // remove duplicates
  for (int i=0; i<N; i++) {
    if (A[i] == K) ans_and--, ans_or--;
    if (0 == K) ans_xor--;
  }
  ans_and /= 2, ans_or /= 2, ans_xor /= 2;

  cout << ans_and << " " << ans_or << " " << ans_xor << endl;

  ////////////////////////////////
  return 0;
}
