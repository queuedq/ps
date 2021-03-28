#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const int MAXP = 1e6+5;
int N, A[MAXN];
bool isprime[1005];
vector<int> prime;
lld D[2][MAXP];

vector<int> factor(int n) {
  vector<int> res;
  for (auto p: prime) {
    if (n % p != 0) continue;
    res.push_back(p);
    while (n % p == 0) n /= p;
  }
  if (n > 1) res.push_back(n);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(isprime+2, isprime+1005, true);
  for (int i=2; i*i<1005; i++) {
    if (!isprime[i]) continue;
    for (int j=i*2; j<1005; j+=i) isprime[j] = false;
  }

  for (int i=2; i<1005; i++) {
    if (isprime[i]) prime.push_back(i);
  }


  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  lld ans = 0;
  for (int i=0; i<N; i++) {
    vector<int> F = factor(A[i]);

    for (int b=0; b<1<<F.size(); b++) {
      int divisor = 1, sgn = 1;
      for (int m=0; m<F.size(); m++) {
        if (b & (1<<m)) {
          divisor *= F[m];
          sgn *= -1;
        }
      }
      ans += sgn * D[1][divisor];
    }

    for (int b=0; b<1<<F.size(); b++) {
      int divisor = 1;
      for (int m=0; m<F.size(); m++) {
        if (b & (1<<m)) divisor *= F[m];
      }
      D[1][divisor] += D[0][divisor];
    }

    for (int b=0; b<1<<F.size(); b++) {
      int divisor = 1;
      for (int m=0; m<F.size(); m++) {
        if (b & (1<<m)) divisor *= F[m];
      }
      D[0][divisor]++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
