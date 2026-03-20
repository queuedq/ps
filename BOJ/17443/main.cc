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
int N, Q, A, B;
string S, T;

struct Node {
  bool empty = 1;
  // s[pre][suf]: max score of string
  // pre = 1: X... / pre = 2: OX...
  // suf = 1: ...F / suf = 2: ...FO
  lld s[3][3] = {};
  // score of single O
  lld o = -1e18;

  Node() {
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) s[i][j] = -1e18;
  }

  Node(char c, char ans) : Node() {
    empty = 0;
    if (c == 'O') {
      s[0][0] = o = ans == c ? A : 0; // O
      s[0][1] = 0; // F
    } else {
      s[1][0] = ans == c ? A : 0; // X
      s[0][1] = 0; // F
    }
  }

  lld score() {
    return max({s[0][0], s[0][1], s[0][2],
                s[1][0], s[1][1], s[1][2],
                s[2][0], s[2][1], s[2][2], o});
  }

  static Node merge(const Node &X, const Node &Y) {
    if (X.empty) return Y;
    if (Y.empty) return X;

    Node Z = {};
    Z.empty = 0;
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        lld score = -1e18;
        score = max(score, X.s[i][0] + Y.s[0][j]);
        score = max(score, X.s[i][0] + Y.s[1][j]);
        score = max(score, X.s[i][0] + Y.s[2][j]);
        score = max(score, X.s[i][1] + Y.s[0][j]);
        score = max(score, X.s[i][1] + Y.s[1][j]);
        score = max(score, X.s[i][1] + Y.s[2][j] + B); // ...F + OX...
        score = max(score, X.s[i][2] + Y.s[0][j]);
        score = max(score, X.s[i][2] + Y.s[1][j] + B); // ...FO + X...
        score = max(score, X.s[i][2] + Y.s[2][j]);
        Z.s[i][j] = score;
      }
    }

    if (X.o >= 0) Z.s[2][0] = max(Z.s[2][0], X.o + Y.s[1][0]); // O + X...
    if (Y.o >= 0) Z.s[0][2] = max(Z.s[0][2], X.s[0][1] + Y.o); // ...F + O

    return Z;
  }
};

Node seg[ST*2];

void update(int i) {
  T[i] = 'O' + 'X' - T[i];
  seg[i+ST] = Node(T[i], S[i]);
  for (i+=ST, i/=2; i>0; i/=2) seg[i] = Node::merge(seg[i*2], seg[i*2+1]);
}

lld query(int l, int r) {
  Node X, Y;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) X = Node::merge(X, seg[l++]);
    if (r&1) Y = Node::merge(seg[--r], Y);
  }
  Node Z = Node::merge(X, Y);
  return Z.score();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> A >> B >> S >> T >> Q;

  // build segtree
  for (int i=0; i<N; i++) seg[i+ST] = Node(T[i], S[i]);
  for (int i=ST-1; i>0; i--) seg[i] = seg[i*2].merge(seg[i*2], seg[i*2+1]);

  // query
  for (int q=0; q<Q; q++) {
    char qry; cin >> qry;
    if (qry == 'Q') {
      int l, r; cin >> l >> r; l--, r--;
      lld score = query(l, r);
      cout << score << endl;
    } else {
      int i; cin >> i; i--;
      update(i);
    }
  }

  ////////////////////////////////
  return 0;
}
