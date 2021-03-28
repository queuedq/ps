#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N, pre[MAXN];
string S;

void calc() {
  if (pre[N/2] == N/4) {
    cout << 1 << endl;
    cout << N/2 << endl;
    return;
  }

  for (int i = 0; i <= N/2; i++) {
    if (pre[i+N/2] - pre[i] == N/4) {
      cout << 2 << endl;
      cout << i << " " << i+N/2 << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  for (int i = 1; i <= N; i++) {
    pre[i] = pre[i-1] + (S[i-1] == 's');
  }
  calc();

  ////////////////////////////////
  return 0;
}
