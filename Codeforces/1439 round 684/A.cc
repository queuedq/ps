#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100;
int N, M;
bool A[MN][MN];

void flip(vector<pii> flips, vector<vector<pii>> &ans) {
  for (auto [i, j]: flips) A[i][j] = !A[i][j];
  ans.push_back(flips);
}

void solve() {
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<M; j++) A[i][j] = S[j] == '1';
  }

  vector<vector<pii>> ans;
  for (int i=0; i<N-2; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j]) {
        if (j == 0) {
          flip({{i, j}, {i+1, j}, {i+1, j+1}}, ans);
        } else {
          flip({{i, j}, {i+1, j-1}, {i+1, j}}, ans);
        }
      }
    }
  }

  for (int j=0; j<M-1; j++) {
    if (A[N-2][j] && A[N-1][j]) {
      flip({{N-2, j}, {N-1, j}, {N-2, j+1}}, ans);
    } else if (A[N-2][j]) {
      flip({{N-2, j}, {N-2, j+1}, {N-1, j+1}}, ans);
    } else if (A[N-1][j]) {
      flip({{N-1, j}, {N-2, j+1}, {N-1, j+1}}, ans);
    }
  }

  if (A[N-2][M-1] && A[N-1][M-1]) {
    flip({{N-2, M-2}, {N-1, M-2}, {N-2, M-1}}, ans);
    flip({{N-2, M-2}, {N-1, M-2}, {N-1, M-1}}, ans);
  } else if (A[N-2][M-1]) {
    flip({{N-2, M-2}, {N-1, M-2}, {N-2, M-1}}, ans);
    flip({{N-2, M-2}, {N-2, M-1}, {N-1, M-1}}, ans);
    flip({{N-1, M-2}, {N-2, M-1}, {N-1, M-1}}, ans);
  } else if (A[N-1][M-1]) {
    flip({{N-2, M-2}, {N-1, M-2}, {N-1, M-1}}, ans);
    flip({{N-2, M-2}, {N-2, M-1}, {N-1, M-1}}, ans);
    flip({{N-1, M-2}, {N-2, M-1}, {N-1, M-1}}, ans);
  }

  bool ok = true;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j]) ok = false;
    }
  }
  assert(ok);
  assert(ans.size() <= N*M);

  cout << ans.size() << endl;
  for (auto flips: ans) {
    for (auto [i, j]: flips) {
      cout << i+1 << " " << j+1 << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
