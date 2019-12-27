#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MOD = 1e9+7;
const int MAX_L = 3005;
int L, cuts[MAX_L];
lld comb[MAX_L][MAX_L], D[MAX_L];
vector<int> lengths;

void dp() {
  comb[0][0] = 1;
  for (int i = 1; i < MAX_L; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    }
  }

  D[0] = 1;
  for (int i = 1; i < MAX_L; i++) {
    for (int j = 0; j < MAX_L; j += 2) {
      D[i] += D[j] * D[i-j-1] * comb[i-1][j];
      D[i] %= MOD;
    }
  }

  // for (int i = 0; i < 20; i++) { cout << D[i] << endl; }
}

void input() {
  cin >> L;
  int n; cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int p; cin >> p;
    if (p == 1) cuts[cnt++] = 1;
    else { cuts[cnt++] = 0; cuts[cnt++] = 1;}
  }
  cin >> n;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    int p; cin >> p;
    if (p == 1) cuts[cnt++] ^= 1;
    else { cnt++; cuts[cnt++] ^= 1; }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  dp();

  input();

  lld l = 0, num = 0, ways = 1;
  for (int i = 0; i < L; i++) {
    if (cuts[i] == 1) { l++; num++; }
    else { lengths.push_back(l); l = 0; }
  }

  lld sum = 0;
  for (int l: lengths) {
    sum += l;
    ways = ways * D[l] % MOD;
    ways = ways * comb[sum][l] % MOD;
  }

  cout << num << " " << ways << endl;

  ////////////////////////////////
  return 0;
}
