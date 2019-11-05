#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 36
#define POW_N 300000
lld N;
lld A[MAX_N], B[MAX_N];
lld D1[POW_N];
vector<pll> D2[MAX_N / 2 + 1], D2temp[MAX_N / 2 + 1];

void input() {
  cin >> N;
  for (lld i = 0; i < N; i++) cin >> A[i];
  for (lld i = 0; i < N; i++) cin >> B[i];
}

lld power(lld b) {
  return 1LL << b;
}

int countOnes(lld x) {
  int cnt = 0;
  while (x > 0) {
    cnt += (x & 1);
    x >>= 1;
  }
  return cnt;
}

void processTeams() {
  for (lld i = 0; i < power(N / 2); i++) {
    lld ii = i;
    lld diff = 0;
    for (lld j = N / 2 - 1; j >= 0; j--) {
      if ((ii & 1) == 0) {
        diff += A[j];
      } else {
        diff -= B[j];
      }
      ii >>= 1;
    }
    D1[i] = diff;
  }

  for (lld i = 0; i < power(N / 2); i++) {
    lld ii = i;
    lld diff = 0;
    int cnt = 0;  // number of team 1
    for (lld j = N - 1; j >= N / 2; j--) {
      if ((ii & 1) == 0) {
        diff += A[j];
        cnt++;  // count if team 1
      } else {
        diff -= B[j];
      }
      ii >>= 1;
    }
    D2temp[cnt].push_back({diff, i});
  }

  // Remove duplicte
  for (int cnt = 0; cnt <= N / 2; cnt++) {
    sort(D2temp[cnt].begin(), D2temp[cnt].end());
    D2[cnt].push_back(D2temp[cnt][0]);
    for (lld i = 1; i < D2temp[cnt].size(); i++) {
      if (D2temp[cnt][i].first == D2temp[cnt][i - 1].first) continue;
      D2[cnt].push_back(D2temp[cnt][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  processTeams();

  lld score = LLONG_MAX;
  lld best = LLONG_MAX;

  for (lld i = 0; i < power(N / 2); i++) {
    int cnt = countOnes(i);  // number of team 2 in first half

    auto it = lower_bound(D2[cnt].begin(), D2[cnt].end(), (pll){-D1[i], 0});

    if (it != D2[cnt].end()) {
      lld newScore = abs(D1[i] + it->first);
      lld newBest = i * power(N / 2) + it->second;
      if (newScore == score) {
        best = min(best, newBest);
      } else if (newScore < score) {
        best = newBest;
        score = newScore;
      }
    }
    if (it != D2[cnt].begin()) {
      it--;
      lld newScore = abs(D1[i] + it->first);
      lld newBest = i * power(N / 2) + it->second;
      if (newScore == score) {
        best = min(best, newBest);
      } else if (newScore < score) {
        best = newBest;
        score = newScore;
      }
    }
  }

  for (lld mask = power(N - 1); mask > 0; mask >>= 1) {
    if ((best & mask) == 0) {
      cout << "1 ";
    } else {
      cout << "2 ";
    }
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
