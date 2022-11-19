#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct {
	char name[10];
	int age, worth;
}billionares;
int number, Amin,Amax;
billionares bil[100010], valid[100010];

bool cmp(billionares a, billionares b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	int N, K, rec[200] = { 0 };
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d", bil[i].name, &bil[i].age, &bil[i].worth);
	}
	sort(bil, bil + N, cmp);
	int cnt = 0, flag=0;
	for (int i = 0; i < N; i++) {
		if (rec[bil[i].age] < 101) {
			valid[cnt] = bil[i];
			cnt++;
			rec[bil[i].age]++;
		}
	}
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &number, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		flag = 0;
		for(int j = 0; j < cnt && flag<number; j++) {
			if (valid[j].age >= Amin && valid[j].age <= Amax) {
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
				flag++;
			}
		}
		if (flag == 0) printf("None\n");
	}

	return 0;
}