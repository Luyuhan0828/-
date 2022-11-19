#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
bool cmp(int a, int b) {
	return a > b;
}
//struct participant {
//	int team, teammate;
//	int grade;
//}stu[maxn];
int sum_grade[maxn];
int main() {
	int N;
	memset(sum_grade, 0, sizeof(sum_grade));
	int indivisual, t, grade;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d-%d%d", &t, &indivisual, &grade);
		sum_grade[t] += grade;
	}
	int maxpos=0;
	for (int i = 1; i < maxn; i++) {
		if (sum_grade[i] > sum_grade[maxpos]) maxpos = i;
	}
	printf("%d %d", maxpos, sum_grade[maxpos]);
	return 0;
}