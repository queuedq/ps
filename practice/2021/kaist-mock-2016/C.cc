#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;

struct Matrix {
  lld a[32][32];

  Matrix() {
    for (int i=0; i<32; i++) fill(a[i], a[i]+32, 0);
  }

  static Matrix Xe[64];

  static Matrix id() {
    Matrix I;
    for (int i=0; i<32; i++) I.a[i][i] = 1;
    return I;
  }

  Matrix operator *(Matrix &B) {
    Matrix C;
    for (int i=0; i<32; i++) {
      for (int j=0; j<32; j++) {
        for (int k=0; k<32; k++) {
          C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % MOD;
        }
      }
    }
    return C;
  }

  vector<lld> mul(vector<lld> &vec) {
    vector<lld> res(32);
    for (int i=0; i<32; i++) {
      for (int j=0; j<32; j++) res[i] = (res[i] + a[i][j] * vec[j]) % MOD;
    }
    return res;
  }
};

lld N, K;
vector<pll> A;
Matrix X, Xe[64];

vector<lld> expmul(vector<lld> &vec, lld e) {
  vector<lld> res = vec;
  for (int i=0; e>0; i++, e/=2) {
    if (e & 1) res = Xe[i].mul(res);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<32; i++) {
    for (int j=0; j<32; j++) {
      if (i & j) continue;
      int row = 0b11111 ^ i ^ j;
      for (int k=0; k<4; k++) {
        if ((row>>k & 1) && (row>>(k+1) & 1)) row = row ^ 1<<k ^ 1<<(k+1);
      }
      if (row == 0) X.a[i][j] = 1;
    }
  }

  Xe[0] = X;
  for (int i=1; i<64; i++) Xe[i] = Xe[i-1] * Xe[i-1];

  cin >> N >> K;
  for (int i=0; i<K; i++) {
    lld x, y; cin >> x >> y;
    A.push_back({x-1, y-1});
  }
  sort(A.begin(), A.end());

  vector<lld> v(32);
  v[0] = 1;

  lld x = 0;
  for (int i=0; i<K; i++) {
    lld y = A[i].first;
    int row = 1 << A[i].second;
    while (i < K && A[i+1].first == y) {
      row |= 1 << A[++i].second;
    }

    v = expmul(v, y-x);

    for (int j=31; j>=0; j--) {
      if ((j&row) == row) v[j] = v[j ^ row];
      else v[j] = 0;
    }
    x = y;
  }
  v = expmul(v, N-x);

  cout << v[0] << endl;

  ////////////////////////////////
  return 0;
}
