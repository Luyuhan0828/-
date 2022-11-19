#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	int  sum = 0, res[100] = {0}, i=0;
	char pro[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char input[102];
	scanf("%s", input);
	int len = strlen(input);
	while (i < len) {
		sum += input[i]-'0';
		i++;
	}
	i = 0;
	while (sum > 0) {
		res[i++] = sum % 10;
		sum /= 10;
	}
	for (i = i - 1; i >= 0; i--) {
		printf("%s", pro[res[i]]);
		if (i > 0) printf(" ");
	}
	return 0;
}