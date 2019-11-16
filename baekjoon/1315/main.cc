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
int pnt[MAX_P][MAX_P], quest[MAX_P][MAX_P];
int SP[MAX_P][MAX_P], SQ[MAX_P][MAX_P];
bool visited[MAX_P][MAX_P];

void dfs(int i, int j) {
  if (visited[i][j] || i >= MAX_P || j >= MAX_P) return;
  visited[i][j] = true;

  if (SP[i][MAX_P-1] + SP[MAX_P-1][j] - SP[i][j] > i+j-2) {
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

  for (int i = 0; i < N; i++) {
    pnt[S[i]][I[i]] += P[i];
    quest[S[i]][I[i]]++;
  }

  for (int i = 1; i < MAX_P; i++) {
    for (int j = 1; j < MAX_P; j++) {
      SP[i][j] = SP[i - 1][j] + SP[i][j - 1] - SP[i - 1][j - 1] + pnt[i][j];
      SQ[i][j] = SQ[i - 1][j] + SQ[i][j - 1] - SQ[i - 1][j - 1] + quest[i][j];
    }
  }

  dfs(1, 1);

  int ans = 0;
  for (int i = 1; i < MAX_P; i++) {
    for (int j = 1; j < MAX_P; j++) {
      if (!visited[i][j]) continue;
      ans = max(ans, SQ[i][MAX_P-1] + SQ[MAX_P-1][j] - SQ[i][j]);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
