#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL inf = (1LL << 63) - 1;
char N1[15], N2[15], temp[15];
int tag;
int map[256];
LL cal_sum(char* N, int radix) {
	int len = strlen(N);
	LL sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum * radix + map[N[i]];
	}
	return sum;
}
void init() {
	for (char c = '0'; c <= '9'; c++) {
		map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++) {
		map[c] = c - 'a' + 10;
	}
}
LL covertToDecimal(char* N, LL radix, LL maxium) {  //返回-1说明溢出
	int len = strlen(N);
	LL sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum * radix + map[N[i]];
		if (sum<0 || sum>maxium) {
			sum = -1;
			break;
		}
	}
	return sum;
}

int searchRadix(char* N) {
	int len = strlen(N);
	int r = 0;
	for (int i = 0; i < len; i++) {
		r = max(map[N[i]], r);
	}
	return r;
}

int binarySearch(char* N, LL n1, LL low, LL high ) {  //返回0表示没找到
	int mid, flag=0;
	LL temp;
	while(high >= low) {
		mid = (high + low) / 2;
		temp = cal_sum(N, mid);
		if (temp > n1) {
			high = mid - 1;
		}
		else if (temp < n1) {
			low = mid + 1;
		}
		else {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		mid = 0;
	}
	return mid;
}



int main() {
	LL radix;
	scanf("%s %s %d %lld", N1, N2, &tag, &radix);
	if (tag == 2) {
		strcpy(temp, N2);
		strcpy(N2, N1);
		strcpy(N1, temp);
	}
	init();
	LL n1 = covertToDecimal(N1, radix, inf);
	LL leastRadix = searchRadix(N2) + 1;
	LL maxRadix = max(leastRadix, n1) + 1;
	LL res = binarySearch(N2, n1, leastRadix, maxRadix);
	if (res == 0) {
		printf("Impossible");
	}
	else {
		printf("%d", res);
	}
	return 0;
}