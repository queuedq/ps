#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e5+5;
int N, A[MAXN], idx[MAXN], temp[MAXN], cnt[MAXN];

void merge(int l, int r) {
  if (l == r) return;
  int m = (l+r) / 2;
  merge(l, m);
  merge(m+1, r);

  int i = l, j = m+1, k = l;
  while (i <= m && j <= r) {
    if (A[idx[i]] < A[idx[j]]) {
      temp[k++] = idx[i++];
    } else {
      temp[k++] = idx[j];
      cnt[idx[j++]] += i-l;
    }
  }
  while (i <= m) {
    temp[k++] = idx[i++];
  }
  while (j <= r) {
    temp[k++] = idx[j];
    cnt[idx[j++]] += i-l;
  }

  for (int i=l; i<=r; i++) {
    idx[i] = temp[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    idx[i] = i;
  }

  merge(1, N);

  for (int i=1; i<=N; i++) {
    cout << i - cnt[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
