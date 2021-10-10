#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
////////////////////////////////
const int MN = 101010;
const int ST = 1<<20;
lld N, D[MN][4], seg[ST*2];
pii A[MN];

void reset() {
  fill(seg, seg+ST*2, 0);
}

void upd(int i, lld v) {
  seg[i += ST] += v;
  for (i/=2; i>0; i/=2) {
    seg[i] = seg[i*2] + seg[i*2+1];
  }
}

lld sum(int l, int r) {
  lld res = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].first;
  for (int i=0; i<N; i++) cin >> A[i].second;
  sort(A, A+N);

  for (int i=0; i<N; i++) D[i][1] = 1;
  for (int k=2; k<=3; k++) {
    reset();
    int j=0;
    for (int i=0; i<N; i++) {
      if (i > 0 && A[i].first != A[i-1].first) {
        for (; j < i; j++) upd(A[j].second, D[j][k-1]);
      }
      D[i][k] = sum(0, A[i].second-1);
    }
  }

  lld ans = 0;
  for (int i=0; i<N; i++) ans += D[i][3];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
