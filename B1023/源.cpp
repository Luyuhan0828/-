#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int digit[10];
int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &digit[i]);
	}
	for (int i = 1; i < 10; i++) {
		if (digit[i] > 0) {
			printf("%d", i);
			digit[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		while (digit[i] > 0) {
			printf("%d", i);
			digit[i]--;
		}
	}
	return 0;
}