#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;
int pos(char a) {
	if (a >= '0' && a <= '9') {
		return a - '0';
	}
	else if (a >= 'a' && a <= 'z') {
		return a - 'a' + 10;
	}
	else if (a >= 'A' && a <= 'Z') {
		return a - 'A' + 36;
	}
}
int main() {
	int zhuzi[80];
	memset(zhuzi, 0, sizeof(zhuzi));
	char str1[maxn], str2[maxn];
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {
		zhuzi[pos(str1[i])]++;
	}
	int miss = 0;
	for (int i = 0; i < len2; i++) {
		if (zhuzi[pos(str2[i])] > 0) zhuzi[pos(str2[i])]--;
		else miss++;
	}
	if (miss == 0) {
		for (int i = 0; i < 80; i++) {
			miss += zhuzi[i];
		}
		printf("Yes %d", miss);
	}
	else {
		printf("No %d", miss);
	}
	return 0;
}