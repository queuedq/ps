#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
map<string, string> dict;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string w, k; cin >> w;
    k = w;
    if (k.size() > 2) sort(k.begin() + 1, k.end() - 1);
    dict[k] = w;
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    string w; cin >> w;
    if (w.size() > 2) sort(w.begin() + 1, w.end() - 1);
    cout << dict[w] << ' ';
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
