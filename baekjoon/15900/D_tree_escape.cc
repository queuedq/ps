#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_N 500000
#define TRUE 1
#define FALSE 0

int N;
vector<int> edge[MAX_N+1];
int node_stack[MAX_N+1];
int distance_stack[MAX_N+1];
int pointer = 0;
int visited[MAX_N+1];

int main() {
  scanf("%d", &N);

  for (int i = 1; i <= N - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  // DFS
  node_stack[0] = 1;
  distance_stack[0] = 0;
  visited[1] = TRUE;

  int win = FALSE;

  while (pointer >= 0) {
    int node = node_stack[pointer];
    int distance = distance_stack[pointer];
    pointer--;
    int cnt_unvisited = 0;

    for (int i = 0; i < edge[node].size(); i++) {
      int adjacent = edge[node][i];
      if (!visited[adjacent]) {
        pointer++;
        node_stack[pointer] = adjacent;
        distance_stack[pointer] = distance + 1;
        visited[adjacent] = TRUE;
        cnt_unvisited++;
      }
    }
    if (cnt_unvisited == 0) { // Leaf node
      // printf("(%d, %d)\n", node, distance);
      win ^= (distance % 2 == 1);
    }
  }

  if (win) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
