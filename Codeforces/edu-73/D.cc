#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 300000
#define INF 9223372036854775744

int q;

ll n, a[MAX_N], b[MAX_N];
ll cost[3][MAX_N];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
}

void dp() {
  cost[0][0] = 0;
  cost[1][0] = b[0];
  cost[2][0] = b[0] * 2;
  for (int i = 1; i < n; i++) {
    for (int t = 0; t < 3; t++) {
      cost[t][i] = INF;
      if (a[i - 1] != a[i] + t) {
        cost[t][i] = min(cost[t][i], cost[0][i - 1] + b[i] * t);
      }
      if (a[i - 1] + 1 != a[i] + t) {
        cost[t][i] = min(cost[t][i], cost[1][i - 1] + b[i] * t);
      }
      if (a[i - 1] + 2 != a[i] + t) {
        cost[t][i] = min(cost[t][i], cost[2][i - 1] + b[i] * t);
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   printf("cost[%d]: %lld %lld %lld\n", i, cost[0][i], cost[1][i], cost[2][i]);
  // }

  printf("%lld\n", min({cost[0][n-1], cost[1][n-1], cost[2][n-1]}));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> q;

  for (int i = 0; i < q; i++) {
    input();
    dp();
  }

  return 0;
}
