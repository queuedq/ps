#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
vector<pii> TREE[30];
vector<int> adj[MAXN];
int cnt = 0;

void expand(int N, int u) {
  TREE[N+5] = TREE[N];
  TREE[N+5].push_back({u, N+1});
  TREE[N+5].push_back({u, N+3});
  TREE[N+5].push_back({u, N+5});
  TREE[N+5].push_back({N+1, N+2});
  TREE[N+5].push_back({N+3, N+4});
}

void construct(int N) {
  if (6 <= N && N <= 24) {
    for (auto [u, v]: TREE[N]) {
      adj[cnt+u].push_back(cnt+v);
      adj[cnt+v].push_back(cnt+u);
    }
    cnt += N;
    return;
  }
  construct(11);
  int a = cnt;
  construct(N-11-3);
  int b = cnt;
  adj[b+1].push_back(a); adj[a].push_back(b+1);
  adj[b+1].push_back(b); adj[b].push_back(b+1);
  adj[b+1].push_back(b+2); adj[b+2].push_back(b+1);
  adj[b+1].push_back(b+3); adj[b+3].push_back(b+1);
  cnt += 3;
}

void print(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    cout << u << " " << v << endl;
    print(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  TREE[6] = { {1,2}, {2,3}, {3,4}, {4,5}, {4,6} };
  TREE[7] = { {1,2}, {2,3}, {3,4}, {3,5}, {5,6}, {5,7} };
  TREE[8] = { {1,2}, {2,3}, {3,4}, {3,5}, {5,6}, {6,7}, {6,8} };
  TREE[9] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}, {2,8}, {6,9} };
  TREE[10] = { {1,2}, {2,3}, {3,4}, {4,5}, {4,6}, {3,7}, {7,8}, {7,9}, {2,10} };
  TREE[11] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}, {7,8}, {2,9}, {7,10}, {4,11} };

  expand(7, 4); expand(12, 6); expand(17, 7);
  expand(8, 4); expand(13, 7); expand(18, 8);
  expand(9, 1); expand(14, 7); expand(19, 8);
  expand(10, 5); expand(15, 6);
  expand(11, 1); expand(16, 8);

  expand(6, 5); // modularize TREE[11]

  int N; cin >> N;
  construct(N);
  // test(N);
  print(1, 0);

  ////////////////////////////////
  return 0;
}
