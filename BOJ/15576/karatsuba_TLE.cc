#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int BASE_DIGITS = 8;
const ll BASE = 1e8;
const int MN = 303030;

ostream& operator <<(ostream &os, vector<int> v) {
  os << '[';
  for (int i=0; i<v.size(); i++) os << v[i] << ',';
  os << ']';
  return os;
}

inline int get(vector<int> A, int i) {
  if (i < A.size()) return A[i];
  return 0;
}

vector<int> add(const vector<int> &A, const vector<int> &B) {
  int N = max(A.size(), B.size());
  vector<int> res(N);

  int carry = 0;
  for (int i=0; i<N; i++) {
    res[i] = get(A, i) + get(B, i) + carry;
    if (res[i] >= BASE) { res[i] -= BASE; carry = 1; }
    else { carry = 0; }
  }
  if (carry == 1) res.push_back(1);

  while (res.size() > 1 && res.back() == 0) res.pop_back();

  return res;
}

vector<int> subtract(vector<int> &A, vector<int> &B) {
  int N = max(A.size(), B.size());
  vector<int> res(N);

  int carry = 0;
  for (int i=0; i<N; i++) {
    res[i] = get(A, i) - get(B, i) + carry;
    if (res[i] < 0) { res[i] += BASE; carry = -1; }
    else { carry = 0; }
  }

  while (res.size() > 1 && res.back() == 0) res.pop_back();

  return res;
}

vector<int> shift(const vector<int> &A, int s) {
  vector<int> res(s);
  for (int i=0; i<A.size(); i++) res.push_back(A[i]);
  return res;
}

vector<int> multiply(const vector<int> &A, const vector<int> &B) {
  int N = max(A.size(), B.size());
  if (A.size() == 0 || B.size() == 0) return {0};
  if (N == 1) {
    ll c = (ll)A[0] * B[0];
    if (c < BASE) return {(int)c};
    return {(int)(c % BASE), (int)(c / BASE)};
  }

  // A = x + 10^* y, B = z + 10^* w
  vector<int> x, y, z, w;
  x.insert(x.begin(), A.begin(), A.begin() + N/2);
  y.insert(y.begin(), A.begin() + N/2, A.end());
  z.insert(z.begin(), B.begin(), B.begin() + N/2);
  w.insert(w.begin(), B.begin() + N/2, B.end());

  auto p = multiply(x, z);
  auto q = multiply(y, w);
  auto r = multiply(add(x, y), add(z, w));
  r = subtract(r, p);
  r = subtract(r, q);
  
  r = shift(r, N/2);
  q = shift(q, N/2*2);

  auto res = add(add(p, r), q);
  return res;
}

int main() {
  vector<int> A, B;
  string as, bs; cin >> as >> bs;
  reverse(as.begin(), as.end());
  reverse(bs.begin(), bs.end());

  // fill vectors A and B
  for (int i=0; i<as.size(); i+=BASE_DIGITS) {
    int v = 0, p = 1;
    for (int j=0; j<BASE_DIGITS; j++) {
      if (i+j < as.size()) { v += (as[i+j] - '0') * p; p *= 10; }
    }
    A.push_back(v);
  }

  for (int i=0; i<bs.size(); i+=BASE_DIGITS) {
    int v = 0, p = 1;
    for (int j=0; j<BASE_DIGITS; j++) {
      if (i+j < bs.size()) { v += (bs[i+j] - '0') * p; p *= 10; }
    }
    B.push_back(v);
  }

  // multiply
  auto C = multiply(A, B);
  
  // print
  cout << C.back();
  for (int i=C.size() - 2; i >= 0; i--) {
    cout << setw(BASE_DIGITS) << setfill('0') << C[i];
  }

  return 0;
}
