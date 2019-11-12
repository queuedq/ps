#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_S = 200005;
const int MOD = 1e9 + 7;
int N;
lld D[MAX_S];
string sentence;

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
      int i = *it - 'a';
      if (!c->nodes[i]) c->nodes[i] = new Trie;
      c = c->nodes[i];
      c->cnt++;

      it++;
    }
  }
} *trie = new Trie;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    trie->insert(s);
  }
  cin >> sentence;
}

void dp() {
  D[0] = 1;

  for (int i = 0; i <= sentence.size(); i++) {
    int j = i;
    Trie *c = trie;
    while (j < sentence.size() && c->nodes[sentence[j] - 'a']) {
      c = c->nodes[sentence[j] - 'a'];
      D[j + 1] = (D[j + 1] + D[i] * c->cnt) % MOD;
      j++;
    }
  }

  cout << D[sentence.size()] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dp();

  ////////////////////////////////
  return 0;
}
