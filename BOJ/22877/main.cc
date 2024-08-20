#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, T, A[MN];
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> T >> S;
  for (int i=0; i<N; i++) {
    if (S[i] == 'S') A[i] = 0;
    if (S[i] == 'R') A[i] = 1;
    if (S[i] == 'P') A[i] = 2;
  }

  // partition into pairs (2,1), (0,2), (1,0), ...
  vector<int> P;
  int a = A[0], b = (A[0]+2)%3;
  for (int i=0; i<N; i++) {
    if (A[i] == a || A[i] == b) continue;
    P.push_back(i);
    a = A[i], b = (A[i]+2)%3;
  }
  P.push_back(N);

  // bubble sort each partition
  vector<int> ans;
  int l = 0;
  for (auto r: P) {
    int a = A[l], cnt = 0;
    for (int i=l; i<r; i++) {
      if (cnt < T && A[i] == a) cnt++;
      else ans.push_back(A[i]);
    }
    while (cnt--) ans.push_back(a);
    l = r;
  }

  for (auto a: ans) cout << "SRP"[a];
  cout << endl;

  ////////////////////////////////
  return 0;
}
