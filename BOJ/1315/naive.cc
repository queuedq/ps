#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 100;
const int MAX_P = 1005;
int N;
int S[MAX_N], I[MAX_N], P[MAX_N];
int usable[MAX_P][MAX_P];
bool visited[MAX_P][MAX_P];

void dfs(int i, int j) {
  if (visited[i][j] || i >= MAX_P || j >= MAX_P) { return; }
  visited[i][j] = true;

  if (usable[i][j] > i + j - 2) {
    dfs(i+1, j);
    dfs(i, j+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> I[i] >> P[i];
  }

  for (int i = 1; i < MAX_P; i++) {
    for (int j = 1; j < MAX_P; j++) {
      for (int k = 0; k < N; k++) {
        if (i >= S[k] || j >= I[k]) {
          usable[i][j] += P[k];
        }
      }
    }
  }

  dfs(1, 1);

  int ans = 0;
  for (int i = 1; i < MAX_P; i++) {
    for (int j = 1; j < MAX_P; j++) {
      if (!visited[i][j]) continue;
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        if (i >= S[k] || j >= I[k]) cnt++;
      }
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
