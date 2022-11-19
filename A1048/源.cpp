#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int HashTable[1010];
int main() {
	memset(HashTable, 0, sizeof(HashTable));
	int n, m, temp;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		HashTable[temp]++;
	}
	bool flag = false;
	int cnt = 1, v1,v2;
	while (!flag) {
		if (HashTable[cnt] > 0 && HashTable[m-cnt]>0) {
			if (cnt != m - cnt) {
				flag = true;
				v1 = cnt;
				v2 = m - cnt;
				printf("%d %d", v1, v2);
			}
			else {
				if (HashTable[cnt] > 1) {
					flag = true;
					v1 = cnt;
					v2 = cnt;
					printf("%d %d", v1, v2);
				}
			}
		}
		cnt++;
		if (cnt == 501) {
			printf("No Solution");
			break;
		}
	}
	//if (flag == true) {
	//	printf("%d %d", v1, v2);
	//}
	//else {
	//	printf("No Solution");
	//}
	return 0;
}