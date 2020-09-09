#include "template.h"

struct BigInt {
  static const int BASE = 1e8;
  vector<int> arr;

  BigInt() { }
  BigInt(const BigInt &x) { arr = x.arr; }
  BigInt(int val) {
    for (; val > 0; val /= BASE) arr.push_back(val % BASE);
  }

  BigInt& operator +=(const BigInt &x) {
    arr.resize(max(arr.size(), x.arr.size()));
    int c = 0;
    for (int i = 0; i < arr.size(); i++) {
      arr[i] += (i < x.arr.size() ? x.arr[i] : 0) + c;
      if (c = arr[i] >= BASE) arr[i] -= BASE;
    }
    if (c > 0) arr.push_back(c);
    return *this;
  }

  BigInt operator +(const BigInt &x) const {
    return BigInt(*this) += x;
  }
};

ostream& operator <<(ostream &os, const BigInt &x) {
  if (x.arr.empty()) return os << 0;
  os << x.arr.back();
  for (int i = x.arr.size()-2; i >= 0; i--) {
    os << setfill('0') << setw(8) << x.arr[i];
  }
  return os;
}
