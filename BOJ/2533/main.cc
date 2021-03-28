#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 1000005
int N;
vector<int> adj[MAX_N];
bool visited[MAX_N];
bool early[MAX_N];
int numEarly = 0;

void input() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void dfs(int c) {
  visited[c] = true;
  int cnt = 0;
  for (int node: adj[c]) {
    if (visited[node]) continue;
    dfs(node);
    if (!early[node]) cnt++;
  }
  if (cnt != 0) {
    early[c] = true;
    numEarly++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dfs(1);
  // for (int i = 1; i <= N; i++) {
  //   cout << early[i] << endl;
  // }
  cout << numEarly << endl;

  ////////////////////////////////
  return 0;
}
