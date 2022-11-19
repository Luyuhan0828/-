#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
typedef struct {
	char name[11], password[11];
	bool flag;
}stu_info;
bool transfer(char* str, int len);
int main() {
	int N, len,count=0;
	stu_info stu[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s", stu[i].name, stu[i].password);
		len = strlen(stu[i].password);
		stu[i].flag = transfer(stu[i].password, len);
		if (stu[i].flag) count++;
	}
	if (count == 0) {
		if(N>1) printf("There are %d accounts and no account is modified", N);
		else if(N==1) printf("There is 1 account and no account is modified");
	}
	else {
		printf("%d\n", count);
		for (int i = 0; i < N; i++) {
			if (stu[i].flag) {
				printf("%s %s", stu[i].name, stu[i].password);
				count--;
				if (count) printf("\n");
			}
		}
	}
	
	return 0;
}

bool transfer(char* str, int len) {
	bool flag = false;
	for (int j = 0; j < len; j++) {
		if (str[j] == '1') {
			str[j] = '@';
			flag = true;
		}
		else if (str[j] == '0') {
			str[j] = '%';
			flag = true;
		}
		else if (str[j] == 'l') {
			str[j] = 'L';
			flag = true;
		}
		else if (str[j] == 'O') {
			str[j] = 'o';
			flag = true;
		}
	}
	return flag;
}