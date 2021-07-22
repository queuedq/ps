#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1e5+5;
const int MX = 1e6+5;
int N, A[MN], prime[MX], factor[MX];
pii ans[MN];
vector<int> idx[MX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime, prime+MX, 1);
  for (int i=2; i*i<MX; i++) {
    if (prime[i]) {
      for (int j=i*2; j<MX; j+=i) prime[j] = false;
    }
  }

  for (int i=2; i<MX; i++) {
    if (!prime[i]) continue;
    for (lld j=i; j<MX; j*=i) {
      for (int k=j; k<MX; k+=j) factor[k]++;
    }
  }

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    idx[A[i]].push_back(i);
  }

  fill(ans, ans+MN, pii(INF, -1));
  
  for (int i=1; i<MX; i++) {
    pii a = {INF, -1}, b = {INF, -1};

    for (int j=i; j<MX; j+=i) {
      for (auto k: idx[j]) {
        pii f = {factor[j], k};
        if (f < a) { b = a; a = f; }
        else if (f < b) b = f;
      }
    }

    for (int j=i; j<MX; j+=i) {
      for (auto k: idx[j]) {
        if (k != a.second) {
          ans[k] = min(ans[k], {factor[j] + a.first - factor[i]*2, a.second});
        } else {
          ans[k] = min(ans[k], {factor[j] + b.first - factor[i]*2, b.second});
        }
      }
    }
  }

  for (int i=0; i<N; i++) cout << ans[i].second + 1 << endl;

  ////////////////////////////////
  return 0;
}
