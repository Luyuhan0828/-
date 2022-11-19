#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	int count[128];
	memset(count, 0, sizeof(count));
	int i = 0;
	char c;
	while (scanf("%c",&c)) {
		if (c == '\n') break;
		if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
			count[c]++;
		}
		else {
			count[c]++;
		}
	}
	int max = count['a'];
	int pos = 'a';
	for (i = 'b'; i <= 'z'; i++) {
		if (count[i] > max) {
			max = count[i];
			pos = i;
		}
	}
	printf("%c %d", pos, max);
	return 0;
}