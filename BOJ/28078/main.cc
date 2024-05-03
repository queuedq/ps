#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct GravityQueue {
  deque<char> dq; // b: ball, w: divider
  int balls = 0; // dividers = dq.size() - balls
  int rot = 0; // 0: right, 1: up, 2: left, 3: down

  void drop() {
    if (rot == 1) {
      while (!dq.empty() && dq.back() == 'b') {
        balls--;
        dq.pop_back();
      }
    } else if (rot == 3) {
      while (!dq.empty() && dq.front() == 'b') {
        balls--;
        dq.pop_front();
      }
    }
  }

  void push(char c) {
    dq.push_back(c);
    if (c == 'b') balls++;
    drop();
  }

  void pop() {
    if (dq.empty()) return;
    if (dq.front() == 'b') balls--;
    dq.pop_front();
    drop();
  }

  void rotate(char dir) {
    if (dir == 'l') rot = (rot+1) & 3;
    else rot = (rot+3) & 3;
    drop();
  }

  void count(char c) {
    if (c == 'b') cout << balls << '\n';
    else cout << (dq.size() - balls) << '\n';
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int Q; cin >> Q;
  GravityQueue gq;

  while (Q--) {
    string cmd; cin >> cmd;
    char c;

    if (cmd == "push") { cin >> c; gq.push(c); }
    else if (cmd == "pop") { gq.pop(); }
    else if (cmd == "rotate") { cin >> c; gq.rotate(c); }
    else if (cmd == "count") { cin >> c; gq.count(c); }
  }

  ////////////////////////////////
  return 0;
}
