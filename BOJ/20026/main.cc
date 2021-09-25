#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
lld N, M, C[MN*MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  M = N*(N-1) / 2;
  for (int i=0; i<M; i++) cin >> C[i];
  sort(C, C+M);

  lld mn = 0, mx = 0;
  for (int i=0; i<N-1; i++) mn += C[i];
  for (int i=0; i<N-1; i++) mx += C[i*(i+1)/2];

  cout << mn << " " << mx << endl;

  ////////////////////////////////
  return 0;
}
