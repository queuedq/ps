#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_K 100005
#define INF 987654321
int N, M, K;
pii obsX[MAX_K], obsY[MAX_K];

bool cmpY(pii a, pii b) {
  if (a.second == b.second) return a.first < b.first;
  else return a.second < b.second;
}

void input() {
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    obsX[i] = {x, y};
    obsY[i] = {x, y};
  }

  sort(obsX, obsX + K);
  sort(obsY, obsY + K, cmpY);
}

int findL(pii P) {
  int i = lower_bound(obsX, obsX + K, P) - obsX - 1;
  if (i < 0) return -INF;
  pii found = obsX[i];
  if (found.first != P.first) return -INF;
  return found.second;
}

int findR(pii P) {
  int i = lower_bound(obsX, obsX + K, P) - obsX;
  if (i >= K) return INF;
  pii found = obsX[i];
  if (found.first != P.first) return INF;
  return found.second;
}

int findU(pii P) {
  int i = lower_bound(obsY, obsY + K, P, cmpY) - obsY - 1;
  if (i < 0) return -INF;
  pii found = obsY[i];
  if (found.second != P.second) return -INF;
  return found.first;
}

int findD(pii P) {
  int i = lower_bound(obsY, obsY + K, P, cmpY) - obsY;
  if (i >= K) return INF;
  pii found = obsY[i];
  if (found.second != P.second) return INF;
  return found.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  // cout << findR({3, 2}) << endl;
  // cout << findU({3, 3}) << endl;
  // cout << findD({2, 3}) << endl;
  // cout << findL({4, 4}) << endl;

  int up = 1, down = N, left = 1, right = M;
  int dir = 0;
  lld visited = 0;

  while (true) {
    int toVisit;
    if (dir == 0) {
      int to = min(findR({up, left - 1}) - 1, right);
      toVisit = to - left + 1;
      if (toVisit == 0) break;
      up++; right = to;
    } else if (dir == 1) {
      int to = min(findD({up - 1, right}) - 1, down);
      toVisit = to - up + 1;
      if (toVisit == 0) break;
      right--; down = to;
    } else if (dir == 2) {
      int to = max(findL({down, right + 1}) + 1, left);
      toVisit = right - to + 1;
      if (toVisit == 0) break;
      down--; left = to;
    } else if (dir == 3) {
      int to = max(findU({down + 1, left}) + 1, up);
      toVisit = down - to + 1;
      if (toVisit == 0) break;
      left++; up = to;
    }
    // cout << toVisit << endl;

    visited += toVisit;
    dir = (dir + 1) % 4;
  }
  // cout << visited << endl;

  if (visited + K == (lld)N * M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  ////////////////////////////////
  return 0;
}
