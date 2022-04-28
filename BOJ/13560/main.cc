#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<int> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) { int a; cin >> a; A.push_back(a); }
  sort(all(A));

  for (int i=N-1; i>=0; i--) {
    if (A[i] < 0 || A[i] > i) { cout << -1 << endl; return 0; }
    for (int j=A[i]; j<i; j++) A[j]--;
    sort(A.begin(), A.begin() + i);
  }
  cout << 1 << endl;

  ////////////////////////////////
  return 0;
}
