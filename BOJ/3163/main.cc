#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, L, k;
vector<int> pos, id;
vector<pii> falls;

void input() {
  pos.clear(); id.clear(); falls.clear();

  cin >> N >> L >> k;
  for (int i = 0; i < N; i++) {
    int p, a; cin >> p >> a;
    pos.push_back(p);
    id.push_back(a);
  }
}

void calc() {
  for (int i = 0; i < N; i++) {
    if (id[i] > 0) {
      falls.push_back({L - pos[i], INT_MAX});
    } else {
      falls.push_back({pos[i], INT_MIN});
    }
  }

  sort(falls.begin(), falls.end());

  int l = 0, r = N - 1;
  for (int i = 0; i < N; i++) {
    if (falls[i].second == INT_MIN) { falls[i].second = id[l++]; }
    if (falls[i].second == INT_MAX) { falls[i].second = id[r--]; }
  }

  sort(falls.begin(), falls.end());

  cout << falls[k-1].second << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    calc();
  }

  ////////////////////////////////
  return 0;
}
