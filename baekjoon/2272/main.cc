#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
vector<bool> lamp;

void shiftxor(int shift) {
  vector<bool> shifted;
  shifted.resize(lamp.size());
  for (int i = 0; i < N; i++) {
    shifted[i] = lamp[(i + shift) % N];
  }
  for (int i = 0; i < N; i++) {
    lamp[i] = lamp[i] ^ shifted[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    bool b; cin >> b;
    lamp.push_back(b);
  }

  int s = 1;
  while (s < M) { s <<= 1; }
  while (s > 0) {
    if (M & s) { shiftxor(s); }
    s >>= 1;
  }

  for (int i = 0; i < N; i++) {
    cout << lamp[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
