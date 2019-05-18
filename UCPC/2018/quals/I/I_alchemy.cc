#include <stdio.h>
using namespace std;

int N;
int effect[10][4][4], color[10][4][4]

int calculate_score(i, j, k, pos_i, pos_j, pos_k) {
  int pot_effect[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
  int pot_color[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
  int pos_i_x = pos_i & 1;
  int pos_i_y = pos_i & 2 >> 1;
  int pos_i_r = pos_i & 12 >> 2;
  int pos_j_x = pos_j & 1;
  int pos_j_y = pos_j & 2 >> 1;
  int pos_j_r = pos_j & 12 >> 2;
  int pos_k_x = pos_k & 1;
  int pos_k_y = pos_k & 2 >> 1;
  int pos_k_r = pos_k & 12 >> 2;

  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      if (pos_i_r == 0) {
        pot_effect[x+pos_i_x][y+pos_i_y] += effect[i][x][y];
        pot_color[x+pos_i_x][y+pos_i_y] = color[i][x][y] == 0 ? pot_color[x+pos_i_x][y+pos_i_y] : color[i][x][y];
      } else if (pos_i_r == 1) {
        pot_effect[x+pos_i_x][y+pos_i_y] += effect[i][y][3-x];
        pot_color[x+pos_i_x][y+pos_i_y] = color[i][y][3-x] == 0 ? pot_color[x+pos_i_x][y+pos_i_y] : color[i][y][3-x];
      } else if (pos_i_r == 2) {
        pot_effect[x+pos_i_x][y+pos_i_y] += effect[i][3-x][3-y];
        pot_color[x+pos_i_x][y+pos_i_y] = color[i][3-x][3-y] == 0 ? pot_color[x+pos_i_x][y+pos_i_y] : color[i][3-x][3-y];
      } else {
        pot_effect[x+pos_i_x][y+pos_i_y] += effect[i][3-y][x];
        pot_color[x+pos_i_x][y+pos_i_y] = color[i][3-y][x] == 0 ? pot_color[x+pos_i_x][y+pos_i_y] : color[i][3-y][x];
      }
    }
  }
}

int main() {
  scanf("%d", N);

  for (int i = 0; i < N; i++) {
    for (int row = 0; row < 4; row++) {
      scanf("%d %d %d %d", effect[i][row][0], effect[i][row][1], effect[i][row][2], effect[i][row][3]);
    }
    for (int row = 0; row < 4; row++) {
      scanf("%d %d %d %d", color[i][row][0], color[i][row][1], color[i][row][2], color[i][row][3]);
    }
  }

  int max_score = 0

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == i) { break; }
      for (int k = 0; k < N; k++) {
        if (k == i || k == j) { break; }

        for (int pos_i = 0; pos_i < 16; pos_i++) {
          for (int pos_j = 0; pos_j < 16; pos_j++) {
            for (int pos_k = 0; pos_k < 16; pos_k++) {
              int score = calculate_score(i, j, k, pos_i, pos_j, pos_k);
              if (score > max_score) {
                max_score = score
              }
        }
      }
    }
  }

  printf("%d\n", max_score);
}
