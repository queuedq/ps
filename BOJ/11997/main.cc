#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1005;

int N, X[MAX_N], Y[MAX_N];
int xCoords[MAX_N], yCoords[MAX_N];
int A[MAX_N][MAX_N], S[MAX_N][MAX_N];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
}

void compress() {
  for (int i = 0; i < N; i++) {
    xCoords[i] = X[i];
    yCoords[i] = Y[i];
  }
  sort(xCoords, xCoords + N);
  sort(yCoords, yCoords + N);
  for (int i = 0; i < N; i++) {
    X[i] = lower_bound(xCoords, xCoords + N, X[i]) - xCoords;
    Y[i] = lower_bound(yCoords, yCoords + N, Y[i]) - yCoords;
  }
}

void prefixSum() {
  for (int i = 0; i < N; i++) {
    A[X[i]][Y[i]] = 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == 0) {
        S[i][j] = A[i][j];
      } else {
        S[i][j] = S[i][j - 1] + A[i][j];
      }
    }
    if (i == 0) { continue; }
    for (int j = 0; j < N; j++) {
      S[i][j] += S[i - 1][j];
    }
  }
}

int search() {
  int result = INT_MAX;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int maxCows = S[i][j];
      maxCows = max(maxCows, S[N - 1][j] - S[i][j]);
      maxCows = max(maxCows, S[i][N - 1] - S[i][j]);
      maxCows = max(maxCows, S[N - 1][N - 1] - S[N - 1][j] - S[i][N - 1] + S[i][j]);
      result = min(result, maxCows);
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  compress();
  prefixSum();
  cout << search() << endl;

  ////////////////////////////////
  return 0;
}
