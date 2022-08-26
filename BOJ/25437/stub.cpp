#include "towns.h"

#include <cassert>
#include <cstdio>

#include <string>
#include <vector>

static int N;
static std::vector<std::string> R;
static int Q;

static inline void protocol_violation(std::string message) {
  printf("Protocol Violation: %s\n", message.c_str());
  exit(0);
}

bool check_road(int A, int B) {
  if (Q >= 40000) {
    protocol_violation("too many questions");
  }
  ++Q;
  if (A == B || A < 0 || A >= N || B < 0 || B >= N) {
    protocol_violation("invalid parameters");
  }
  return R[A][B] == '1';
}

int main() {
  assert(1 == scanf("%d", &N));
  R.resize(N);

  for (int i = 0; i < N; ++i) {
    char buffer[N + 1];
    assert(1 == scanf("%s", buffer));
    R[i] = buffer;
  }

  int answer = find_town(N);
  printf("%d\n", answer);
  printf("%d\n", Q);
  return 0;
}
