#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 100'005;
int N, A[MAXN], sum[MAXN], B[MAXN];

void update(int i, int val) {
  i++;
  while (i < MAXN) {
    sum[i] += val;
    i += i & -i;
  }
}

int query(int i) {
  i++;
  int ans = 0;
  while (i > 0) {
    ans += sum[i];
    i -= i & -i;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    update(i, 1);
  }

  for (int i = 0; i < N; i++) {
    int l = -1, r = N;
    while (l+1 < r) {
      int mid = (l+r)/2;
      if (query(mid) >= A[i]+1) r = mid;
      else l = mid;
    }
    B[r] = i+1;
    update(r, -1);
  }

  for (int i = 0; i < N; i++) {
    cout << B[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
