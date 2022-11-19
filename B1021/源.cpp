#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int count[10] = { 0 };
char digit[1000];
int main() {
	int i;
	scanf("%s", digit);
	int len = strlen(digit);
	for (int j = 0; j < len; j++) {
		i = int(digit[j] - '0');
		count[i]++;
	}
	if (i = 0) printf("0:1");
	for (int j = 0; j < 10; j++) {
		if (count[j] != 0) printf("%d:%d\n", j, count[j]);
	}
	return 0;
}