#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
char str[10010], output[10010];
int main() {
	scanf("%s",str);
	int pos = 0, exp=0;
	while (str[pos] != 'E') {
		pos++;
	}
	int len = strlen(str);
	for (int i = pos+2; i <len; i++) {
		exp *= 10;
		exp +=(int) (str[i]-'0');
	}
	if (exp == 0) {
		if (str[0] == '-') printf("-");
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
		return 0;
	}
	if (str[pos + 1] == '-') {
		if (str[0] == '-') printf("-");
		printf("0.");
		for (int i = 1; i < exp; i++) {
			printf("0");
		}
		printf("%c", str[1]);
		for (int i = 3; i < pos; i++) {
			printf("%c", str[i]);
		}
	}
	else if (str[pos + 1] == '+') {
		if (str[0] == '-') printf("-");
		printf("%c",str[1]);
		int j = 0;
		for (;j < exp; j++) {
			if (j + 3 == pos) break;
			printf("%c", str[j + 3]);
		}
		if (j + 3 == pos && j < exp) {
			for (; j < exp; j++) printf("0");
		}
		else if (j + 3 < pos && j == exp) {
			printf(".");
			for (; j + 3 < pos; j++) {
				printf("%c", str[j + 3]);
			}
		}
	}
	return 0;
}