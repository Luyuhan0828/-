#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
typedef struct {
	int g, s, k;
}currency;
int main() {
	currency a, b;
	int k_carry = 0, s_carry = 0;
	scanf("%d.%d.%d%d.%d.%d", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
	if ((a.k + b.k) / 29) k_carry++;
	a.k = (a.k + b.k) % 29;
	if ((a.s + b.s + k_carry) / 17) s_carry++;
	a.s = (a.s + b.s + k_carry) % 17;
	a.g = a.g + b.g + s_carry;
	printf("%d.%d.%d", a.g, a.s, a.k);
	return 0;
}