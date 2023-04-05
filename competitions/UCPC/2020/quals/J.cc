#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, M;
bool final[MAXN], infect[MAXN], restore[MAXN];
vector<int> meeting[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int d=0; d<M; d++) {
    int k; cin >> k;
    for (int j=0; j<k; j++) {
      int a; cin >> a;
      meeting[d].push_back(a);
    }
  }

  for (int p=1; p<=N; p++) {
    cin >> final[p];
    infect[p] = final[p];
  }

  for (int d=M-1; d>=0; d--) {
    bool haszero = false;
    for (int i=0; i<meeting[d].size(); i++) {
      if (!infect[meeting[d][i]]) haszero = true;
    }

    if (haszero) {
      for (int i=0; i<meeting[d].size(); i++) infect[meeting[d][i]] = false;
    }
  }

  for (int p=1; p<=N; p++) {
    restore[p] = infect[p];
  }

  for (int d=0; d<M; d++) {
    bool hasone = false;
    for (int i=0; i<meeting[d].size(); i++) {
      if (restore[meeting[d][i]]) hasone = true;
    }

    if (hasone) {
      for (int i=0; i<meeting[d].size(); i++) restore[meeting[d][i]] = true;
    }
  }

  bool success = true;
  for (int p=1; p<=N; p++) {
    if (restore[p] != final[p]) {
      success = false;
      break;
    }
  }

  if (success) {
    cout << "YES" << endl;
    for (int p=1; p<=N; p++) cout << infect[p] << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  ////////////////////////////////
  return 0;
}
