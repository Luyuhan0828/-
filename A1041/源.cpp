#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
using namespace std;
int cnt[10010];
int input[100010];
int main() {
	memset(cnt, 0, sizeof(cnt));
	int N, temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		cnt[temp]++;
		input[i] = temp;
	}
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (cnt[input[i]]==1) {
			printf("%d", input[i]);
			flag = true;
			break;
		}
	}
	if (flag == false) printf("None");
	return 0;
}
