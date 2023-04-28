#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// It is possible to make multiple of N using at most two digits!
// Proof: construct using 0, 1
// - Start from some number with remainder r (initially r = 1)
// - Repeatedly multiply 10 and stop right before returning back to r
// - Now multiply 10 and add 1, you get remainder r+1
// - Repeat until r becomes 0
const int MN = 30005;
int N;

struct State { // remainder, using one(a) or two(a,b) digits
  int r=0, a=0, b=-1;
  int hash() { return r*110 + (b+1)*10 + a; }

  State next(int d) { 
    if (a == d || b == d) return {(r*10+d)%N, a, b};
    if (b != -1) return {0, -1, -1};
    if (a < d) return {(r*10+d)%N, a, d};
    return {(r*10+d)%N, d, a};
  }
};
struct Edge { int prv=-1, d=-1; };
Edge edge[MN*110];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  if (N < 10) { cout << N << endl; return 0; }

  queue<State> Q;
  for (int d=1; d<=9; d++) {
    State st = {d, d, -1};
    edge[st.hash()] = {0, d};
    Q.push(st);
  }

  // bfs
  State M1 = {0, -1, -1};
  State M2 = {0, -1, -1};
  while (!Q.empty()) {
    auto state = Q.front(); Q.pop();

    for (int d=0; d<=9; d++) {
      State nxt = state.next(d);
      if (edge[nxt.hash()].prv != -1) continue; // visited
      edge[nxt.hash()] = {state.hash(), d};

      Q.push(nxt);
      if (nxt.r == 0) { // found
        if (nxt.b == -1 && M1.a == -1) M1 = nxt;
        if (nxt.b != -1 && M2.a == -1) M2 = nxt;
      }
    }
  }
  State M = (M1.a != -1) ? M1 : M2;

  // traceback
  vector<int> digits;
  int i = M.hash();
  while (i != 0) {
    digits.push_back(edge[i].d);
    i = edge[i].prv;
  }
  reverse(all(digits));

  for (auto d: digits) cout << d;
  cout << endl;

  ////////////////////////////////
  return 0;
}
