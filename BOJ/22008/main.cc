#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20;
lld N, A[ST], first[ST], seg[ST*2];

void add(int i, int v) {
  for (i+=ST; i>0; i/=2) seg[i] += v;
}

lld sum(int l, int r) {
  int ret = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) ret += seg[l++];
    if (r&1) ret += seg[--r];
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N*2; i++) cin >> A[i];

  for (int i=1; i<=N*2; i++) {
    if (!first[A[i]]) first[A[i]] = i;
    add(i, 1);
  }

  lld ans = 0;
  for (int i=1; i<=N*2; i++) {
    int j = first[A[i]];
    if (j != i) {
      ans += sum(j+1, i-1);
      add(j, -1);
      add(i, -1);
    }
  }

  cout << ans + N << endl;

  ////////////////////////////////
  return 0;
}
