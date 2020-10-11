#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, A[MAXN], B[MAXN];
int D[MAXN], E[MAXN]; // D: full cnt, E: any longest (may not be full)
int tot[MAXN], cnt[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B, B+N);
  int j = 0;
  for (int i=0; i<N; i++, j++) {
    tot[j] = 1;
    while (i < N && B[i] == B[i+1]) { i++; tot[j]++; }
  }
  int M = unique(B, B+N) - B;

  int ans = 0;
  for (int i=0; i<N; i++) {
    int j = lower_bound(B, B+M, A[i]) - B;

    if (j == 0) {
      D[j]++;
      E[j]++;
    } else {
      if (cnt[j] > 0) D[j]++;
      else if (cnt[j-1] == tot[j-1]) D[j] = D[j-1]+1;
      else D[j] = cnt[j-1]+1;

      if (cnt[j-1] == tot[j-1]) E[j] = max(E[j]+1, D[j-1]+1);
      else E[j] = max(E[j]+1, cnt[j-1]+1);
    }

    cnt[j]++;
    ans = max(ans, E[j]);
  }

  cout << N - ans << endl;

  ////////////////////////////////
  return 0;
}
