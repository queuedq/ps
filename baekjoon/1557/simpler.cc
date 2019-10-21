#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

template<typename T>
ostream& operator << (ostream& os, vector<T> vec) {
  os << "{";
  if (vec.size() > 0) {
    copy(vec.begin(), vec.end() - 1, ostream_iterator<T>(os, ", "));
    os << *(vec.end() - 1);
  }
  os << "}";
  return os;
}

////////////////////////////////////////////////////////////////
#define SQRT_K 50000
lld K;
bool composite[SQRT_K];

lld mobius[SQRT_K];
vector<lld> SF;

void getSF() {
  for (lld i = 1; i < SQRT_K; i++) { mobius[i] = 1; }
  for (lld i = 2; i < SQRT_K; i++) {
    if (composite[i]) { continue; }
    mobius[i] = -1;
    for (lld j = i * 2; j < SQRT_K; j += i) {
      composite[j] = true;
      mobius[j] = -mobius[j];
    }
    for (lld j = i * i; j < SQRT_K; j += i * i) {
      mobius[j] = 0;
    }
  }

  for (int i = 1; i < SQRT_K; i++) {
    if (mobius[i] != 0) SF.push_back(i);
  }
}

lld squareFreesUnder(lld n) {
  lld result = 0;
  for (int i = 0; i < SF.size(); i++) {
    if (SF[i] * SF[i] > n) break;
    result += mobius[SF[i]] * (n / SF[i] / SF[i]);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  getSF();

  // cout << squareFreesUnder(45) << endl;
  // cout << squareFreesUnder(46) << endl;

  cin >> K;
  lld r = K;
  while (squareFreesUnder(r) < K) {
    r *= 2;
  }

  lld l = 0, mid = (l + r) / 2;
  while (l + 1 < r) {
    if (squareFreesUnder(mid) >= K) {
      r = mid;
      mid = (l + r) / 2;
    } else {
      l = mid;
      mid = (l + r) / 2;
    }
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
