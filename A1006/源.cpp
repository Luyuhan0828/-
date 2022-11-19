#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
struct person {
	char id[16];
	int inhour, inmin, insecond, outhour, outmin, outsecond;
};

bool sign_in(person a, person b) {  //a比b早到为真
	if (a.inhour != b.inhour) return a.inhour < b.inhour;
	if (a.inmin != b.inmin) return a.inmin < b.inmin;
	return a.insecond < b.insecond;
}
bool sign_out(person a, person b) {  //a比b晚走为真
	if (a.outhour != b.outhour) return a.outhour > b.outhour;
	if (a.outmin != b.outmin) return a.outmin > b.outmin;
	return a.outsecond > b.outsecond;
}

int main() {
	person earliest, latest, temp;
	earliest.inhour = 24;
	earliest.inmin = 60;
	earliest.insecond = 60;
	latest.outhour = 0;
	latest.outmin = 0;
	latest.outsecond = 0;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s%d:%d:%d%d:%d:%d", &temp.id, &temp.inhour, &temp.inmin, &temp.insecond, &temp.outhour, &temp.outmin, &temp.outsecond);
		if (sign_in(temp, earliest)) {
			earliest = temp;
		}
		if (sign_out(temp, latest)) {
			latest = temp;
		}
	}
	printf("%s %s", earliest.id, latest.id);
	return 0;
}