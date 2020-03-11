#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, T[MAXN], S[MAXN], idx[MAXN];

bool cmp(int i, int j) {
  if (S[i] * T[j] == S[j] * T[i]) return i < j;
  return S[i] * T[j] > S[j] * T[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> T[i] >> S[i];
    idx[i] = i;
  }
  sort(idx+1, idx+N+1, cmp);

  for (int i=1; i<=N; i++) cout << idx[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
