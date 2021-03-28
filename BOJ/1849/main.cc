#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 100'005;
const int ST = 1<<17;
int N, A[MAXN], B[MAXN], seg[ST*2];

void update(int i, int val) {
  int n = ST+i;
  for (; n > 0; n /= 2) seg[n] += val;
}

int query(int n, int nl, int nr, int k) {
  if (nl == nr) return nl;
  int mid = (nl+nr+1)/2;
  if (seg[n*2] >= k) return query(n*2, nl, mid-1, k);
  else return query(n*2+1, mid, nr, k-seg[n*2]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    update(i, 1);
  }

  for (int i=1; i<=N; i++) {
    int j = query(1, 0, ST-1, A[i]+1);
    B[j] = i;
    update(j, -1);
  }

  for (int i=1; i<=N; i++) {
    cout << B[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
