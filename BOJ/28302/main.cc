#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const string color = ".RGB";

int N, M;
vector<int> A, B;

int to_num(char c) {
  if (c == 'R') return 1;
  if (c == 'G') return 2;
  if (c == 'B') return 3;
  return 0;
}

struct Op {
  int t, i, x, y, z;
  void reverse() { t = 3-t; }
};

Op merge(vector<int> &S, int i) { // x <- y z
  int y = S[i], z = S[i+1], x = y^z;
  // assert(y != z);
  S.erase(S.begin()+i+1);
  S[i] = x;
  return {1, i, x, y, z};
}

Op split(vector<int> &S, int i, int y) { // x -> y z
  int x = S[i], z = x^y;
  S[i] = y;
  S.insert(S.begin()+i, z);
  return {2, i, x, y, z};
}

bool reduce(vector<int> &S, vector<Op> &ops) {
  if (S.size() == 1) return 0;
  int i = S.size() - 1;

  // merge diff
  if (S[i-1] != S[i]) {
    ops.push_back(merge(S, i-1));
    return 1;
  }
  
  // handle same 2
  if (S.size() == 2) return 0;
  if (S[i-2] != S[i-1]) {
    ops.push_back(merge(S, i-2));
    ops.push_back(merge(S, i-2));
    return 1;
  }

  // handle same 3
  int x = S[i], y = S[i]%3+1, z = x^y;
  ops.push_back(split(S, i, y));
  ops.push_back(merge(S, i-1));
  ops.push_back(merge(S, i-2));
  ops.push_back(merge(S, i-2));
  return 1;
}

void convert(vector<int> &S, vector<Op> &ops, int y) {
  int x = S[0], z = x^y;
  if (x == y) return;
  ops.push_back(split(S, 1, z));
  ops.push_back(merge(S, 0));
}

bool check(vector<int> &S, vector<int> &T, vector<Op> &ops) {
  if (S.size() != T.size()) return 0;
  if (S.size() == 1) return S[0] == T[0];
  convert(S, ops, T[0]);
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S, T;
  cin >> N >> S >> M >> T;
  for (int i=0; i<N; i++) A.push_back(to_num(S[i]));
  for (int i=0; i<M; i++) B.push_back(to_num(T[i]));

  // reduce
  vector<Op> ops;
  while (reduce(A, ops)) {}

  vector<Op> rops;
  while (reduce(B, rops)) {}

  // check
  bool ok = check(A, B, ops);
  if (!ok) return cout << -1 << endl, 0;

  // print
  reverse(all(rops));
  for (auto op: rops) op.reverse(), ops.push_back(op);

  cout << ops.size() << endl;
  for (auto [t, i, x, y, z]: ops) {
    if (t == 1) cout << t << " " << i+1 << " " << i+2 << endl;
    else cout << t << " " << i+1 << " " << color[y] << " " << color[z] << endl;
  }

  ////////////////////////////////
  return 0;
}
