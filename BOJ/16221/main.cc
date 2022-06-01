#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 1e6+5;
int Q, cnt[MK], bit[MK];

void add(int i, int x) {
  for (; i<MK; i+=i&-i) bit[i] += x;
}

int qry(int i) {
  int ret = 0;
  for (; i>0; i-=i&-i) ret += bit[i];
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> Q;
  set<int> S;
  for (int i=1; i<MK; i++) S.insert(i);

  for (int q=0; q<Q; q++) {
    int T, K; cin >> T >> K;
    if (T == 1) {
      if (cnt[K] == 0) S.erase(K);
      cnt[K]++;
      add(K, 1);
    } else {
      cnt[K]--;
      if (cnt[K] == 0) S.insert(K);
      add(K, -1);
    }

    int i = *S.begin();
    cout << qry(i-1) << endl;
  }

  ////////////////////////////////
  return 0;
}
