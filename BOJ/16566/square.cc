#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 4'000'005;
int N, M, K, cnt[MN];
vector<int> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  A.resize(M);
  for (int i=0; i<M; i++) {
    int a; cin >> a;
    cnt[a]++;
  }
  for (int i=1, j=0; i<=N; i++) if (cnt[i]) A[j++] = i;

  for (int q=0; q<K; q++) {
    int b; cin >> b;
    int i = upper_bound(all(A), b) - A.begin();
    while (!cnt[A[i]]) i++;
    cnt[A[i]] = 0;
    cout << A[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
