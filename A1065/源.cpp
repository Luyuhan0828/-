#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
bool judge(long long a,long long b,long long c) {
    bool flag;
    if (a > 0 && b > 0 && a + b < 0) {
        flag = true;
    }
    else if (a < 0 && b < 0 && a + b>=0) {  //负上溢结果可能为0
        flag = false;
    }
    else {
        if (a + b > c) flag = true;
        else flag = false;
    }
    return flag;
}

int main() {
    int T;
    long long A, B, C;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        if (judge(A, B, C)) printf("Case #%d: true\n",i+1);
        else printf("Case #%d: false\n",i+1);
    }
    return 0;
}