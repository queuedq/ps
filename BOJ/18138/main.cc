#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 205;
int N, M, A[MAXN], B[MAXN], S[MAXN], T[MAXN];
vector<int> adj[MAXN];
bool vst[MAXN];

bool match(int u) {
  if (vst[u]) return false;
  vst[u] = true;

  for (int v: adj[u]) {
    if (T[v] == 0 || match(T[v])) {
      S[u] = v;
      T[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=M; i++) cin >> B[i];

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      bool edge = A[i] <= B[j]*2 && B[j]*4 <= A[i]*3;
      edge |= A[i] <= B[j] && B[j]*4 <= A[i]*5;
      if (edge) adj[i].push_back(j);
    }
  }

  int cnt = 0;
  for (int i=1; i<=N; i++) {
    fill(vst, vst+N+1, false);
    cnt += match(i);
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
