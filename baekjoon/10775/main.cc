#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define MAX_G 100000
#define MAX_P 100000

int G, P;
int planes[MAX_P];
int parent[MAX_G + 1];
int sizes[MAX_G + 1];

int find(int i) {
  while (parent[i] != i) {
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}

void join(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (x == y) { return; }
  if (sizes[x] > sizes[y]) {
    parent[y] = x;
    sizes[x] = sizes[x] + sizes[y];
  } else {
    parent[x] = y;
    sizes[y] = sizes[x] + sizes[y];
  }
}

void input() {
  cin >> G;
  cin >> P;
  for (int i = 0; i < P; i++) {
    cin >> planes[i];
  }
}

void init() {
  for (int i = 1; i <= G; i++) {
    parent[i] = i;
  }
}

// void debug() {
//   for (int i = 0; i <= G; i++) {
//     cout << i << ": " << parent[i] << " " << sizes[i] << endl;
//   }
// }

void insert() {
  int i = 0;
  for (; i < P; i++) {
    int x = find(planes[i]);
    int next = x - sizes[x];
    if (next <= 0) {
      break;
    }
    // assert(sizes[next] == 0);
    sizes[next] = 1;
    if (next < G && sizes[next + 1] > 0) {
      join(next, next + 1);
    }
    if (sizes[next - 1] > 0) {
      join(next, next - 1);
    }
    // cout << "plane = " << i << endl;
    // debug();
  }
  cout << i;
}

int main() {
  input();
  init();
  insert();
  return 0;
}
