#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int perm[6][3] = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};
int N, A[MN], B[MN], cnt[4], G[4][4];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) { cin >> A[i]; cnt[A[i]]++; }

  int ans = N;
  for (auto [a, b, c]: perm) {
    int i = 0;
    for (int j=0; j<cnt[a]; j++) B[i++] = a;
    for (int j=0; j<cnt[b]; j++) B[i++] = b;
    for (int j=0; j<cnt[c]; j++) B[i++] = c;

    for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) G[i][j] = 0;
    for (int i=0; i<N; i++) G[A[i]][B[i]]++;
    
    int cost = 0;
    cost += min(G[1][2], G[2][1]); // swap 1 2
    cost += min(G[2][3], G[3][2]); // swap 2 3
    cost += min(G[3][1], G[1][3]); // swap 3 1
    cost += abs(G[1][2] - G[2][1]) * 2; // cycle 1 2 3
    ans = min(ans, cost);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
