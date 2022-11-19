#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	int  i=0, sum=0;
	char N[111]; 
	scanf("%s", &N);
	if (!strcmp(N,"0")) {
		printf("zero");
		return 0;
	}
	int len = strlen(N);
	char output[10][10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int res[110] = { 0 };
	while (i<len) {
		sum += N[i]-'0';
		i++;
	}
	i = 0;
	while (sum > 0) {
		res[i++] = sum % 10;
		sum /= 10;
	}
	i--;
	while (i >= 0) {
		if (i != 0) printf("%s ", output[res[i]]);
		else printf("%s", output[res[i]]);
		i--;
	}
	return 0;
}