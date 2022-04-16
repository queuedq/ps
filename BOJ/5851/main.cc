#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, K, A[MN];
vector<int> xs;
int types, mx, cnt[MN], cnt2[MN];

void add(int a) {
  cnt2[cnt[a]]--;
  cnt[a]++;
  cnt2[cnt[a]]++;

  if (cnt[a] == 1) types++;
  mx = max(mx, cnt[a]);
}

void remove(int a) {
  cnt2[cnt[a]]--;
  cnt[a]--;
  cnt2[cnt[a]]++;

  if (cnt[a] == 0) types--;
  if (cnt2[mx] == 0) mx--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) { cin >> A[i]; xs.push_back(A[i]); }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  for (int i=1; i<=N; i++) A[i] = lower_bound(all(xs), A[i]) - xs.begin();

  int ans = 0;
  for (int i=1, j=1; i<=N; i++) {
    add(A[i]);
    while (types > K+1) {
      remove(A[j]);
      j++;
    }
    ans = max(ans, mx);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
