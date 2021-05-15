#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e12;
const int MR = 11;
lld R, C, F, S;
lld A[MR*MR], B[MR*MR], D[MR*MR][1<<MR];

int s0(int state) {
  return state & 1;
}

int s1(int state) {
  return (state >> 1) & 1;
}

lld dp(int i, int state) {
  if (i == R*C) {
    if (state == 0) return 0;
    else return INF;
  }

  if (D[i][state] != INF) return D[i][state];

  if (s0(state) == B[i]) {
    D[i][state] = min(D[i][state], dp(i+1, state >> 1 | A[i+C] << C-1));
  } else {
    D[i][state] = min(D[i][state], dp(i+1, state >> 1 | A[i+C] << C-1) + F); // flip

    if (i<(R-1)*C && A[i+C] == B[i]) { // vertical
      D[i][state] = min(D[i][state], dp(i+1, state >> 1 | s0(state) << C-1) + S);
    }

    if (i%C != C-1 && s1(state) == B[i]) { // horizontal
      int state1 = (state >> 2 << 1) + s0(state);
      D[i][state] = min(D[i][state], dp(i+1, state1 | A[i+C] << C-1) + S);
    }
  }

  return D[i][state];
}

void solve(int test) {
  cin >> R >> C >> F >> S;
  fill(A, A+(R+1)*C, 0);
  fill(B, B+(R+1)*C, 0);
  for (int i=0; i<R; i++) {
    string S; cin >> S;
    for (int j=0; j<C; j++) A[i*C+j] = S[j] == 'G';
  }
  for (int i=0; i<R; i++) {
    string S; cin >> S;
    for (int j=0; j<C; j++) B[i*C+j] = S[j] == 'G';
  }

  for (int i=0; i<R*C; i++) fill(D[i], D[i] + (1<<C), INF);
  
  int state = 0;
  for (int i=C-1; i>=0; i--) {
    state <<= 1;
    state += A[i];
  }

  int ans = dp(0, state);
  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
