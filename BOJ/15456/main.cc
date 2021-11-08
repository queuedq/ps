#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN];

bool check(int x) {
  vector<int> B(A+1, A+x);
  sort(all(B));
  for (int i=0; i<x-1; i++) {
    if (B[i] >= N-x+1 + i) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  int l=1, r=N+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) l = m;
    else r = m;
  }
  cout << N-l << endl;

  ////////////////////////////////
  return 0;
}
