#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 200005;
int N, A[MAX_N], M;
vector<pii> heros, HP, HS;

void reset() {
  heros.clear();
  HP.clear();
  HS.clear();
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int p, s; cin >> p >> s;
    heros.push_back({p, s});
  }
}

bool cmpS(pii a, pii b) {
  return (pii){a.second, a.first} < (pii){b.second, b.first};
}

void sortHeros() {
  sort(heros.begin(), heros.end());
  for (int i = 0; i < M; i++) {
    pii h = heros[i]; int s = h.second;
    while(!HP.empty() && s >= HP.back().second) { HP.pop_back(); }
    HP.push_back(heros[i]);
  }

  for (int i = HP.size(); i >= 0; i--) {
    HS.push_back(HP[i]);
  }
}

int defeat() {
  int l = 0, r = HP.size();
  int cnt = 0, days = 1;
  for (int i = 0; i < N; i++) {
    // cout << "MONSTER" << A[i] << endl;
    int nl = lower_bound(HP.begin(), HP.end(), (pii){A[i], 0}) - HP.begin();
    int nr = lower_bound(HS.begin(), HS.end(), (pii){0, cnt + 1}, cmpS) - HS.begin();
    nr = HS.size() - nr;
    l = max(l, nl);
    r = min(r, nr);
    // cout << l << " " << r << endl;
    if (l < r) {
      // Success
      cnt++;
    } else {
      // Failure
      if (cnt == 0) {
        return -1;
      }
      l = 0;
      r = HP.size();
      days += 1;
      cnt = 0;
      i--;
    }
  }
  return days;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    reset();
    input();
    sortHeros();
    cout << defeat() << endl;
  }

  ////////////////////////////////
  return 0;
}
