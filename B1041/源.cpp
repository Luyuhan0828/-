#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

struct stu{
	char id[16];
	int test;
}stu_info[1001];


int main() {
	int N, M, pre , exam, req;
	scanf("%d", &N);
	char temp[17];
	for (int i = 0; i < N; i++) {
		scanf("%s %d%d", temp, &pre, &exam);
		stu_info[pre].test = exam;
		for (int j = 0; j < 16; j++) {
			stu_info[pre].id[j] = temp[j];
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &req);
		for (int j = 0; j < 16; j++) {
			printf("%c", stu_info[req].id[j]);
		}
		printf(" %d", stu_info[req].test);
		if (i < M - 1)  printf("\n");
	}
	return 0;
}