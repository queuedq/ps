#include "squirrel.h"
#include <cstdio>
#include <vector>

int main() {
    int N;
    scanf("%d", &N);
    
    std::vector<int> D(N), H(N), W(N);
    for (int i=0; i<N; i++) scanf("%d %d %d", &D[i], &H[i], &W[i]);
    
    int L, R;
    scanf("%d %d", &L, &R);

    long long ret=fly(D, H, W, L, R);
    printf("%lld\n", ret);

    return 0;
}
