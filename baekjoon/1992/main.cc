#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 64;
int N;
string A[MAXN];

string compress(int x, int y, int sz) {
  if (sz == 1) return string(1, A[x][y]);
  string s1 = compress(x, y, sz/2);
  string s2 = compress(x, y+sz/2, sz/2);
  string s3 = compress(x+sz/2, y, sz/2);
  string s4 = compress(x+sz/2, y+sz/2, sz/2);
  if (s1 == "0" && s2 == "0" && s3 == "0" && s4 == "0") return "0";
  if (s1 == "1" && s2 == "1" && s3 == "1" && s4 == "1") return "1";
  return "(" + s1+s2+s3+s4 + ")";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  cout << compress(0, 0, N) << endl;

  ////////////////////////////////
  return 0;
}
