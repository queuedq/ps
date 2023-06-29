#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).cnt()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 1010;
const int MM = 305;
int N, K, M, D[MK][MM];

struct Node {
  Node *next[26], *par, *link, *go[26];
  int ch, cnt;
  int idx;

  Node *add(int i) {
    if (next[i]) return next[i];
    Node *n = new Node;
    n->par = this;
    n->ch = i;
    return next[i] = n;
  }
};
Node *root;
vector<Node *> nodes;

Node *link(Node *n) {
  if (n->par == root) return root;
  return n->par->link->go[n->ch];
}

Node *go(Node *n, int i) {
  if (n->next[i]) return n->next[i];
  if (n == root) return root;
  return n->link->go[i];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  root = new Node;
  root->par = root;

  for (int i=0; i<N; i++) {
    string S; cin >> S;
    Node *n = root;
    for (int j=0; j<sz(S); j++) n = n->add(S[j] - 'A');
    n->cnt++;
  }

  // BFS Aho-Corasick
  queue<Node *> Q({root});
  while (!Q.empty()) {
    Node *n = Q.front(); Q.pop();
    n->idx = nodes.size();
    nodes.push_back(n);
    
    n->link = link(n);
    n->cnt += n->link->cnt;
    for (int i=0; i<26; i++) {
      n->go[i] = go(n, i);
      if (n->next[i]) Q.push(n->next[i]);
    }
  }

  // DP
  M = sz(nodes);

  for (int i=K; i>=0; i--) {
    for (int j=0; j<M; j++) {
      Node *n = nodes[j];
      for (int k=0; k<26; k++) {
        D[i][j] = max(D[i][j], D[i+1][n->go[k]->idx] + n->cnt);
      }
    }
  }

  cout << D[0][0] << endl;

  ////////////////////////////////
  return 0;
}
