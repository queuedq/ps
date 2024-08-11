#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;

vector<int> suffix_array(string &S) {
  // Reference: https://infossm.github.io/blog/2021/07/18/suffix-array-and-lcp/
  // sa, nsa: idx -> suffix
  // c, nc: suffix -> eqv class
  int N = sz(S);
  vector<int> sa(N), nsa(N), c(N), nc(N);
  vector<int> cnt(max(N, 256) + 1);
  for (int i=0; i<N; i++) sa[i] = i, c[i] = S[i];

  for (int len=1; len<N; len*=2) {
    auto cmp = [&](int i, int j) { return pii(c[i], c[(i+len)%N]) < pii(c[j], c[(j+len)%N]); };

    // sort by c[i+len]
    fill(all(cnt), 0);
    for (int i=0; i<N; i++) cnt[c[(i+len)%N]]++;
    for (int i=1; i<sz(cnt); i++) cnt[i] += cnt[i-1];
    for (int i=N-1; i>=0; i--) nsa[--cnt[c[(i+len)%N]]] = i;

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
      for (int j = sa[isa[i]-1]; len < N && S[(i+len)%N] == S[(j+len)%N]; len++);
      lcp[isa[i]] = len;
    }
  }
  return lcp;
}

struct RMQ {
  static const int ST = 1<<18;
  pii seg[ST*2];

  void init(vector<int> arr) {
    fill(seg, seg+ST*2, pii(INF, -1));
    for (int i=0; i<sz(arr); i++) seg[ST+i] = {arr[i], i};
    for (int i=ST-1; i>0; i--) seg[i] = min(seg[i*2], seg[i*2+1]);
  }

  pii get(int l, int r) {
    pii ret = {INF, -1};
    for (l+=ST, r+=ST+1; l<r; l>>=1, r>>=1) {
      if (l&1) ret = min(ret, seg[l++]);
      if (r&1) ret = min(ret, seg[--r]);
    }
    return ret;
  }
};

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, K, psum[MN*2];
string S;
vector<int> sa, lcp;
RMQ rmq;

int solve(int s, int e, int cnt, int eat) {
  int len = N, m = 0; // [s, e] lcp length, split position
  if (s < e) tie(len, m) = rmq.get(s+1, e);

  if (len > cnt) {
    int i = sa[s];
    int to_eat = psum[i+len] - psum[i+cnt+1];

    if (eat + to_eat >= K) {
      int l = cnt+1, r = len; // binary search (l: < K, r: >= K)
      while (l+1 < r) {
        int m = (l+r)/2;
        if (eat + psum[i+m] - psum[i+cnt+1] >= K) r = m;
        else l = m;
      }
      return r;
    }

    eat += to_eat;
  }

  if (s == e) return INF;
  return max(solve(s, m-1, len, eat), solve(m, e, len, eat));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K >> S;

  sa = suffix_array(S);
  lcp = lcp_array(S, sa);
  rmq.init(lcp);
  for (int i=1; i<=N*2; i++) psum[i] = psum[i-1] + (S[(i-1)%N] == 'X');

  if (find(all(S), 'O') == S.end()) {
    cout << 0 << endl; // edge case: all X
  } else {
    int ans = solve(0, N-1, 0, 0);
    if (ans == INF) cout << -1 << endl;
    else cout << ans - K << endl;
  }

  ////////////////////////////////
  return 0;
}
