#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 55;
const int MAX_T = 100005;
int N, T;
lld M[MAX_N], P[MAX_N], R[MAX_N];
lld score[MAX_N][MAX_T];

struct Problem {
  lld M, P, R;
};

bool cmp(Problem a, Problem b) {
  return a.P * b.R > b.P * a.R;
}

Problem probs[MAX_N];

void input() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) { cin >> M[i]; }
  for (int i = 0; i < N; i++) { cin >> P[i]; }
  for (int i = 0; i < N; i++) { cin >> R[i]; }
  for (int i = 0; i < N; i++) {
    probs[i] = {M[i], P[i], R[i]};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  sort(probs, probs + N, cmp);

  for (int t = probs[0].R; t <= T; t++) {
    score[0][t] = probs[0].M - t * probs[0].P;
  }

  for (int i = 1; i < N; i++) {
    for (int t = 0; t <= T; t++) {
      score[i][t] = score[i - 1][t];
      if (t >= probs[i].R) {
        score[i][t] = max(score[i][t], score[i - 1][t - probs[i].R] + probs[i].M - t * probs[i].P);
      }
    }
  }

  lld ans = 0;
  for (int t = 0; t <= T; t++) {
    ans = max(ans, score[N - 1][t]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
