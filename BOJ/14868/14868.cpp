#include <stdio.h>
using namespace std;

#define MAX_N 2000
#define MAX_K 1000000

int N, K, year = 0;
int x[MAX_K], y[MAX_K];
bool isCivilized[MAX_N + 2][MAX_N + 2];

typedef struct Position {
  int x;
  int y;
  Position() : x(0), y(0) { }
  Position(int _x, int _y) : x(_x), y(_y) { }
} Position;

Position array1[MAX_N * MAX_N]; // Current year's new civil
Position array2[MAX_N * MAX_N]; // Next year's new civil
Position *currentCivil = array1;
Position *nextCivil = array2;
int currentCivilLength;

int map(int x, int y) { // Map to index of DisjointSet
  return (x - 1) * N + (y - 1);
}

bool isOutOfBound(int x, int y) {
  return x == 0 || x == N + 1 || y == 0 || y == N + 1;
}

// Disjoint set of unified civil
int parent[MAX_N * MAX_N];
int size[MAX_N * MAX_N];

void initializeDisjointSet(int length) {
  for (int i = 0; i < length; i++) {
    parent[i] = i;
    size[i] = 1;
  }
}

int find(int x) {
  while (x != parent[x]) {
    parent[x] = parent[parent[x]];
    x = parent[x];
  }
  return x;
}

void unionSets(int x, int y) {
  int xRoot = find(x);
  int yRoot = find(y);
  if (xRoot == yRoot) {
    return;
  }
  if (size[xRoot] < size[yRoot]) {
    int temp = xRoot;
    xRoot = yRoot;
    yRoot = temp;
  }
  parent[yRoot] = xRoot;
  size[xRoot] = size[xRoot] + size[yRoot];
}

int main() {
  // Input
  scanf("%d %d", &N, &K);
  for (int i = 0; i < K; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }

  initializeDisjointSet(N * N);

  for (int i = 0; i < K; i++) {
    isCivilized[x[i]][y[i]] = true; // Initial civilization
    currentCivil[i] = Position(x[i], y[i]);
  }
  currentCivilLength = K;

  while (true) {
    // Unify civils
    for (int i = 0; i < currentCivilLength; i++) {
      Position civ = currentCivil[i];
      if (isCivilized[civ.x - 1][civ.y]) {
        unionSets(map(civ.x - 1, civ.y), map(civ.x, civ.y));
      }
      if (isCivilized[civ.x + 1][civ.y]) {
        unionSets(map(civ.x + 1, civ.y), map(civ.x, civ.y));
      }
      if (isCivilized[civ.x][civ.y - 1]) {
        unionSets(map(civ.x, civ.y - 1), map(civ.x, civ.y));
      }
      if (isCivilized[civ.x][civ.y + 1]) {
        unionSets(map(civ.x, civ.y + 1), map(civ.x, civ.y));
      }
    }

    // Count civilizations
    int uniqueCivil = -2; // -2: Initial state, -1: Non-unique civil found
    for (int i = 0; i < currentCivilLength; i++) {
      Position civ = currentCivil[i];
      if (uniqueCivil == -2) {
        uniqueCivil = find(map(civ.x, civ.y));
      } else if (uniqueCivil != find(map(civ.x, civ.y))) {
        uniqueCivil = -1;
        break;
      }
    }

    if (uniqueCivil >= 0) {
      break;
    }

    // Prepare next year
    year += 1;
    int cnt = 0;
    for (int i = 0; i < currentCivilLength; i++) {
      Position civ = currentCivil[i];
      if (!isOutOfBound(civ.x - 1, civ.y) && !isCivilized[civ.x - 1][civ.y]) {
        isCivilized[civ.x - 1][civ.y] = true;
        nextCivil[cnt] = Position(civ.x - 1, civ.y);
        cnt += 1;
      }
      if (!isOutOfBound(civ.x + 1, civ.y) && !isCivilized[civ.x + 1][civ.y]) {
        isCivilized[civ.x + 1][civ.y] = true;
        nextCivil[cnt] = Position(civ.x + 1, civ.y);
        cnt += 1;
      }
      if (!isOutOfBound(civ.x, civ.y - 1) && !isCivilized[civ.x][civ.y - 1]) {
        isCivilized[civ.x][civ.y - 1] = true;
        nextCivil[cnt] = Position(civ.x, civ.y - 1);
        cnt += 1;
      }
      if (!isOutOfBound(civ.x, civ.y + 1) && !isCivilized[civ.x][civ.y + 1]) {
        isCivilized[civ.x][civ.y + 1] = true;
        nextCivil[cnt] = Position(civ.x, civ.y + 1);
        cnt += 1;
      }
    }

    Position *temp = currentCivil;
    currentCivil = nextCivil;
    nextCivil = temp;
    currentCivilLength = cnt;

  }

  printf("%d\n", year);
  return 0;
}
