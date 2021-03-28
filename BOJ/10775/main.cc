#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define MAX_G 100005
#define MAX_P 100005

int G, P;
int planes[MAX_P];
int parent[MAX_G];

int find(int i) {
  if (parent[i] == i) return i;
  parent[i] = find(parent[i]);
  return parent[i];
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

void insert() {
  int i = 0;
  for (; i < P; i++) {
    int e = find(planes[i]);
    if (e == 0) break;
    parent[e] = e - 1;
  }
  cout << i << endl;
}

int main() {
  input();
  init();
  insert();
  return 0;
}
