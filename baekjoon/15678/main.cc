#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e5+5;
lld N, D, A[MAX_N], score[MAX_N];
list<pll> dq;

void push(pll s) {
  while (!dq.empty() && dq.back().first <= s.first) {
    dq.pop_back();
  }
  dq.push_back(s);
}

void pop(int t) {
  while (!dq.empty() && dq.front().second < t - D) {
    dq.pop_front();
  }
}

void input() {
  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

void dp() {
  score[0] = A[0];
  dq.push_back({score[0], 0});
  for (int i = 1; i < N; i++) {
    pop(i);
    score[i] = max(A[i], dq.front().first + A[i]);
    push({score[i], i});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dp();

  lld maxScore = LLONG_MIN;
  for (int i = 0; i < N; i++) {
    maxScore = max(maxScore, score[i]);
  }
  cout << maxScore << endl;

  ////////////////////////////////
  return 0;
}
