#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<pair<pii, int>> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A.resize(N);
  for (int i=0; i<N; i++) {
    cin >> A[i].first.first >> A[i].first.second;
    A[i].second = i+1;
  }

  sort(A.begin(), A.end());

  cout << N*2-1 << endl;
  for (int i=0; i<N; i++) cout << A[i].second << " ";
  for (int i=N-2; i>=0; i--) cout << A[i].second << " ";

  ////////////////////////////////
  return 0;
}
