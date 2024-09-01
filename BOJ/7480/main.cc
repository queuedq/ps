#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int B = 512;
int N, M;
deque<int> arr[B];
int vst[B*B+B];

int put(int i, int x) { // return push end pos
  deque<int> &bkt = arr[i/B];
  int s = i/B*B, e = s+B;

  // skip if full
  if (i == s && sz(bkt) == B) {
    bkt.push_front(x);
    int y = bkt.back(); bkt.pop_back();
    return put(e, y);
  }

  // insert to bucket
  int pos = 0;
  for (int j=s; j<i; j++) pos += vst[j];
  bkt.insert(bkt.begin() + pos, x);

  // push elements
  int j = i; // end pos
  while (j < e && vst[j]) j++;

  if (j < e) { vst[j] = 1; return j; }
  int y = bkt.back(); bkt.pop_back();
  return put(e, y);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;

  int mx = 0;
  for (int k=1; k<=N; k++) {
    int i; cin >> i;
    mx = max(mx, put(i, k));
  }

  cout << mx << endl;
  for (int i=1; i<=mx; i++) {
    if (!vst[i]) {
      cout << 0 << " ";
    } else {
      cout << arr[i/B].front() << " ";
      arr[i/B].pop_front();
    }
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
