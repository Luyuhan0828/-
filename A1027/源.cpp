#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main() {
	char transfer[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
	int R, G, B;
	scanf("%d%d%d", &R, &G, &B);
	printf("#%c%c", transfer[R / 13], transfer[R % 13]);
	printf("%c%c", transfer[G/ 13], transfer[G % 13]);
	printf("%c%c", transfer[B / 13], transfer[B % 13]);
	return 0;
}