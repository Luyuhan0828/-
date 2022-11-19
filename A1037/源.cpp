#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
long long coupon[maxn], value[maxn];
int main() {
	int nc, np;
	long long sum = 0;
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++) {
		scanf("%lld", &coupon[i]);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++) {
		scanf("%lld", &value[i]);
	}
	sort(coupon, coupon + nc);
	sort(value, value + np);
	int pc=0, pp=0;
	while (coupon[pc] < 0) {
		pc++;
	}
	while (value[pp] < 0) {
		pp++;
	}
	int p = 0;
	while (p < pc && p < pp) {
		sum += coupon[p] * value[p];
		p++;
	}
	pc = nc - 1;
	pp = np - 1;
	while (coupon[pc] > 0) {
		pc--;
	}
	while (value[pp] > 0) {
		pp--;
	}
	int p1 = nc - 1;
	int p2 = np - 1;
	while (p1 > pc && p2 > pp) {
		sum += coupon[p1] * value[p2];
		p1--,p2--;
	}
	printf("%lld", sum);
	return 0;
}