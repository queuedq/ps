#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

vector<int> suffix_array(string &S) {
  // Reference: https://infossm.github.io/blog/2021/07/18/suffix-array-and-lcp/
  // sa, nsa: idx -> suffix
  // c, nc: suffix -> eqv class
  int N = sz(S);
  vector<int> sa(N), nsa(N), c(N*2), nc(N*2);
  vector<int> cnt(max(N, 256) + 1);
  for (int i=0; i<N; i++) sa[i] = i, c[i] = S[i];

  for (int len=1; len<N; len*=2) {
    auto cmp = [&](int i, int j) { return pii(c[i], c[i+len]) < pii(c[j], c[j+len]); };

    // sort by c[i+len]
    fill(all(cnt), 0);
    for (int i=0; i<N; i++) cnt[c[i+len]]++;
    for (int i=1; i<sz(cnt); i++) cnt[i] += cnt[i-1];
    for (int i=N-1; i>=0; i--) nsa[--cnt[c[i+len]]] = i;

    // sort by c[i]
    fill(all(cnt), 0);
    for (int i=0; i<N; i++) cnt[c[i]]++;
    for (int i=1; i<sz(cnt); i++) cnt[i] += cnt[i-1];
    for (int i=N-1; i>=0; i--) sa[--cnt[c[nsa[i]]]] = nsa[i];

    // update c
    nc[sa[0]] = 1;
    for (int i=1; i<N; i++) nc[sa[i]] = nc[sa[i-1]] + cmp(sa[i-1], sa[i]);
    swap(c, nc);

    if (c[sa[N-1]] == N) break; // N classes -> done
  }
  return sa;
}

vector<int> lcp_array(string &S, vector<int> &sa) {
  int N = sz(S);
  vector<int> lcp(N), isa(N);
  for (int i=0; i<N; i++) isa[sa[i]] = i;
  for (int i=0, len=0; i<N; i++, len=max(len-1, 0)) {
    if (isa[i]) {
      for (int j = sa[isa[i]-1]; S[i+len] == S[j+len]; len++);
      lcp[isa[i]] = len;
    }
  }
  return lcp;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S; cin >> S;
  int N = sz(S);
  auto sa = suffix_array(S);
  auto lcp = lcp_array(S, sa);

  for (int i=0; i<N; i++) cout << sa[i]+1 << ' ';
  cout << endl;
  cout << "x ";
  for (int i=1; i<N; i++) cout << lcp[i] << ' ';
  cout << endl;

  ////////////////////////////////
  return 0;
}
