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

struct segtree {
  static const int MX = 1<<18;
  int ST, seg[MX*2], lazy[MX*2];

  segtree(int N) {
    for (ST=1; ST<=N; ST<<=1);
    fill(seg, seg+ST*2, 0);
    fill(lazy, lazy+ST*2, -1);
  }

  void push(int n, int nl, int nr) {
    if (lazy[n] == -1 || n >= ST) return;
    int v = lazy[n];
    lazy[n] = -1;
    lazy[n*2] = lazy[n*2+1] = v;
    seg[n*2] = seg[n*2+1] = (nr-nl+1)/2 * v;
  }

  void update(int n, int nl, int nr, int l, int r, int v) {
    if (r < nl || nr < l) return;
    if (l <= nl && nr <= r) {
      lazy[n] = v;
      seg[n] = (nr-nl+1) * v;
      return;
    }

    int m = (nl+nr+1)/2;
    push(n, nl, nr);
    update(n*2, nl, m-1, l, r, v);
    update(n*2+1, m, nr, l, r, v);
    seg[n] = seg[n*2] + seg[n*2+1];
  }

  int sum(int n, int nl, int nr, int l, int r) {
    if (r < nl || nr < l) return 0;
    if (l <= nl && nr <= r) return seg[n];

    int m = (nl+nr+1)/2;
    push(n, nl, nr);
    return sum(n*2, nl, m-1, l, r) + sum(n*2+1, m, nr, l, r);
  }
};

////////////////////////////////////////////////////////////////

void solve() {
  string A, B; cin >> A >> B;
  string S = A+B;
  int a = sz(A), b = sz(B), N = a+b;

  auto sa = suffix_array(S);
  auto lcp = lcp_array(S, sa);

  // solve
  segtree seg(N);
  lld ST = seg.ST, ans = 0;

  for (int i=0; i<N; i++) {
    // truncate used array
    seg.update(1, 0, ST-1, lcp[i]+1, ST-1, 0);

    int t = sa[i];
    if (t < a) {
      // count new strings
      int lo = a-t+1, hi = N-t; // [lo, hi] = new string length range
      int cnt = seg.sum(1, 0, ST-1, lo, hi); // already used strings
      ans += (hi-lo+1) - cnt;

      // update used array
      seg.update(1, 0, ST-1, lo, hi, 1);
    }
  }

  cout << ans << endl;
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
