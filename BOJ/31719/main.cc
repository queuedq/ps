#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int T, N, A[MN];

bool solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  // two closed stacks and floor
  pii S1 = {-1, -1}, S2 = {-1, -1};
  int last = 0;

  for (int i=0; i<N; i++) {
    // put element
    if (A[i] == last+1) last++;
    else if (A[i] == S1.second+1) S1.second++;
    else if (A[i] == S2.second+1) S2.second++;
    else if (S1.first == -1) S1 = {A[i], A[i]};
    else if (S2.first == -1) S2 = {A[i], A[i]};
    else return 0; // nowhere to put element

    // flush stack
    if (S1.first == last+1) { last = S1.second; S1 = {-1, -1}; }
    if (S2.first == last+1) { last = S2.second; S2 = {-1, -1}; }
    if (S1.first == last+1) { last = S1.second; S1 = {-1, -1}; }
  }

  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
