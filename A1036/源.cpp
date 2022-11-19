#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
typedef struct student {
	char name[11];
	char gender;
	char id[11];
	int grade;
}stu;
int main() {
	int N;
	stu male_lowest, female_highest, temp;
	male_lowest.grade = 101;
	female_highest.grade = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %c %s%d", temp.name, &temp.gender, temp.id, &temp.grade);
		if (temp.gender == 'M' && temp.grade < male_lowest.grade) male_lowest = temp;
		if (temp.gender == 'F' && temp.grade > female_highest.grade) female_highest = temp;
	}
	if (female_highest.grade >= 0) printf("%s %s\n", female_highest.name, female_highest.id);
	else printf("Absent\n");
	if (male_lowest.grade <= 100) printf("%s %s\n", male_lowest.name, male_lowest.id);
	else printf("Absent\n");
	if (female_highest.grade >= 0 && male_lowest.grade <= 100) printf("%d", female_highest.grade - male_lowest.grade);
	else printf("NA");
	return 0;
}