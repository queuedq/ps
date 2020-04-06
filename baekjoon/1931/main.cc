#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<pii> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A.resize(N);
  for (int i=0; i<N; i++) cin >> A[i].second >> A[i].first;
  sort(A.begin(), A.end());

  int end = 0, cnt = 0;
  for (int i=0; i<N; i++) {
    if (A[i].second >= end) {
      end = A[i].first;
      cnt++;
    }
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
