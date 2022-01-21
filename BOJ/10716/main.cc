#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int INF = 1e9+1;
int N, M, A[MN], B[MN];
int tree[MN*2][3], cnt[MN*2], D[MN*2];
// cnt: current count of >= x
// D: min count of >= x to make median >= x

bool check(int x) {
  for (int i=1; i<=N; i++) {
    cnt[i] = A[i] >= x;
    if (A[i] == 0) D[i] = 1;
    else D[i] = A[i] < x ? INF : 1;
  }

  for (int i=N+1; i<=N+N/2; i++) {
    int a = tree[i][0];
    int b = tree[i][1];
    int c = tree[i][2];
    cnt[i] = cnt[a] + cnt[b] + cnt[c];
    D[i] = min({
      D[a] + D[b] + cnt[c],
      D[b] + D[c] + cnt[a],
      D[c] + D[a] + cnt[b],
      INF
    });
  }

  int num = 0;
  for (int i=1; i<=N; i++) num += A[i] >= x;
  for (int i=1; i<=N-M; i++) num += B[i] >= x;

  return num >= D[N+N/2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int d, p; cin >> d >> p;
    A[p] = d;
  }
  for (int i=1; i<=N-M; i++) cin >> B[i];

  for (int i=1, j=N+1; j<=N+N/2; i+=3, j++) {
    tree[j][0] = i;
    tree[j][1] = i+1;
    tree[j][2] = i+2;
  }
  
  int l = 0, r = 1e9+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) l = m;
    else r = m;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
