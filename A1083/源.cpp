#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct student{
	char name[12];
	char id[12];
	int grade;
}stu[maxn];
bool cmp(student a, student b) {
	return a.grade > b.grade;
}
int main() {
	int N,grade1,grade2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	scanf("%d%d", &grade1, &grade2);
	sort(stu, stu + N, cmp);
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (stu[i].grade >= grade1 && stu[i].grade <= grade2) {
			if (flag) printf("\n");
			printf("%s %s", stu[i].name, stu[i].id);
			flag = true;
		}
	}
	if (flag == false) printf("NONE");
	return 0;
}