#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
typedef struct {
	int year, month, day;
	char name[6];
}resident;

bool compare(resident a, resident b) {   //如果a比b小，则返回true
	int a_val = a.year * 1000000 + a.month * 1000 + a.day;
	int b_val = b.year * 1000000 + b.month * 1000 + b.day;
	return a_val > b_val;
}

bool judge(resident a) {   //在范围内则为真
	if (a.year > 1814 && a.year < 2014) {
		return true;
	}
	if (a.year == 1814) {
		if (a.month > 9) return true;
		if (a.month == 9)
			if (a.day >= 6) return true;
	}
	if (a.year == 2014) {
		if (a.month < 9) return true;
		if (a.month == 9)
			if (a.day <= 6) return true;
	}
	return false;
}

int main() {
	resident person, oldest, youngest;
	oldest.year = 2014;
	oldest.month = 9;
	oldest.day = 7;
	youngest.year = 1814;
	youngest.month = 9;
	youngest.day = 5;
	int N, count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d/%d/%d", person.name, &person.year, &person.month, &person.day);
		if (judge(person)) {
			count++;
			if (!compare(person, oldest)) {
				for (int j = 0; j < 6; j++) {
					oldest.name[j] = person.name[j];
				}
				oldest.year = person.year;
				oldest.month = person.month;
				oldest.day = person.day;
			}
			if (compare(person, youngest)) {
				for (int j = 0; j < 6; j++) {
					youngest.name[j] = person.name[j];
				}
				youngest.year = person.year;
				youngest.month = person.month;
				youngest.day = person.day;
			}
		}
	}
	if (0 == count) printf("0");
	else printf("%d %s %s", count, oldest.name, youngest.name);
	return 0;
}