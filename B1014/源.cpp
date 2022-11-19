#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	char str1[61], str2[61], str3[61], str4[61];
	scanf("%s%s%s%s", str1, str2, str3, str4);
	int len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3), len4 = strlen(str4);
	int i = 0;
	char week[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	for (i = 0; i < 60; i++) {
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {
			printf("%s ", week[str1[i] - 'A']);
			break;
		}
	}
	for (i=i+1 ; i < 61; i++) {
		if (str1[i] == str2[i]) {
			if (str1[i] >= '0' && str1[i] <= '9') {
				printf("%02d:", str1[i]-'0');
				break;
			}
			else if (str1[i] >= 'A' && str1[i] <= 'N') {
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			}
		}
	}
	for (i = 0; i < 61; i++) {
		if (str3[i] == str4[i]) {
			if ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')) {
				printf("%02d", i);
				break;
			}
		}
	}
	return 0;
}