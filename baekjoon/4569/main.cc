#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int P, S[7], cnt, ball[20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> P;
    if (P == 0) break;
    for (int i=0; i<P; i++) cin >> S[i];

    cnt = 0;
    fill(ball, ball+20, 0);
    bool crash = false;

    for (int i=0; i<20; i++) {
      if (ball[i] == 0) ball[i] = ++cnt;
      int j = i + S[i%P];
      if (j >= 20) continue;
      if (ball[j] != 0) { crash = true; break; }
      ball[j] = ball[i];
    }

    if (crash) {
      cout << "CRASH\n";
    } else {
      for (int i=0; i<20; i++) cout << (char)('A' + ball[i] - 1);
      cout << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
