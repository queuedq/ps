#include <stdio.h>
#include <math.h>

#define MAX_N 500
#define INF 987654321

int N, K;
int pref[MAX_N];

double avg(int* arr, int l, int r) {
  double sum = 0;
  for (int i = l; i < r; i++) {
    sum += arr[i];
  }
  return sum / (r - l);
}

double stddev(int* arr, int l, int r) {
  double m = avg(arr, l, r);
  double sum = 0;
  for (int i = l; i < r; i++) {
    sum += (arr[i] - m) * (arr[i] - m);
  }
  return sqrt(sum / (r - l));
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d", &pref[i]);

  double minStddev = INF;
  for (int i = 0; i < N; i++) {
    for (int j = i + K; j <= N; j++) {
      double d = stddev(pref, i, j);
      if (d < minStddev) {
        minStddev = d;
      }
    }
  }

  printf("%.11g\n", minStddev);
  return 0;
}
