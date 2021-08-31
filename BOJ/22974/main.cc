#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[55][55], tmp[55];

struct Op { char dir; int x, k; };
vector<Op> ans;

int mod(int x, int m) { return (x % m + m) % m; }

pii find(int value) {
  for (int i=value; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (A[i][j] == value) return {i, j};
    }
  }
  return {-1, -1}; // never
}

void shift(char dir, int x, int k) {
  k = mod(k, N);
  if (dir == 'R') {
    for (int i=0; i<N; i++) tmp[i] = A[x][i];
    for (int i=0; i<N; i++) A[x][i] = tmp[mod(i-k, N)];
  } else if (dir == 'D') {
    for (int i=0; i<N; i++) tmp[i] = A[i][x];
    for (int i=0; i<N; i++) A[i][x] = tmp[mod(i-k, N)];
  }
  ans.push_back({dir, x, k});
}

void cycle(int i, int j, int r, int c) { // {r, c} -> {i, j}
  if (j == c) {
    shift('R', r, 1);
    shift('D', j, r-i);
    shift('R', r, -1);
    shift('D', j, i-r);
  } else {
    shift('D', j, r-i);
    shift('R', r, j-c);
    shift('D', j, i-r);
    shift('R', r, c-j);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> A[i][j];
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (A[i][j] == i+1) continue;
      auto [r, c] = find(i+1);
      cycle(i, j, r, c);
    }
  }

  cout << ans.size() << endl;
  for (auto [dir, x, k]: ans) {
    cout << dir << " " << x+1 << " " << k << endl;
  }

  ////////////////////////////////
  return 0;
}
