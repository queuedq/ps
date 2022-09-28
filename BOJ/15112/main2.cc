#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;

struct Op { char t; lld i; char c; };
struct Block {
  lld orig, st, len; char c;
  bool operator ==(const Block &B) const {
    return make_tuple(orig, st, len, c) == make_tuple(B.orig, B.st, B.len, B.c);
  }
};
Block substr(lld st, lld len) { return {1, st, len, 0}; }
Block chr(char c) { return {0, 0, 1, c}; }

vector<Block> run(const vector<Op> &seq) {
  vector<Block> S = {substr(0, INF)};

  for (auto [t, i, c]: seq) {
    int k;
    for (k=0; k<sz(S); k++) {
      if (i < S[k].len) break; // apply op at this block
      i -= S[k].len;
    }

    // apply op
    if (S[k].orig) {
      if (t == 'I') {
        Block L = substr(S[k].st, i);
        Block R = substr(S[k].st+i, S[k].len-i);
        S.erase(S.begin()+k);
        if (R.len > 0) S.insert(S.begin()+k, R);
        S.insert(S.begin()+k, chr(c));
        if (L.len > 0) S.insert(S.begin()+k, L);
      } else {
        Block L = substr(S[k].st, i);
        Block R = substr(S[k].st+i+1, S[k].len-i-1);
        S.erase(S.begin()+k);
        if (R.len > 0) S.insert(S.begin()+k, R);
        if (L.len > 0) S.insert(S.begin()+k, L);
      }
    } else {
      if (t == 'I') S.insert(S.begin()+k, chr(c));
      else {
        S.erase(S.begin()+k);
        // heal up
        if (1<=k && k<sz(S) && S[k-1].orig && S[k].orig &&
            S[k-1].st + S[k-1].len == S[k].st) {
          S[k-1].len += S[k].len;
          S.erase(S.begin()+k);
        }
      }
    }
  }

  return S;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  vector<Block> S[2];
  for (auto k: {0, 1}) {
    vector<Op> ops;
    while (1) {
      char t, c; lld i; cin >> t;
      if (t == 'D') { cin >> i; ops.push_back({t, i, 0}); }
      else if (t == 'I') { cin >> i >> c; ops.push_back({t, i, c}); }
      else break;
    }
    S[k] = run(ops);
  }

  cout << (S[0] == S[1] ? 0 : 1) << endl;

  ////////////////////////////////
  return 0;
}
