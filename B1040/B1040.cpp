#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;
const int MAXINT = 100010;
int leftPNumber[MAXINT] = { 0 };
char input[MAXINT];
int main() {
	int cnt = 0;
	int rightcnt = 0;
	gets_s(input);
	int len = strlen(input);
	if (len < 3) {
		cnt = 0;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (i > 0) leftPNumber[i] = leftPNumber[i - 1];
			if (input[i] == 'P') leftPNumber[i]++;
		}
		for (int i = len - 1; i > 0; i--) {
			if (input[i] == 'T') rightcnt++;
			else if (input[i] == 'A') cnt += rightcnt * leftPNumber[i - 1];
		}
	}
	printf("%d", cnt);
	return 0;
}