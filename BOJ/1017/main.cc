#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 55;
const int MAXK = 2005;
bool prime[MAXK];
int N, A[MAXN];

int m1;
vector<int> adj[MAXN];
bool vst[MAXN];
int L[MAXN], R[MAXN];

void construct() {
  for (int i=2; i<=N; i++) {
    if (i == m1) continue;
    for (int j=2; j<i; j++) {
      if (j == m1) continue;
      if (prime[A[i] + A[j]]) {
        if (A[i] % 2) adj[i].push_back(j);
        else adj[j].push_back(i);
      }
    }
  }
}

bool match(int u) {
  if (vst[u]) return false;
  vst[u] = true;

  for (auto v: adj[u]) {
    if (R[v] == 0 || match(R[v])) {
      L[u] = v;
      R[v] = u;
      return true;
    }
  }
  return false;
}

void reset() {
  for (int i=1; i<=N; i++) {
    adj[i].clear();
    L[i] = 0;
    R[i] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime, prime+MAXK, true);
  prime[0] = prime[1] = false;
  for (int i=2; i<MAXK; i++) {
    if (prime[i]) {
      for (int j=i*2; j<MAXK; j+=i) prime[j] = false;
    }
  }

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  vector<int> ans;
  for (m1=2; m1<=N; m1++) {
    if (!prime[A[1] + A[m1]]) continue;
    construct();

    int cnt = 0;
    for (int i=1; i<=N; i++) {
      fill(vst, vst+N+1, false);
      cnt += match(i);
    }
    if (cnt == N/2 - 1) ans.push_back(A[m1]);

    reset();
  }

  if (ans.empty()) { cout << -1; return 0; }
  sort(ans.begin(), ans.end());
  for (auto a: ans) cout << a << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
