#include <bits/stdc++.h>
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, A[MN];

int main() {
  cin >> N;

  // output P
  // P1 = (1 2)
  // P2 = (1 2 3 4)
  cout << 2 << endl;

  for (int i=1; i<=N; i++) {
    if (i <= 2) cout << 3-i << " ";
    else cout << i << " ";
  }
  cout << endl;

  for (int i=1; i<=N; i++) {
    if (i == N) cout << 1 << " ";
    else cout << i+1 << " ";
  }
  cout << endl;

  // input Q
  for (int i=1; i<=N; i++) {
    int q; cin >> q;
    A[q] = i; // save inverse for bubble sort
  }

  // bubble sort
  vector<int> ans;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N-1; j++) {
      if (A[j] > A[j+1]) swap(A[j], A[j+1]), ans.push_back(1);
      ans.push_back(2);
    }
    ans.push_back(2);
  }

  // print ans
  cout << sz(ans) << " ";
  for (auto i: ans) cout << i << " ";
  cout << endl;

  return 0;
}
