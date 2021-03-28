#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e6+5;
const int MK = 3005;
int N, d, k, c, A[MN + MK], cnt[MK], num;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> d >> k >> c;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<k; i++) A[N+i] = A[i];

  for (int i=0; i<k; i++) {
    if (cnt[A[i]] == 0) num++;
    cnt[A[i]]++;
  }

  int ans = 0;
  for (int i=k; i<N+k; i++) {
    ans = max(ans, num + (cnt[c] == 0));

    if (cnt[A[i]] == 0) num++;
    cnt[A[i]]++;

    cnt[A[i-k]]--;
    if (cnt[A[i-k]] == 0) num--;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
