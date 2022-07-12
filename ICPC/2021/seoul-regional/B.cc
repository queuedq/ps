#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, K, A[MN], cnt[MN], num, cnt2[MN], num2;

void add(int i) {
  if (cnt[A[i]] == 0) num++;
  cnt[A[i]]++;
}

void rem(int i) {
  cnt[A[i]]--;
  if (cnt[A[i]] == 0) num--;
}

void add2(int i) {
  if (cnt2[A[i]] == 0) num2++;
  cnt2[A[i]]++;
}

bool check(int i, int j) {
  if (num < K) return false;
  fill(cnt2, cnt2+K+1, 0);
  num2 = 0;
  for (int k=1; k<i; k++) add2(k);
  for (int k=j+1; k<=N; k++) add2(k);
  return num2 == K;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];

  int i = 1, ans = N+1;
  for (int j=1; j<=N; j++) {
    add(j);

    while (i <= j) {
      rem(i);
      if (num < K) { add(i); break; }
      i++;
    }

    if (check(i, j)) {
      ans = min(ans, j-i+1);
    }
  }

  if (ans == N+1) cout << 0 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
