#include <cstdio>
#include <cstdlib>
#include <vector>

extern std::vector<long long> find_minimum_costs (int N, std::vector<int> A, std::vector<int> B);

void my_assert (bool x) {
  if (!x) {
    puts("Input error!");
    exit(0);
  }
}

int main() {
  int N, M;
  my_assert(scanf("%d", &N) == 1);
  my_assert(scanf("%d", &M) == 1);

  std::vector<int> A(M), B(M);
  for (int i = 0 ; i < M; i++) {
    my_assert(scanf("%d", &A[i]) == 1);
    my_assert(scanf("%d", &B[i]) == 1);
  }

  auto ans = find_minimum_costs(N, A, B);
  
  if (int(ans.size()) != N) {
    puts("Size of array C is not N");
    exit(0);
  }

  for (long long x : ans) {
    printf("%lld\n", x);
  }

  return 0;
}
