#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 105;
int A[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
pll small[MAX_N];
pll zero[MAX_N];

lld pow(int n) {
  lld ret = 1;
  while (n--) {
    ret *= 10;
  }
  return ret;
}

void dp() {
  fill(zero, zero + MAX_N, (pll){LLONG_MAX, 0});
  fill(small, small + MAX_N, (pll){LLONG_MAX, 0});
  zero[0] = {0, 0};
  small[0] = {0, 0};

  for (int i = 0; i <= 100; i++) {
    if (i - A[0] >= 0) {
      pll pz = zero[i - A[0]];
      pll ps = small[i - A[0]];
      if (pz.first != LLONG_MAX) {
        pz.first++;
        zero[i] = min(zero[i], pz);
      }
      if (ps.first != LLONG_MAX) {
        ps.first++;
        zero[i] = min(zero[i], ps);
      }
    }

    for (int d = 1; d < 10; d++) {
      if (i - A[d] >= 0) {
        pll pz = zero[i - A[d]];
        pll ps = small[i - A[d]];
        if (pz.first != LLONG_MAX) {
          pz.second += pow(pz.first) * d;
          pz.first++;
          small[i] = min(small[i], pz);
        }
        if (ps.first != LLONG_MAX) {
          ps.second += pow(ps.first) * d;
          ps.first++;
          small[i] = min(small[i], ps);
        }
      }
    }
    // cout << i << " " << zero[i].first << " " << zero[i].second << " " << small[i].first << " " << small[i].second << endl;
  }
}

string large(int n) {
  string s;
  if (n % 2 == 1) {
    s += "7";
    n -= 3;
  }
  while (n) {
    s += "1";
    n -= 2;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  dp();

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    cout << small[N].second << " " << large(N) << endl;
  }

  ////////////////////////////////
  return 0;
}
