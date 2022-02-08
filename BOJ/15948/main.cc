#include <bits/stdc++.h>
using namespace std;
using lld = long long;

lld N, M, vst[55], A[55];

int main() {
  cin >> N >> M;
  for (int i=0; i<M; i++) cin >> A[i];

  int j = 0;
  for (int i=0; i<M; i++) {
    if (N>>i & 1) {
      vst[i] = 1;
      A[j++] *= N>>i;
      N += 1LL<<i;
    }
  }
  for (int i=M-1; i>=0; i--) {
    if (!vst[i]) {
      A[j++] *= N>>i;
      N += 1LL<<i;
    }
  }

  for (int i=0; i<M; i++) cout << A[i] << ' ';
  return 0;
}
