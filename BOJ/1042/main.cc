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
const int MN = 2505;
int c2i[256];
string S;
int N, M, A[MN], nxt[MN][4];
lld D[MN];
map<string, vector<string>> C;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  c2i['A'] = 0, c2i['C'] = 1, c2i['G'] = 2, c2i['T'] = 3;

  cin >> S >> M;
  for (int i=0; i<M; i++) {
    string codon, amino; cin >> codon >> amino;
    C[amino].push_back(codon);
  }

  N = sz(S);
  for (int i=1; i<=N; i++) A[i] = c2i[S[i-1]];

  // calc nxt
  int last[4] = {N+1, N+1, N+1, N+1};
  nxt[N+1][0] = nxt[N+1][1] = nxt[N+1][2] = nxt[N+1][3] = N+1;
  for (int i=N; i>=0; i--) {
    for (int j=0; j<4; j++) nxt[i][j] = last[j];
    last[A[i]] = i;
  }

  // dp
  D[N+1] = 0;
  for (int i=N; i>=0; i--) {
    D[i] = 1; // end at i
    for (auto [amino, codons]: C) {
      int j = N+1; // min end for this amino
      for (auto codon: codons) {
        int k = i;
        for (char c: codon) k = nxt[k][c2i[c]];
        j = min(j, k);
      }
      D[i] += D[j];
    }
    D[i] %= MOD;
  }

  cout << D[0]-1 << endl;

  ////////////////////////////////
  return 0;
}
