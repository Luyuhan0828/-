#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main() {
	char ID[20];
	int n,  count=0 ,flag, sum, weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char value[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	scanf("%d", &n);
	while (n > 0) {
		sum = 0;
		flag = 0;
		scanf("%s", ID);
		for (int i = 0; i < 17; i++) {
			if (ID[i] > '9' || ID[i] < '0') {
				flag = 1;
				break;
			}
			sum =sum + weight[i] * (ID[i] - '0');
		}
		sum = sum % 11;
		if (ID[17] != value[sum]) flag = 1;
		if (flag) {
			if (count > 0) printf("\n");
			printf("%s", ID);
			count++;
		}
		n--;
	}
	if (0 == count) printf("All passed\n");
	return 0;
}