#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool HashTable[101];
int a[110];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	memset(HashTable, false, sizeof(HashTable));
	memset(a, 0, sizeof(a));
	int n, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		a[i] = temp;
		while (temp > 1) {
			if (temp % 2 == 0) {
				temp /= 2;
				if (temp < 101) HashTable[temp] = true;
			}
			else {
				temp = (temp * 3 + 1)/2;
				if (temp < 101) HashTable[temp] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (HashTable[a[i]] == true) {
			a[i] = 0;
		}
		else {
			cnt++;
		}
	}
	sort(a, a + n,cmp);
	for (int i = 0; i < cnt; i++) {
		printf("%d", a[i]);
		if (i < cnt - 1) printf(" ");
	}
	return 0;
}