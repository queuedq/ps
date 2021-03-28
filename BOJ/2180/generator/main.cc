#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 40000;
const int MAXN = 2e5+5;
int N;
pii A[MAXN];

bool cmp(pii a, pii b) {
  if (b == pii(0, 0)) return false;
  if (a == pii(0, 0)) return true;
  if (a.second * b.first < b.second * a.first) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  sort(A, A+N, cmp);

  int t = 0;
  for (int i=0; i<N; i++) {
    auto [a, b] = A[i];
    t = ((a+1)*t+b) % MOD;
  }
  cout << t << endl;

  ////////////////////////////////
  return 0;
}
