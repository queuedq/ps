#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, C[MN];
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i].second >> A[i].first;
  for (int i=0; i<M; i++) cin >> C[i];
  sort(A, A+N);
  sort(C, C+M);

  int cnt = 0;
  for (int i=N-1; i>=0; i--) {
    if (A[i].second <= C[M-1-cnt]) cnt++;
  }
  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
