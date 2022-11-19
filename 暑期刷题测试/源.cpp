#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int compare(int a, int b) {
    return a <= b ? 1 : 0;
}
int main() {
    int  N, totaldistance = 0, temp;
    scanf("%d", &N);
    vector<int> d;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        d.push_back(temp);
        totaldistance += temp;
    }
    int M, d1, d2, circle;
    scanf("%d", &M);
    vector<int> answer;
    for (int i = 0; i < M; i++) {
        circle = 0;
        scanf("%d%d", &d1, &d2);
        if (!compare(d1, d2)) {   //保证d1小于d2
            temp = d1;
            d1 = d2;
            d2 = temp;
        }
        for (int j = d1 - 1; j < d2; j++) {
            circle += d[j];
        }
        if (circle > totaldistance - circle) {
            answer.push_back(totaldistance - circle);
        }
        else {
            answer.push_back(circle);
        }
    }
    for (int i = 0; i < M; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}