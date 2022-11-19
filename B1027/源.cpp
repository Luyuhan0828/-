#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int N,num;
	double dnum;
	char sig;
	scanf("%d %c", &N, &sig);
	dnum = floor(sqrt(2.0 * (N + 1))) - 1;
	num = (int)dnum;
	if (0 == num % 2) num = num - 1;
	for (int i = 0; i <= num/2 ; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 0; j < num - 2 * i; j++) {
			printf("%c", sig);
		}
		printf("\n");
	}

	for (int i = (num - 3) / 2; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 0; j < num - 2 * i; j++) {
			printf("%c", sig);
		}
		printf("\n");
	}
	printf("%d", N-(num+1)*(num+1)/2+1);
	return 0;
}