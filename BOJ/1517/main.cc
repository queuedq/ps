#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e5+5;
int N, A[MAXN], temp[MAXN];
lld cnt;

void merge_sort(int l, int r) {
  if (l+1 == r) return;

  int mid = (l+r)/2;
  merge_sort(l, mid);
  merge_sort(mid, r);

  int j = mid, k = l;
  for (int i=l; i<mid; i++) {
    while (j < r && A[j] < A[i]) {
      temp[k++] = A[j++];
      cnt += mid - i;
    }
    temp[k++] = A[i];
  }
  while (j < r) temp[k++] = A[j++];

  for (int i=l; i<r; i++) A[i] = temp[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  merge_sort(0, N);
  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
