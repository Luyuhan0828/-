#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
int pos[100010];
int temp;
int main() {
	int n, left, notSuit=0, cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		pos[temp] = i;
		if (pos[temp] != temp) {
			notSuit++;
		}
	}
	left = 1;
	while (notSuit > 1) {
		if (pos[0] == 0) {
			for (; left < n; left++) {
				if (pos[left] != left) {
					swap(pos[0], pos[left]);
					cnt++;
					break;
				}
			}
		}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			cnt++;
			notSuit--;
		}
	}
	printf("%d\n", cnt);
	return 0;
}