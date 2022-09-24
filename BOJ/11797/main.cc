#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 101010;
int N, M, A[MN];
int prv[MN], vcnt, group[MN], len;
lld D[MN]; // # of non-existing subsequences of length `len+1`

void add(lld &a, lld b) { a = (a+b+MOD) % MOD; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  
  D[0] = 1;
  len = 1;
  lld pd = M, cd = 0; // (prev, current) group DP sum

  for (int i=1; i<=N; i++) {
    group[i] = len;
    D[i] = pd;

    if (group[prv[A[i]]] < len) { // first visit of A[i] in current group
      vcnt++;
      add(pd, -D[prv[A[i]]]);
    } else {
      add(cd, -D[prv[A[i]]]);
    }

    prv[A[i]] = i;
    add(cd, D[i]);

    if (vcnt == M) { // new group
      vcnt = 0; len++;
      pd = cd; cd = 0;
    }
  }

  cout << len << " " << pd << endl;

  ////////////////////////////////
  return 0;
}
