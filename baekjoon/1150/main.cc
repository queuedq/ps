#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const int INF = 2e9;
int N, K, S[MAXN];

struct Node {
  int w, l, r;
  Node(): w(-1), l(-1), r(-1) {}
  Node(int w, int l, int r): w(w), l(l), r(r) {}
  bool operator <(const Node &n) const { return w > n.w; }
};

Node L[MAXN], R[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> S[i];

  priority_queue<Node> pq;

  for (int i=0; i<N-1; i++) {
    int w = S[i+1]-S[i];
    Node n = {w, i, i+1};
    L[i] = n;
    R[i+1] = n;
    pq.push(n);
  }

  int ans = 0;

  for (int i=0; i<K; ) {
    Node n = pq.top(); pq.pop();
    if (L[n.l].r != n.r) continue;

    ans += n.w;

    Node left = R[n.l], right = L[n.r];
    if (left.w != -1 && right.w != -1) {
      Node m = {left.w + right.w - n.w, left.l, right.r};
      L[m.l] = R[m.r] = m;
      L[n.l] = R[n.l] = L[n.r] = R[n.r] = Node();
      pq.push(m);
    } else {
      if (left.w != -1) L[left.l] = R[left.r] = Node();
      if (right.w != -1) L[right.l] = R[right.r] = Node();
      L[n.l] = R[n.r] = Node();
    }

    i++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
