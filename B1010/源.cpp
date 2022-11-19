#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	const int MaxN = 1010;
	int coe[MaxN] = { 0 };
	int i,c,count=0;
	while (scanf("%d%d",  &c, &i) != EOF) {
		coe[i] = c;
	}
	for (int i = 1; i < MaxN; i++) {
		coe[i - 1] = coe[i] * i;
		coe[i] = 0;
		if (coe[i - 1] != 0) count++;
	}
	if (!count) printf("0 0");
	for (int i = 1000; count > 0; i--) {
		if (coe[i] != 0) {
			printf("%d %d", coe[i], i);
			count--;
			if (count) printf(" ");
		}
	}
	return 0;
}