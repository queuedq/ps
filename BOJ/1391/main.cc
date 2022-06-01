#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N, A[MN];

bool check() {
  for (int i=1; i<=N-1; i++) {
    for (int j=i+2; j<=N-1; j+=2) {
      vector<pii> B;
      B.push_back({A[i], 0}); B.push_back({A[i+1], 0});
      B.push_back({A[j], 1}); B.push_back({A[j+1], 1});
      sort(all(B));
      if (B[0].second == B[2].second) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    cout << (check() ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
