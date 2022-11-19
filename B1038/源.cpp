#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
using namespace std;
const int maxn = 100010;
int main() {
	int grade[101];
	memset(grade, 0, sizeof(grade));
	int N, input;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		grade[input]++;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		printf("%d", grade[input]);
		if (i < N - 1) printf(" ");
	}
	return 0;
}