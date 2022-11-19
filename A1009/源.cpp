#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const int MaxN = 1010;
float A[MaxN] = { 0 }, B[MaxN] = { 0 }, C[2*MaxN] = { 0 };
int main() {
	int k, n, count = 0, flag=0;
	float a;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%f", &n, &a);
		A[n] = a;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%f", &n, &a);
		B[n] = a;
	}
	for (int i = 0; i < MaxN; i++) {
		for (int j = 0; j < MaxN; j++) {
			if (C[i + j] != 0) flag = 1;
			C[i + j] += A[i] * B[j];
			if (C[i + j] == 0 && flag==1) count--;
			else if(flag==0 && C[i+j]!=0) count++;
			flag = 0;
		}
	}
	printf("%d", count);
	for (int i = 2*MaxN - 1; i >= 0; i--) {
		if (C[i]) {
			printf(" %d %.1f", i, C[i]);
		}
	}
	return 0;
}