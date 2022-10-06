#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string S;
vector<pii> block, stk, ans;
int siz;

void push(pii b) {
  if (stk.empty() || stk.back().first != b.first) stk.push_back(b);
  else stk.back().second += b.second; // merge
  siz += b.second;
}

pii pop() {
  pii res = stk.back(); stk.pop_back();
  siz -= res.second;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S;

  block.push_back({S[0]-'0', 1});
  for (int i=1; i<sz(S); i++) {
    if (S[i-1] == S[i]) block.back().second++;
    else block.push_back({S[i]-'0', 1});
  }

  for (int i=0; i<sz(block); i++) {
    push(block[i]);

    if (sz(stk) >= 3) {
      auto [rc, rs] = pop();
      auto [lc, ls] = pop();
      if (ls >= rs) {
        ans.push_back({siz + ls - rs, siz + ls + rs});
        if (ls > rs) push({lc, ls - rs});
      } else {
        ans.push_back({siz, siz + ls*2});
        push({rc, rs - ls});
      }
    }
  }

  if (!stk.empty()) {
    // assert(sz(stk) == 2);
    ans.push_back({0, siz});
  }

  cout << sz(ans) << endl;
  for (auto [l, r]: ans) {
    cout << l+1 << " " << r << endl;
  }

  ////////////////////////////////
  return 0;
}
