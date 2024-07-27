#include <bits/stdc++.h>
using namespace std;
using lld = long long;

lld N, K, num[19], p10[19];
lld D[19][2][1<<10]; // pos, match, mask

lld solve(int i, bool b, int m) {
  if (i == -1) return (__builtin_popcount(m) == K) ? 0 : -2;
  lld &ret = D[i][b][m];
  if (ret != -1) return ret;
  ret = -2;

  if (b) {
    for (int d=num[i]; d<=9; d++) {
      int mask = (m == 0 && d == 0) ? 0 : (m|1<<d); // handle leading zero
      lld val = solve(i-1, d == num[i], mask);
      if (val >= 0) return ret = val + p10[i]*d;
    }
  } else {
    for (int d=0; d<=9; d++) {
      lld val = solve(i-1, 0, m|1<<d);
      if (val >= 0) return ret = val + p10[i]*d;
    }
  }
  return ret;
}

int main() {
  cin >> N >> K;
  for (int i=0; N>0; i++, N/=10) num[i] = N % 10;

  p10[0] = 1;
  for (int i=1; i<19; i++) p10[i] = p10[i-1] * 10;

  for (int i=0; i<19; i++)
    for (int b: {0, 1})
      for (int m=0; m<1<<10; m++)
        D[i][b][m] = -1;
  
  lld ans = solve(18, 1, 0);
  cout << ans << endl;
  return 0;
}
