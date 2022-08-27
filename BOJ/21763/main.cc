#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101;
int N, K, A[MN][MN];

bool solve() {
  if (N == 1 && K >= 1) return 0;
  if (N == 2 && K >= 2) return 0;
  if (K > N*N - N) return 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      A[i][j] = i != j;
    }
  }
  if (N%2 == 0) {
    int l = N/2-1, r = N/2;
    swap(A[l][l], A[l][r]);
    swap(A[r][l], A[r][r]);
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;

  if (solve()) {
    cout << "YES" << endl;
    int cnt = 0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (A[i][j]) {
          cnt++;
          cout << (cnt <= K ? '#' : '.');
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  };

  ////////////////////////////////
  return 0;
}
