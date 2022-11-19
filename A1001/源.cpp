#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int a, b, c, i = 0, count=0;
	scanf("%d%d", &a, &b);
	c = a + b;
	if (c == 0) {
		printf("0");
		return 0;
	}
	char str[1000010] = { '\0' };
	int flag = 0;
	if (c < 0) {
		c = abs(c);
		flag = 1;
	}
	while (c > 0) {
		str[i++] = c % 10 + '0';
		c = c / 10;
		count++;
		if (count % 3 == 0 && c>0) {
			str[i++] = ',';
			count = 0;
		}
	}
	if (flag) str[i] = '-';
	else i--;
	for (; i >= 0; i--) {
		printf("%c", str[i]);
	}
	return 0;
}