#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 2020;
int h, w, H, W;
int P[MX][MX], S[MX][MX];
int ids[MX], matched[MX][MX];
int fail[MX];

struct Node {
  Node *next[2], *link;
  int id; // id: pattern id

  Node *add(int i) {
    if (next[i]) return next[i];
    return next[i] = new Node;
  }
};

Node *root;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> h >> w >> H >> W;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      char c; cin >> c;
      P[i][j] = c == 'o';
    }
  }
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      char c; cin >> c;
      S[i][j] = c == 'o';
    }
  }

  // build trie
  root = new Node;
  root->link = root;
  for (int i=0; i<h; i++) {
    Node *u = root;
    for (int j=0; j<w; j++) u = u->add(P[i][j]);
    if (!u->id) u->id = i+1;
    ids[i] = u->id;
  }

  // aho-corasick
  queue<Node *> Q;
  for (int i=0; i<2; i++) {
    Node *u = root->next[i];
    if (u) u->link = root, Q.push(u);
  }

  while (!Q.empty()) {
    Node *u = Q.front(); Q.pop();
    for (int i=0; i<2; i++) {
      if (!u->next[i]) continue;

      Node *p = u->link;
      while (p != root && !p->next[i]) p = p->link;
      if (p->next[i]) p = p->next[i];
      
      u->next[i]->link = p;
      Q.push(u->next[i]);
    }
  }

  // match rows
  for (int i=0; i<H; i++) {
    Node *u = root;
    for (int j=0; j<W; j++) {
      int c = S[i][j];
      while (u != root && !u->next[c]) u = u->link;
      if (u->next[c]) u = u->next[c];
      
      matched[i][j] = u->id;
    }
  }

  // kmp failure
  fail[1] = 0;
  for (int i=1; i<h; i++) {
    int p = fail[i];
    while (p && ids[p] != ids[i]) p = fail[p];
    if (ids[p] == ids[i]) p++;
    fail[i+1] = p;
  }

  // kmp match
  int ans = 0;
  for (int j=0; j<W; j++) {
    int p = 0;
    for (int i=0; i<H; i++) {
      while (p && ids[p] != matched[i][j]) p = fail[p];
      if (ids[p] == matched[i][j]) p++;
      if (p == h) ans++, p = fail[p];
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
