#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
const int MAXA = 2e6 + 5;
int N, A[MAXN];
int res[MAXA];
bool prime[MAXA];
vector<int> P;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime+2, prime+MAXA, true);

  for (int i=2; i*i<MAXA; i++) {
    if (!prime[i]) continue;
    for (int j=i*2; j<MAXA; j+=i) {
      prime[j] = false;
    }
  }

  for (int i=2; i<MAXA; i++) {
    if (prime[i]) P.push_back(i);
  }

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  set<int> cand;
  for (int i=0; i<50; i++) {
    int a = rand() % N, b = rand() % N;
    if (a == b) continue;
    int diff = A[a] - A[b];
    for (int p: P) {
      if (diff % p == 0) cand.insert(p);
      while (diff % p == 0) diff /= p;
      if (diff == 1) break;
    }
  }

  int maxScore = 0;
  for (int p: cand) {
    for (int i=0; i<N; i++) res[A[i] % p]++;
    for (int i=0; i<N; i++) {
      maxScore = max(maxScore, res[A[i] % p]);
      res[A[i] % p] = 0;
    }
  }

  cout << maxScore << endl;

  ////////////////////////////////
  return 0;
}
