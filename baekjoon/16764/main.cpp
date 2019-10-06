#include <bits/stdc++.h>
#include <string>
#include <tuple>
using namespace std;

#define MAX_N 50000
#define MAX_FLAVORS 1000000

int N, favorites[MAX_N][5], compatible[MAX_N];
typedef vector<int> FavoriteSubset;
map<FavoriteSubset, int> multi_compatible;

template<typename T>
ostream& operator << (ostream& os, vector<T> vec)
{
    os << "{";
    if (vec.size() > 0) {
      copy(vec.begin(), vec.end() - 1, ostream_iterator<T>(os, ", "));
      os << *(vec.end() - 1);
    }
    os << "}";
    return os;
}

void input() {
  scanf("%d", &N);
  for (int i = 0; i < N; i ++) {
    scanf(
      "%d %d %d %d %d",
      &favorites[i][0],
      &favorites[i][1],
      &favorites[i][2],
      &favorites[i][3],
      &favorites[i][4]
    );
    sort(favorites[i], favorites[i + 1]);
  }
  // for (int i = 0; i < N; i ++) {
  //   printf(
  //     "%d %d %d %d %d\n",
  //     favorites[i][0],
  //     favorites[i][1],
  //     favorites[i][2],
  //     favorites[i][3],
  //     favorites[i][4]
  //   );
  // }
}

void count() {
  for (int i = 0; i < N; i ++) {
    for (int sel = 1; sel < 32; sel ++) {
      FavoriteSubset sub;
      for (int d = 0; d < 5; d ++) {
        if ((sel >> d) & 1) sub.push_back(favorites[i][d]);
      }

      auto it = multi_compatible.find(sub);
      if (it != multi_compatible.end()) {
        int alt = 1;
        if (sub.size() % 2 == 0) alt = -1;
        compatible[i] += alt * multi_compatible[sub];
        multi_compatible[sub] ++;
      } else {
        multi_compatible[sub] = 1;
      }
    }
  }

  long long incompatible = (long long)N * (N - 1) / 2;
  for (int i = 0; i < N; i ++) {
    // printf("compatible[%d] = %d\n", i, compatible[i]);
    incompatible -= compatible[i];
  }

  printf("%lld\n", incompatible);
}

int main() {
  input();
  count();
  return 0;
}
