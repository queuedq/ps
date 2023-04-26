#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void suffix_array(string S, vector<int> &sa, vector<int> &lcp) {
  // Reference: https://infossm.github.io/blog/2021/07/18/suffix-array-and-lcp/
  
  // sa, idx: -> sorted suffix
  // b, nb: suffix -> bucket
  // cnt: bucket -> size
  int N = sz(S);
  sa.resize(N);
  vector<int> idx(N), b(N*2), nb(N*2), cnt(max(N, 256)+1);

  for(int i=0; i<N; i++) sa[i] = i, b[i] = S[i];

  for (int len=1; len<N; len<<=1) {
    auto cmp = [&](int i, int j){ return pii(b[i], b[i+len]) < pii(b[j], b[j+len]); };

    // sort by b[i+len]
    fill(all(cnt), 0);
    for (int i=0; i<N; i++) cnt[b[i+len]]++;
    for (int i=1; i<sz(cnt); i++) cnt[i] += cnt[i-1];
    for (int i=N-1; i>=0; i--) idx[--cnt[b[i+len]]] = i;

    // sort by b[i]
    fill(all(cnt), 0);
    for (int i=0; i<N; i++) cnt[b[i]]++;
    for (int i=1; i<sz(cnt); i++) cnt[i] += cnt[i-1];
    for (int i=N-1; i>=0; i--) sa[--cnt[b[idx[i]]]] = idx[i];

    nb[sa[0]] = 1;
    for (int i=1; i<N; i++) nb[sa[i]] = nb[sa[i-1]] + cmp(sa[i-1], sa[i]);
    swap(b, nb);

    if(nb[sa[N-1]] == N) break; // N buckets -> done
  }

  // lcp
  lcp.resize(N);
  vector<int> rank(N); // inverse sa
  for (int i=0; i<N; i++) rank[sa[i]] = i;
  for (int i=0, k=0; i<N; i++, k=max(k-1, 0)) { // k: suffix (i-1)'s lcp
    if (rank[i] == 0) continue;
    for (int j = sa[rank[i]-1]; S[i+k] == S[j+k]; k++);
    lcp[rank[i]] = k;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S; cin >> S;
  vector<int> sa, lcp;
  suffix_array(S, sa, lcp);
  
  for (int i=0; i<sz(sa); i++) cout << sa[i]+1 << " ";
  cout << endl;
  cout << "x ";
  for (int i=1; i<sz(lcp); i++) cout << lcp[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
