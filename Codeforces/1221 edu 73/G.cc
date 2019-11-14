#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 300000
#define INF 9223372036854775744

int n, m;
vector<int> adj[40];

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {

  }
}

int main() {
  input();
  solve();

  return 0;
}
