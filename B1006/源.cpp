#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main() {
	int n, b, s, g;
	scanf("%d", &n);
	b = n / 100;
	n = n % 100;
	s = n / 10;
	n = n % 10;
	g = n;
	for (int i = 0; i < b; i++) {
		printf("B");
	}
	for (int i = 0; i < s; i++) {
		printf("S");
	}
	for (int i = 1; i <= g; i++) {
		printf("%d", i);
	}
	return 0;
}