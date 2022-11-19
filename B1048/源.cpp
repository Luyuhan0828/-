#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void reverse(char a[]);
int main() {
	char str1[110] = { '\0' }, str2[110] = { '\0' }, res[110] = { '\0' };
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	reverse(str1);
	reverse(str2);
	int len = max(len1, len2);
	int a, b, count=0;
	while (count<len) {
		if (str1[count] != '\0') a = str1[count] - '0';
		else a = 0;
		if (str2[count] != '\0') b = str2[count] - '0';
		else b = 0;
		if (a+b == 10) res[count] = 'J';
		else if (a + b == 11) res[count] = 'Q';
		else if (a + b == 12) res[count] = 'K';
		else res[count] = '0'+(a + b) % 13;
		count += 2;
 	}
	count = 1;
	while (count < len) {
		if (str1[count] != '\0') a = str1[count] - '0';
		else a = 0;
		if (str2[count] != '\0') b = str2[count] - '0';
		else b = 0;
		if ( b>=a ) res[count] = b-a + '0';
		else res[count] = b-a+10+'0';
		count += 2;
	}
	int pos = 101;
	int flag = 0;
	while (res[pos] == '\0') pos--;
	for (int i = pos; i >= 0; i--) {
		if (flag == 0 && res[i] == '0') continue;
		printf("%c", res[i]);
		flag = 1;
	}
		return 0;
}

void reverse(char a[]) {
	int len = strlen(a);
	int temp;
	for (int i = 0; i < len/2; i++) {
		temp = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = temp;
	}
}
