#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    const int MaxN = 100000;
    const int MaxM = 10000;
    int A[MaxN], Dis[MaxN];
    int N, M, sum = 0;
    int x, y;
    scanf("%d" , &N);
    Dis[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
        if (i < N - 1)  Dis[i + 1] = sum;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        printf("%d", min(Dis[y - 1] - Dis[x - 1], sum - Dis[y - 1] + Dis[x - 1]));
    }
    return 0;
}
