#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 100005;

int N;
pii P[MAX_N];
int xCoords[MAX_N], yCoords[MAX_N];

struct Fenwick {
  int arr[MAX_N];

  void reset() {
    fill(arr, arr + MAX_N, 0);
  }

  int query(int i) {
    i++;
    if (i == 0) return 0;
    int s = 0;
    while (i > 0) {
      s += arr[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int val) {
    i++;
    while (i < MAX_N) {
      arr[i] += val;
      i += i & -i;
    }
  }
} LF, RF;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    P[i] = {x, y};
  }
}

void compress() {
  for (int i = 0; i < N; i++) {
    xCoords[i] = P[i].first;
    yCoords[i] = P[i].second;
  }
  sort(xCoords, xCoords + N);
  sort(yCoords, yCoords + N);
  for (int i = 0; i < N; i++) {
    P[i].first = lower_bound(xCoords, xCoords + N, P[i].first) - xCoords;
    P[i].second = lower_bound(yCoords, yCoords + N, P[i].second) - yCoords;
  }
}

void sortCows() {
  sort(P, P + N);
}

void rightFenwick() {
  for (int i = 0; i < N; i++) {
    RF.add(P[i].second, 1);
  }
}

int getM(int i) {
  int result = 0;
  int l = LF.query(N - 1), lu = LF.query(i - 1), r = RF.query(N - 1), ru = RF.query(i - 1);
  result = max(result, lu);
  result = max(result, l - lu);
  result = max(result, ru);
  result = max(result, r - ru);
  // cout << i << " " << l << " " << lu << " " << r << " " << ru << " " << result << endl;
  return result;
}

int sweep() {
  int result = INT_MAX;
  int pos = 0;
  for (int i = 0; i <= N; i++) {
    int l = 0, r = N;
    while (r - l >= 3) {
      int ml = (l*2 + r) / 3, mr = (l + r*2)/3;
      if (getM(ml) <= getM(mr)) r = mr;
      else l = ml;
    }
    for (int t = l; t <= r; t++) {
      result = min(result, getM(t));
    }
    // cout << LF.query(N) << "/" << RF.query(N) << endl;

    while (pos < N && P[pos].first == i) {
      LF.add(P[pos].second, 1);
      RF.add(P[pos].second, -1);
      pos++;
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
  sortCows();
  rightFenwick();
  cout << sweep() << endl;

  ////////////////////////////////
  return 0;
}
