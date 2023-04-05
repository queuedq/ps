#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K;

struct Trie {
  static const int ALPHA_SIZE = 26;
  Trie *nodes[ALPHA_SIZE];
  int cnt = 0;

  Trie() {
    fill(nodes, nodes + ALPHA_SIZE, nullptr);
  }

  ~Trie() {
    for(int i = 0; i < ALPHA_SIZE; i++) {
      if (nodes[i]) delete nodes[i];
    }
  }

  void insert(string s) {
    Trie *c = this;
    auto it = s.begin();

    while (it != s.end()) {
      int i = *it - 'A';
      if (!c->nodes[i]) c->nodes[i] = new Trie;
      c = c->nodes[i];
      c->cnt++;

      it++;
    }
    cnt++;
  }
};

int dfs(Trie *u, int len, int &ans) {
  int groups = 0;
  for (int i=0; i<26; i++) {
    if (!u->nodes[i]) continue;
    groups += dfs(u->nodes[i], len+1, ans);
  }

  int g = (u->cnt - groups*K) / K;
  ans += len * g;
  return groups + g;
}

void calc(int test) {
  cin >> N >> K;

  Trie *trie = new Trie;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    trie->insert(s);
  }

  int ans = 0;
  dfs(trie, 0, ans);

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    calc(t);
  }

  ////////////////////////////////
  return 0;
}
