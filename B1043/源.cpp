#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
using namespace std;
char input[1010];
char corr[7] = { 'P','A','T','e','s','t' };
int main() {
	int count[6], sum=0;
	memset(count, 0, sizeof(count));
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		switch (input[i]) {
		case 'P':
			count[0]++;
			sum++;
			break;
		case 'A':
			count[1]++;
			sum++;
			break;
		case 'T':
			count[2]++;
			sum++;
			break;
		case 'e':
			count[3]++;
			sum++;
			break;
		case 's':
			count[4]++;
			sum++;
			break;
		case 't':
			count[5]++;
			sum++;
			break;
		default:
			continue;
		}
	}
	while (sum>0) {
		for (int i = 0; i < 6; i++) {
			if (count[i] > 0) {
				printf("%c", corr[i]);
				count[i]--;
				sum--;
			}
		}
	}
	return 0;
}