#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
lld F[100];

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

pll calc() {
  lld G;
  cin >> G;

  pll ba = {LLONG_MAX, LLONG_MAX};

  for (int i = 0; i < 100; i++) {
    if (F[i] > 1000000000) break;
    pll s = xgcd(F[i], F[i + 1]);
    lld x = G * s.first, y = G * s.second;
    lld bb = G / (F[i] + F[i + 1]);
    lld b = bb + (y - bb) % F[i];
    lld a = (G - b * F[i+1]) / F[i];
    while (a > b) {
      a -= F[i + 1];
      b += F[i];
    }
    if (a <= 0) continue;
    assert(a * F[i] + b * F[i+1] == G);
    ba = min(ba, {b, a});
  }

  return {ba.second, ba.first};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  F[0] = 1; F[1] = 1;
  for (int i = 2; i < 100; i++) {
    F[i] = F[i - 1] + F[i - 2];
    if (F[i] > 1000000000) break;
  }

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    pll result = calc();
    cout << result.first << " " << result.second << endl;
  }

  ////////////////////////////////
  return 0;
}
