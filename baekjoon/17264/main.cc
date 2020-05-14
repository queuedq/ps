#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, P, W, L, G;
map<string, bool> win;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> P;
  cin >> W >> L >> G;
  for (int i=0; i<P; i++) {
    string name, result; cin >> name >> result;
    win[name] = result == "W";
  }

  int score = 0;
  bool ok = false;
  for (int i=0; i<N; i++) {
    string name; cin >> name;
    if (win[name]) score += W;
    else score -= L;
    score = max(score, 0);

    if (score >= G) {
      ok = true;
      break;
    }
  }

  if (ok) cout << "I AM NOT IRONMAN!!" << endl;
  else cout << "I AM IRONMAN!!" << endl;

  ////////////////////////////////
  return 0;
}
