#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, A[MN], S[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) S[i] = S[i-1] + A[i];

  for (int j=0; j<M; j++) {
    int l, r; cin >> l >> r;
    cout << S[r] - S[l-1] << '\n';
  }

  ////////////////////////////////
  return 0;
}
