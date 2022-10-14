#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int p10[4] = {1, 10, 100, 1000};
const int MN = 2020;
int N, A[MN], num[10000], digit[10000][4], sub[10000][1<<4];

int mask(int x, int m) {
  int res = 0;
  for (int k=0; k<4; k++) {
    if (m>>k & 1) res += digit[x][k];
  }
  return res;
}

int count(int x, int y, int i, int p) { // returns count of third number
  // i: decide i-th digit of p
  // p: digits to be satisfied
  if (i == 4) return num[p];

  int xd = digit[x][i];
  int yd = digit[y][i];

  if (xd == yd) {
    return count(x, y, i+1, p + xd);
  } else {
    return count(x, y, i+1, p)
      - count(x, y, i+1, p + xd)
      - count(x, y, i+1, p + yd);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  // precompute digits
  for (int x=0; x<10000; x++) {
    for (int k=0; k<4; k++) {
      digit[x][k] = (x / p10[k]) % 10 * p10[k];
    }
  }

  // precompute & count masks
  for (int i=0; i<N; i++) {
    for (int m=0; m<1<<4; m++) {
      sub[i][m] = mask(A[i], m);
      num[sub[i][m]]++;
    }
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    fill(num, num+10000, 0);
    for (int j=0; j<i; j++) {
      ans += count(A[i], A[j], 0, 0); // inclusion-exclusion
      for (int m=0; m<1<<4; m++) num[sub[j][m]]++; // add A[j]
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
