#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 100000;
struct station {
	double distance;
	double price;
}sta[505];
bool cmp(station a, station b) {
	return a.distance < b.distance;
}
int main() {
	double cmax, d, davg, minprice ;
	int pos = 0, next=1, n,  minpos;
	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	double range = cmax * davg, sum = 0, nowTank = 0, need;
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &sta[i].price, &sta[i].distance);
	}
	sta[n].distance = d;
	sta[n].price = -1;
	sort(sta, sta + n, cmp);
	if (sta[0].distance != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else {
		while (pos < n) {
			minprice = inf;
			minpos = -1;
			for (int i = pos + 1; i <= n && sta[i].distance <= sta[pos].distance + range; i++) {
				if (sta[i].price < minprice) {
					minpos = i;
					minprice = sta[i].price;
					if (minprice < sta[pos].price) {
						break;
					}
				}
			}
			if (minpos == -1) {
				break;
			}
			need = (sta[minpos].distance - sta[pos].distance) / davg;
			if (minprice <= sta[pos].price) {
				if (nowTank >= need) {
					nowTank -= need;
				}
				else {
					sum += (need - nowTank) * sta[pos].price;
					nowTank = 0;
				}
			}
			else {
				sum += (cmax - nowTank) * sta[pos].price;
				nowTank = cmax - need;
			}
			pos = minpos;
		}
		if (minpos == -1) {
			printf("The maximum travel distance = %.2lf", sta[pos].distance+range);
		}
		else {
			printf("%.2lf", sum);
		}
	}
	return 0;
}