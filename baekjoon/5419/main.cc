#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 75005
#define BIT_SIZE MAX_N * 2
int T, N;
pii P[MAX_N];
vector<int> coords;
int BIT[BIT_SIZE];

int compress(int x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin() + 1;
}

void add(int i) {
  assert(i > 0);
  while (i < BIT_SIZE) {
    BIT[i]++;
    i += (i & -i);
  }
}

int sum(int i) {
  int sum = 0;
  while (i > 0) {
    sum += BIT[i];
    i -= (i & -i);
  }
  return sum;
}

lld calc() {
  // Reset
  coords.clear();
  fill(BIT, BIT + BIT_SIZE, 0);

  // Input
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    P[i] = {x, -y};
    coords.push_back(x);
    coords.push_back(-y);
  }

  // Compress & Sort
  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());

  for (int i = 0; i < N; i++) {
    // cout << "Orig: " << P[i].first << ", " << P[i].second << endl;
    P[i].first = compress(P[i].first);
    P[i].second = compress(P[i].second);
    // cout << P[i].first << " " << P[i].second << endl;
  }
  sort(P, P + N);

  // Calc
  lld count = 0;
  for (int i = 0; i < N; i++) {
    pii point = P[i];
    count += sum(point.second);
    add(point.second);
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;

  for (int i = 0; i < T; i++) {
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
