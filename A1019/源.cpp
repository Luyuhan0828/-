#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main() {
	int N, base, goal[100] = {0}, i=0;
	bool flag = true;
	scanf("%d%d", &N, &base);
	while (N > 0) {
		goal[i++] = N % base;
		N = N / base;
	}
	for (int j = 0; j < i-1-j ; j++) {
		if (goal[j] != goal[i - 1 - j]) {
			flag = false;
			break;
		}
	}
	if (flag) printf("Yes");
	else printf("No");
	printf("\n");
	i--;
	printf("%d", goal[i--]);
	while (i >= 0) {
		printf(" %d", goal[i--]);
	}
	return 0;
}