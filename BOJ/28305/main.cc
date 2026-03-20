#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, T, A[MN], S[MN];

bool check(int M) {
  for (int i=0; i<N; i++) {
    S[i] = max(1, A[i]-T+1);
    if (i >= M) S[i] = max(S[i], S[i-M]+T);
    if (S[i] > A[i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> T;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);

  int l=0, r=N;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) r = m;
    else l = m;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
