#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 20'000;
const int MN = 1010;
int prime[MX];
int N, vst[MN], A[MN];

int query(int x, int k) {
  cout << "? " << x << " " << k << endl;
  int ans; cin >> ans;
  return ans;
}

int main() {
  ////////////////////////////////

  fill(prime+2, prime+MX, 1);
  for (int i=2; i<MX; i++) {
    if (prime[i]) {
      for (int j=i*2; j<MX; j+=i) prime[j] = 0;
    }
  }

  cin >> N;

  int k = N+1;
  for (int i=1; i<=N; i++) {
    if (vst[i]) continue;

    while (!prime[k]) k++;
    int x = query(i, k++);
    if (x == i) { A[x] = x, vst[x] = 1; continue; }

    int s = x;
    do {
      A[x] = query(i, k++);
      vst[x] = 1;
      x = A[x];
    } while (x != s);
  }

  cout << "! ";
  for (int i=1; i<=N; i++) cout << A[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
