#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Card { int a, b, c; };
bool isSet(Card x, Card y, Card z) {
  return (x.a + y.a + z.a) % 3 == 0 &&
         (x.b + y.b + z.b) % 3 == 0 &&
         (x.c + y.c + z.c) % 3 == 0;
}

map<string, int> shape = {{"CIRCLE", 0}, {"TRIANGLE", 1}, {"SQUARE", 2}};
map<string, int> color = {{"YELLOW", 0}, {"RED", 1}, {"BLUE", 2}};
map<string, int> bg = {{"GRAY", 0}, {"WHITE", 1}, {"BLACK", 2}};

Card cards[9];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<9; i++) {
    string S, C, B; cin >> S >> C >> B;
    cards[i] = {shape[S], color[C], bg[B]};
  }

  map<set<int>, bool> sets;
  int left = 0;

  for (int i=0; i<9; i++) {
    for (int j=0; j<i; j++) {
      for (int k=0; k<j; k++) {
        if (isSet(cards[i], cards[j], cards[k])) {
          sets[{i+1, j+1, k+1}] = true;
          left++;
        }
      }
    }
  }

  int n; cin >> n;
  int points = 0;
  bool already = false;
  for (int i=0; i<n; i++) {
    char q; cin >> q;
    if (q == 'H') {
      int a, b, c; cin >> a >> b >> c;
      if (sets[{a, b, c}]) {
        points++;
        sets[{a, b, c}] = false;
        left--;
      } else {
        points--;
      }
    } else {
      if (left == 0 && !already) {
        points += 3;
        already = true;
      }
      else points--;
    }
  }

  cout << points << endl;

  ////////////////////////////////
  return 0;
}
