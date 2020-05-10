#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N, A[MAXN];
bool occupied[MAXN];

bool calc() {
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int i=0; i<N; i++) {
    int room = ((i + A[i]) % N + N) % N;
    if (occupied[room]) return false;
    occupied[room] = true;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cout << (calc() ? "YES" : "NO") << endl;
    fill(occupied, occupied+N, false);
  }

  ////////////////////////////////
  return 0;
}
