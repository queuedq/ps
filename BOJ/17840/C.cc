#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////
#define MAX_FIB 1000005  // 1000 * 1000
int Q, M;
vector<int> fib, fibDigits;

void input() {
  cin >> Q >> M;
}

void getFib() {
  fib.push_back(0);
  fib.push_back(1);
  while (true) {
    int i = fib.size();
    int nextFib = (fib[i - 1] + fib[i - 2]) % M;
    if (fib[i - 1] == 0 && nextFib == 1) {
      fib.pop_back();
      break;
    } else {
      fib.push_back(nextFib);
    }
  }
}

void getFibDigits() {
  for (int i = 0; i < fib.size(); i++) {
    string digits = to_string(fib[i]);
    for (int d = 0; d < digits.size(); d++) {
      fibDigits.push_back(digits[d] - '0');
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  getFib();
  getFibDigits();
  for (int i = 0; i < Q; i++) {
    lld N;
    cin >> N;
    cout << fibDigits[N % fibDigits.size()] << endl;
  }

  ////////////////////////////////
  return 0;
}
