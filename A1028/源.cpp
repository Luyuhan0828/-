#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct {
	int id, grade;
	char name[10];
}stu_info;
stu_info stu[100010];
bool cmp1(stu_info a, stu_info b) {
	return a.id < b.id;
}
bool cmp2(stu_info a, stu_info b) {
	if (0!=strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else return a.id < b.id;
}

bool cmp3(stu_info a, stu_info b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main() {
	int N, C;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if (1 == C) {
		sort(stu, stu + N, cmp1);
	}
	else if (2 == C) {
		sort(stu, stu + N, cmp2);
	}
	else if (3 == C) {
		sort(stu, stu + N, cmp3);
	}
	for (int i = 0; i < N; i++) {
		printf("%06d %s %d", stu[i].id, stu[i].name, stu[i].grade);
		if (i < N - 1) printf("\n");
	}
	return 0;
}