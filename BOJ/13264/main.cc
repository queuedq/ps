#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
inline int mod(int x, int m) { return (x%m+m)%m; }

void suffix_array(string S, vector<int> &sa) {
  S += '$'; int N = sz(S);
  // sa, sb: suffix (sorted)
  // B, B1: suffix to bucket
  // cnt: bucket size
  sa.resize(N);
  vector<int> sb(N), B(N), B1(N), cnt(max(N, 256));

  // initial sort
  int bkt = 256;
  for (int i=0; i<N; i++) B[i] = S[i];
  for (int i=0; i<N; i++) cnt[B[i]]++;
  for (int i=1; i<bkt; i++) cnt[i] += cnt[i-1];
  for (int i=N-1; i>=0; i--) sa[--cnt[B[i]]] = i;
  
  // sort
  for (int len=1; len<N; len<<=1) {
    // ready
    for (int i=0; i<N; i++) sb[i] = mod(sa[i]-len, N);
    // count
    fill(all(cnt), 0);
    for (int i=0; i<N; i++) cnt[B[i]]++;
    for (int i=1; i<bkt; i++) cnt[i] += cnt[i-1];
    // order
    for (int i=N-1; i>=0; i--) sa[--cnt[B[sb[i]]]] = sb[i];
    // bucket
    bkt = 1, B1[sa[0]] = 0;
    for (int i=1; i<N; i++) {
      int l = sa[i-1], r = sa[i];
      B1[r] = (B[l] == B[r] && B[mod(l+len, N)] == B[mod(r+len, N)]) ? bkt-1 : bkt++;
    }
    swap(B, B1);
  }

  sa.erase(sa.begin()); N--;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S; cin >> S;
  vector<int> sa;
  suffix_array(S, sa);
  for (int i=0; i<sz(S); i++) cout << sa[i] << endl;

  ////////////////////////////////
  return 0;
}
