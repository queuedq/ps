#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
 
////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, L[MN], R[MN];
lld x[MN], priority[MN];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
 
  cin >> N;
  for (int i=0; i<N; i++) cin >> L[i] >> R[i];
 
  x[0] = 0;
  vector<int> S = {0};
  int p = 1;
 
  for (int i=1; i<N; i++) {
    lld r = 0;
    while (!S.empty() && R[S.back()] < L[i]) {
      int j = S.back();
      S.pop_back();
      r = max(r, x[j] + R[j]);
      priority[j] = p++;
    }
 
    if (!S.empty()) x[i] = max(r, x[S.back()] + L[i]);
    else x[i] = r;
    S.push_back(i);
  }
 
  while (!S.empty()) {
    priority[S.back()] = p++;
    S.pop_back();
  }
 
  for (int i=0; i<N; i++) {
    cout << x[i] << " " << priority[i] << endl;
  }
 
  ////////////////////////////////
  return 0;
}
