#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
int N, C, A[ST], B[ST], P[ST*2], cnt[ST];

void solve(int test) {
  cin >> N >> C;
  for (int c=1; c<=C; c++) cin >> A[c] >> B[c];
  for (int i=0; i<N; i++) {
    cin >> P[i]; P[i+N] = P[i];
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    lld pans = 0;
    fill(cnt+1, cnt+C+1, 0);
    int nok = 0;

    for (int j=i; j<i+N-1; j++) {
      int c = P[j];
      bool ok = cnt[c] == 0 || (A[c] <= cnt[c] && cnt[c] <= B[c]);
      cnt[P[j]]++;
      bool ok2 = cnt[c] == 0 || (A[c] <= cnt[c] && cnt[c] <= B[c]);
      if (ok && !ok2) nok++;
      if (!ok && ok2) nok--;
      if (j > i && nok == 0) pans++;
    }

    cout << "i=" << i << " " << pans << endl;
    ans += pans;
  }

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
