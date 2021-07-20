#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, Q, ans[30005];
string W[30005];
unordered_map<string, int> idx;

struct Query {
  string word;
  int q, pos;
  bool operator <(const Query &q) const { return pos < q.pos; }
} qry[30005];

struct Trie {
  int cnt, nxt[26];
  Trie(): cnt(0) { fill(nxt, nxt+26, -1); }
};
Trie trie[30005*30];
int last = 0;

int child(int node, int alpha) {
  if (trie[node].nxt[alpha] == -1) {
    trie[node].nxt[alpha] = ++last;
  }
  return trie[node].nxt[alpha];
}

void insert(string s) {
  int node = 0;
  trie[node].cnt++;
  for (auto c: s) {
    node = child(node, c-'a');
    trie[node].cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> W[i];
    idx[W[i]] = i;
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    string word; cin >> word;
    qry[i] = {word, i, idx.count(word) != 0 ? idx[word] : N-1};
  }
  sort(qry, qry+Q);

  for (int i=0, j=0; i<Q; i++) {
    auto [word, q, pos] = qry[i];
    while (j <= pos) insert(W[j++]);

    int node = 0;
    for (auto c: word) {
      node = trie[node].nxt[c-'a'];
      if (node == -1) break;
      ans[q] += trie[node].cnt;
    }
    ans[q] += j;
  }

  for (int i=0; i<Q; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
