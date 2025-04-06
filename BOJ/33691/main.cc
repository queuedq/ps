#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K;
vector<string> msg;
map<string, bool> pin, vst;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string S; cin >> S;
    msg.push_back(S);
  }
  reverse(all(msg));

  cin >> K;
  for (int i=0; i<K; i++) {
    string S; cin >> S;
    pin[S] = true;
  }

  for (auto S: msg) {
    if (!vst[S] && pin[S]) {
      cout << S << endl;
      vst[S] = 1;
    }
  }

  for (auto S: msg) {
    if (!vst[S] && !pin[S]) {
      cout << S << endl;
      vst[S] = 1;
    }
  }

  ////////////////////////////////
  return 0;
}
