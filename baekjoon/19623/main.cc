#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, D[MAXN];

struct Meeting {
  int s, e, w;
  bool operator <(Meeting m) const { return e < m.e; }
} A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].s >> A[i].e >> A[i].w;
  sort(A, A+N);

  for (int i=0; i<N; i++) {
    D[i] = i>0 ? D[i-1] : 0;
    int j = upper_bound(A, A+N, (Meeting){0, A[i].s, 0}) - A - 1;
    D[i] = max(D[i], (j>=0 ? D[j] : 0) + A[i].w);
  }
  
  cout << D[N-1] << endl;

  ////////////////////////////////
  return 0;
}
