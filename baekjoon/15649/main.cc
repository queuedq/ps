#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 9;
int N, M;

void dfs(vector<int> A) {
  if (A.size() == M) {
    for (auto a: A) cout << a << " ";
    cout << endl;
    return;
  }

  bool used[MAXN];
  fill(used+1, used+N+1, false);
  for (auto a: A) used[a] = true;
  for (int i=1; i<=N; i++) {
    if (used[i]) continue;
    A.push_back(i);
    dfs(A);
    A.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  vector<int> A;
  dfs(A);

  ////////////////////////////////
  return 0;
}
