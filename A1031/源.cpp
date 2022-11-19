#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
using namespace std;
int main() {
	char str[100], fig[40][40];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			fig[i][j] = ' ';
		}
	}
	int n1, n2, pos=0;
	n1 = (len + 2) / 3;
	n2 = len + 2 - 2 * n1;
	for (int i = 0; i < n1; i++) {
		fig[i][0] = str[pos++];
	}
	for (int i = 1; i < n2; i++) {
		fig[n1 - 1][i] = str[pos++];
	}
	for (int i = n1 - 2; i >= 0; i--) {
		fig[i][n2 - 1] = str[pos++];
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			printf("%c", fig[i][j]);
		}
		printf("\n");
	}
	return 0;
}