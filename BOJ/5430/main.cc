#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct RevDeque {
  deque<int> dq;
  bool reversed = 0, error = 0;

  bool empty() { return dq.empty(); }

  void push(int x) { dq.push_back(x); } // only for initialization

  void pop() {
    if (empty()) { error = 1; return; }
    if (!reversed) dq.pop_front();
    else dq.pop_back();
  }

  void reverse() { reversed = !reversed; }

  void print() {
    if (error) { cout << "error\n"; return; }

    cout << "[";
    if (!reversed) {
      for (int i=0; i<(int)dq.size(); i++) {
        if (i > 0) cout << ",";
        cout << dq[i];
      }
    } else {
      for (int i=(int)dq.size()-1; i>=0; i--) {
        cout << dq[i];
        if (i > 0) cout << ",";
      }
    }
    cout << "]\n";
  }
};

void solve() {
  string P, arr_str;
  int N;
  cin >> P >> N >> arr_str;
  arr_str = arr_str.substr(1, arr_str.size() - 2); // remove '[', ']'

  // parse arr_str
  vector<string> arr;
  int cur = 0, pos = 0;
  while ((pos = arr_str.find(',', cur)) != string::npos) {
    arr.push_back(arr_str.substr(cur, pos - cur));
    cur = pos + 1;
  }
  arr.push_back(arr_str.substr(cur));

  // init deque
  RevDeque rdq;
  for (int i=0; i<N; i++) rdq.push(stoi(arr[i]));

  // solve
  for (int i=0; i<P.size(); i++) {
    if (P[i] == 'R') rdq.reverse();
    else if (P[i] == 'D') rdq.pop();
  }

  rdq.print();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
