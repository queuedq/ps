#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;

////////////////////////////////////////////////////////////////
int L, R;

char query(int i) {
  cout << "? " << i << endl;
  char c; cin >> c;
  return c;
}

void defense(int p) {
  // 1 2 3 4 5 6
  // R B B R B R
  string table = " RBBRBR";
  for (int i=L; i<=R; i++) cout << table[i>>p];
  cout << endl;
}

void attack(int p) {
  int value[8] = {};
  int color[8] = {};

  // check a, b, c, ab, bc, ac, abc
  //         v----- p
  // a   = 001111
  // b   = 010111
  // c   = 100000
  // abc = 111000
  int a = (1<<p) + (1<<p) - 1;
  int b = (1<<(p+1)) + (1<<p) - 1;
  int c = (1<<(p+2));

  for (int i=1; i<=7; i++) {
    int q = 0;
    if (i & 1) q ^= a;
    if (i & 2) q ^= b;
    if (i & 4) q ^= c;
    value[i] = q;
    color[i] = query(q);
  }

  // find matching colors
  for (int i=1; i<=7; i++) {
    for (int j=i+1; j<=7; j++) {
      int k = i ^ j;
      if (color[i] == color[j] && color[i] == color[k]) {
        cout << "! " << value[i] << " " << value[j] << " " << value[k] << endl;
        return;
      }
    }
  }

  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> L >> R;

  // find leftmost bit pos
  int p = 0;
  while (L>>p) p++;
  p--;

  if ((R>>p) >= 7) {
    cout << "attack" << endl;
    attack(p);
  } else {
    cout << "defense" << endl;
    defense(p);
  }

  ////////////////////////////////
  return 0;
}
