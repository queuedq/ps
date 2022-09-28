#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

// WA: didn't re-normalize (I i), (D i+1), (I i+1) to (I i) x2
// Example:
// I 4 X
// I 3 A 
// I 3 B
// D 5 
// E
// I 4 X
// D 3
// I 3 B
// I 4 A
// E

struct Op {
  char t; lld i; char c;
  bool operator ==(const Op &O) const {
    return make_tuple(t, i, c) == make_tuple(O.t, O.i, O.c);
  }
};

vector<Op> normalize(const vector<Op> &seq) {
  vector<Op> ops;

  for (auto [typ, idx, c]: seq) {
    int k;
    for (k=0; k<sz(ops); k++) {
      if (ops[k].i > idx) break; // found correct idx
      if (ops[k].t == 'D') idx++;
      else { // ops[k].t == 'I'
        if (ops[k].i < idx) idx--;
        else break; // ops overlap
      }
    }

    if (k == sz(ops)) ops.push_back({typ, idx, c});
    else {
      if (ops[k].i == idx && typ == 'D' && ops[k].t == 'I')
        ops.erase(ops.begin() + k); // annihilate
      else
        ops.insert(ops.begin() + k, {typ, idx, c});
    }
  }
  return ops;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  vector<Op> ops[2];
  for (auto k: {0, 1}) {
    vector<Op> seq;
    while (1) {
      char t, c; lld i; cin >> t;
      if (t == 'D') { cin >> i; seq.push_back({t, i, 0}); }
      else if (t == 'I') { cin >> i >> c; seq.push_back({t, i, c}); }
      else break;
    }
    ops[k] = normalize(seq);
  }

  // for (auto k: {0, 1}) {
  //   for (auto [t, i, c]: ops[k]) {
  //     if (t == 'D') cout << t << " " << i << endl;
  //     else cout << t << " " << i << " " << c << endl;
  //   }
  //   cout << endl;
  // }

  cout << (ops[0] == ops[1] ? 0 : 1) << endl;

  ////////////////////////////////
  return 0;
}
