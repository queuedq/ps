#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 500;
int N;
vector<int> matrix[MN];

void add(int i, int j) { // row[j] ^= row[i]
  for (int k=0; k<N*2; k++) matrix[j][k] ^= matrix[i][k];
}

bool solve() {
  for (int i=0; i<N; i++) {
    for (int j=i; j<N; j++) {
      if (matrix[j][i] == 1) { matrix[i].swap(matrix[j]); break; }
    }
    if (matrix[i][i] == 0) return false;

    for (int j=i+1; j<N; j++) {
      if (matrix[j][i] == 1) add(i, j);
    }
  }

  for (int i=N-1; i>=0; i--) {
    for (int j=0; j<i; j++) {
      if (matrix[j][i] == 1) add(i, j);
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    matrix[i].resize(N*2);
    for (int j=0; j<N; j++) cin >> matrix[i][j];
    matrix[i][N+i] = 1;
  }

  if (!solve()) {
    cout << -1 << endl;
    return 0;
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (matrix[i][N+j] == 1) cout << j+1 << " ";
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
