#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N;

void handle_4() {
  lld x0, x1, x2, x3, x4, x5;
  cout << "? 1 2" << endl; cin >> x0;
  cout << "? 1 3" << endl; cin >> x1;
  cout << "? 1 4" << endl; cin >> x2;
  cout << "? 2 3" << endl; cin >> x3;
  cout << "? 2 4" << endl; cin >> x4;
  cout << "? 3 4" << endl; cin >> x5;
  lld diff[3] = {x4-x2, x5-x4, x2-x1};
  sort(diff, diff+3);
  lld a = diff[1];
  lld b = (min(x2, x3) - a*3) / 2;
  lld k = abs(x2 - x3);
  cout << "! " << a << " " << b << " " << k << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  if (N == 4) { handle_4(); return 0; }

  vector<int> idx;
  for (int i=1; i<=N/2-1; i++) idx.push_back(i);
  shuffle(all(idx), default_random_engine(1337));
  int Q = min(N/2-1, 100LL);
  idx.resize(Q);

  vector<lld> S, T;
  for (auto i: idx) {
    cout << "? " << i << " " << N-i+1 << endl;
    lld sum; cin >> sum;
    S.push_back(sum);
  }
  for (auto i: idx) {
    cout << "? " << i << " " << N-i << endl;
    lld sum; cin >> sum;
    T.push_back(sum);
  }

  sort(all(S)); sort(all(T));
  lld a = S[0] - T[0];
  lld b = (S[0] - a*(N-1)) / 2;
  lld k = LLONG_MAX;
  for (int i=0; i<Q-1; i++) {
    if (S[i] != S[i+1]) k = min(k, S[i+1]-S[i]);
    if (T[i] != T[i+1]) k = min(k, T[i+1]-T[i]);
  }

  cout << "! " << a << " " << b << " " << k << endl;

  ////////////////////////////////
  return 0;
}
