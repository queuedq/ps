#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e5 + 5;
lld N, M;
lld F[MAX_N], S[MAX_N];
deque<pll> dq;

void push(pll x) {
  while (!dq.empty() && dq.back() < x) dq.pop_back();
  dq.push_back(x);
}

void pop(lld l) {
  while (!dq.empty() && dq.front().second < l) dq.pop_front();
}

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> F[i] >> S[i];
  }
}

lld slide() {
  int left = 0;
  lld sum = 0;
  lld spice = LLONG_MAX;
  for (int i = 0; i < N; i++) {
    sum += F[i];
    push({S[i], i});

    while (sum - F[left] >= M) {
      sum -= F[left];
      left++;
    }
    pop(left);

    if (sum >= M && !dq.empty()) {
      spice = min(spice, dq.front().first);
    }
  }

  return spice;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  cout << slide() << endl;

  ////////////////////////////////
  return 0;
}
