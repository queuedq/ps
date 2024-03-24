#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
int N, Q, t = 0, in[ST], out[ST];
int cnt[ST*2], vis[ST*2], fold[ST];
vector<int> adj[ST], ord;

void dfs(int u) {
  ord.push_back(u);
  in[u] = t++;
  for (auto v: adj[u]) dfs(v);
  out[u] = t;
}

void add(int n, int nl, int nr, int l, int r, int v) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) {
    cnt[n] += v;
  } else {
    int m = (nl+nr+1)/2;
    add(n*2, nl, m-1, l, r, v);
    add(n*2+1, m, nr, l, r, v);
  }

  if (cnt[n]) vis[n] = 0;
  else if (n < ST) vis[n] = vis[n*2] + vis[n*2+1];
  else vis[n] = 1 <= n-ST && n-ST < N;
}

int kth(int n, int nl, int nr, int k) {
  if (n >= ST) return n-ST;
  int m = (nl+nr+1)/2;
  if (vis[n*2] >= k) return kth(n*2, nl, m-1, k);
  return kth(n*2+1, m, nr, k-vis[n*2]);
}

int get_folder(int cur) {
  return ord[kth(1, 0, ST-1, cur)];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int u=1; u<=N; u++) {
    int d; cin >> d;
    for (int i=0; i<d; i++) {
      int v; cin >> v;
      adj[u].push_back(v);
    }
  }

  // init
  dfs(1);

  for (int i=1; i<N; i++) vis[i+ST] = 1;
  for (int n=ST-1; n>0; n--) vis[n] = vis[n*2] + vis[n*2+1];
  
  for (int u=2; u<=N; u++) {
    fold[u] = 1;
    add(1, 0, ST-1, in[u]+1, out[u]-1, 1);
  }

  // query
  int cur = 1, u = get_folder(cur);
  for (int q=0; q<Q; q++) {
    string t; cin >> t;
    if (t == "move") {
      int k; cin >> k;
      cur = min(max(1, cur+k), vis[1]);
      u = get_folder(cur);
      cout << u << endl;
    } else {
      fold[u] ^= 1;
      add(1, 0, ST-1, in[u]+1, out[u]-1, fold[u] ? 1 : -1);
    }
  }

  ////////////////////////////////
  return 0;
}
