#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;
struct money {
	int Galleon, Sickle, Knut;
};
struct money change(struct money a, struct money b);
int main() {
	struct money P, A;
	scanf("%d.%d.%d%d.%d.%d", &P.Galleon, &P.Sickle, &P.Knut, &A.Galleon, &A.Sickle, &A.Knut);
	struct money ret = change(P, A);
	printf("%d.%d.%d", ret.Galleon, ret.Sickle, ret.Knut);
	return 0;
}

struct money change(struct money a, struct money b) {
	int a1 = a.Galleon * 17 * 29 + a.Sickle * 29 + a.Knut;
	int b1 = b.Galleon * 17 * 29 + b.Sickle * 29 + b.Knut;
	int c1 = b1 - a1;
	struct money c;
	c.Galleon = c1 / (17 * 29);
	c1 = c1 % (17 * 29);
	c1 = abs(c1);
	c.Sickle = c1 / 29;
	c1 = c1 % 29;
	c.Knut = c1;
	return c;
}