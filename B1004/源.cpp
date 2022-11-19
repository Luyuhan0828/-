#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

struct {
	char name[11];
	char id[11];
	int grade;
}stu_info, max_val, min_val;

int main() {
	int n;
	max_val.grade = -1;
	min_val.grade = 101;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stu_info.name, stu_info.id, &stu_info.grade);
		if (stu_info.grade > max_val.grade) {
			max_val = stu_info;
		}
		if (stu_info.grade < min_val.grade) min_val = stu_info;
	}
	printf("%s %s\n", max_val.name, max_val.id);
	printf("%s %s", min_val.name, min_val.id);
	return 0;
}