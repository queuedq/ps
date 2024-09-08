#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 20202;
int N, pos[5][MN];

vector<int> cow;
map<int, int> idx;

bool cmp(int x, int y) {
  int cnt = 0;
  for (int p=0; p<5; p++) cnt += pos[p][x] < pos[p][y];
  return cnt >= 3;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int p=0; p<5; p++) {
    for (int i=0; i<N; i++) {
      int a; cin >> a;
      if (p == 0) {
        cow.push_back(a);
        idx[a] = i;
      }
      pos[p][idx[a]] = i;
    }
  }

  vector<int> ord;
  for (int i=0; i<N; i++) ord.push_back(i);
  sort(all(ord), cmp);

  for (int i=0; i<N; i++) cout << cow[ord[i]] << endl;

  ////////////////////////////////
  return 0;
}
