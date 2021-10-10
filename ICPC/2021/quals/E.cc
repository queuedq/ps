#include<bits/stdc++.h>

#define endl "\n"

using namespace std;
using lld = long long;

int N, B;
double f[4005], psum[4005], psum2[4005] ;
double D[4005][35];
double rst = INFINITY;

double mean(int l, int r) {
  return (psum[r] - psum[l-1]) / (r-l+1);
}

double error(int l, int r) {
  int sz = r-l+1;
  double m = mean(l, r);
  return psum2[r] - psum2[l-1] - 2*(psum[r] - psum[l-1])*m + sz*m*m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> B;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> f[i];
    psum[i] = psum[i-1] + f[i];
    psum2[i] = psum2[i-1] + f[i]*f[i];
  }

  for (int i=1; i<=N; i++) {
    fill(D[i], D[i]+B+1, INFINITY);
    for (int j=0; j<i; j++) {
      for (int b=1; b<=B; b++) {
        D[i][b] = min(D[i][b], D[j][b-1] + error(j+1, i));
      }
    }
  }

  for (int b=1; b<=B; b++) {
    rst = min(D[N][b], rst);
  }

  cout << fixed << setprecision(9) << rst;

  return 0;
}
