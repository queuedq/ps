#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
lld P, B, N;
vector<pll> baby;

pll xgcd(lld a, lld b) {
  lld x1 = 1, y1 = 0, x2 = 0, y2 = 1;
  while (b > 0) {
    lld q = a / b, r = a % b;
    a = b; b = r;
    lld X = x1 - x2 * q;
    lld Y = y1 - y2 * q;
    x1 = x2; y1 = y2; x2 = X; y2 = Y;
  }
  return {x1, y1};
}

lld modinv(lld a, lld n) {
  pll v = xgcd(a, n);
  return (v.first + n) % n;
}

void bsgs() {
  // Reset
  baby.clear();
  lld sqrtP = floor(sqrt(P));
  lld output = -1;

  // Baby Step
  lld pow1 = 1;
  for (lld i = 0; i < sqrtP; i++) {
    baby.push_back({pow1, i});
    pow1 = pow1 * B % P;
  }
  sort(baby.begin(), baby.end());

  // Giant Step
  lld pow2 = 1;
  for (lld i = 0; i < P; i+= sqrtP) {
    lld toFind = modinv(pow2, P) * N % P;
    auto at = lower_bound(baby.begin(), baby.end(), (pll){toFind, -1});
    if (at != baby.end() && at->first == toFind) {
      output = i + at->second;
      break;
    }
    pow2 = pow2 * pow1 % P;
  }

  if (output == -1) {
    cout << "no solution" << endl;
  } else {
    cout << output << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (cin >> P >> B >> N) {
    bsgs();
  }

  ////////////////////////////////
  return 0;
}
