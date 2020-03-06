#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1000005;
int N, A[MAXN], temp[MAXN];
lld cnt;

void merge(int l, int r) {
  if (l == r) return;
  int m = (l+r) / 2;
  merge(l, m);
  merge(m+1, r);

  int i = l, j = m+1, k = l;
  while (i <= m && j <= r) {
    if (A[i] < A[j]) {
      temp[k++] = A[i++];
    } else {
      temp[k++] = A[j++];
      cnt += m-i+1;
    }
  }
  while (i <= m) {
    temp[k++] = A[i++];
  }
  while (j <= r) {
    temp[k++] = A[j++];
    cnt += m-i+1;
  }

  for (int i=l; i<=r; i++) {
    A[i] = temp[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
  }

  merge(1, N);

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
