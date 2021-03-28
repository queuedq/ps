#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////

#define MAX_N 100000
#define MAX_M 100000
int N, M, A[MAX_N], S[MAX_N + 1];
pii Q[MAX_M];


void input() {
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
    S[i + 1] = sum;
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    Q[i] = {l - 1, r};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  for (int i = 0; i < M; i++) {
    int maxLen = 0;
    for (int l = Q[i].first; l < Q[i].second; l++) {
      for (int r = l; r <= Q[i].second; r++) {
        if (S[r] - S[l] == 0 && r - l > maxLen) {
          maxLen = r - l;
        }
      }
    }
    cout << maxLen << endl;
  }

  ////////////////////////////////
  return 0;
}
