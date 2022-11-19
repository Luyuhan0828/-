#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const int MaxN = 1010;
float A[MaxN] = { 0 }, B[MaxN] = { 0 };
int main() {
	int k,n,count=0;
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
		A[i] += B[i];
		if (A[i]) count++;
	}
	printf("%d ", count);
	for (int i = MaxN-1; i >= 0& count>0; i--) {
		if (A[i]) {
			printf("%d %.1f", i, A[i]);
			count--;
			if (count) printf(" ");
		}
	}
	return 0;
}