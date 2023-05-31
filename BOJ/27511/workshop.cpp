#include "workshop.h"
#include <bits/stdc++.h>
using namespace std;
// 100,000 <= binom(20, 10)
// 20 = binom(6, 3)
// 6 = binom(4, 2)
// 4 -> 3 (change 3 to 0, 1, 2)

vector<int> C20, C6, C4;
int color[4][4][4];

void init() {
  for (int b=0; b<1<<20; b++) {
    if (__builtin_popcount(b) == 10) C20.push_back(b);
  }
  for (int b=0; b<1<<6; b++) {
    if (__builtin_popcount(b) == 3) C6.push_back(b);
  }
  for (int b=0; b<1<<4; b++) {
    if (__builtin_popcount(b) == 2) C4.push_back(b);
  }
}

int morning(int my_num, int right_num) {
  int b = ~C20[my_num] & C20[right_num];
  int c = 0;
  for (; (b&1) == 0; b/=2, c++) {}
  return c;
}

int afternoon(int left_num, int my_num, int right_num) {
  int b1 = ~C6[left_num] & C6[my_num];
  int b2 = ~C6[my_num] & C6[right_num];
  int c1 = 0;
  int c2 = 0;
  for (; (b1&1) == 0; b1/=2, c1++) {}
  for (; (b2&1) == 0; b2/=2, c2++) {}

  int b3 = ~C4[c1] & C4[c2];
  int c3 = 0;
  for (; (b3&1) == 0; b3/=2, c3++) {}

  return c3;
}

int evening(int left_num, int my_num, int right_num) {
  if (my_num < 3) return my_num;
  int c = 0;
  for (; c<3; c++) {
    if (c != left_num && c != right_num) break;
  }
  return c;
}
