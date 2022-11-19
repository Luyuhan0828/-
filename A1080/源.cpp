#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int max_stu = 40010;
const int max_school = 101;
struct student {
	int GE, GI, sum;
	int choice[6];
	int id;
	int rank;
}stu[max_stu];
struct university {
	int quota;
	int admitted;
	int admitted_stu[max_stu];
	int last_stu;
}uni[max_school];
bool cmp(student a, student b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	else return a.GE > b.GE;
}
bool cmpid(int a, int b) {
	return stu[a].id < stu[b].id;
}
int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d", &uni[i].quota);
		uni[i].admitted = 0;
		uni[i].last_stu = -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &stu[i].GE, &stu[i].GI);
		for (int j = 0; j < K; j++){
			scanf("%d", &stu[i].choice[j]);
		}
		stu[i].sum = stu[i].GE + stu[i].GI;
		stu[i].id = i;
		
	}
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++) {
		if (i>0&&stu[i-1].sum == stu[i].sum && stu[i-1].GE == stu[i].GE) {
			stu[i].rank = stu[i - 1].rank;
		}
		else {
			stu[i].rank = i;
		}
	}

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) {
			int choice = stu[i].choice[j];
			int num = uni[choice].admitted;
			int last = uni[choice].last_stu;
			if (num < uni[choice].quota|| (last != -1 && stu[i].rank == stu[last].rank)) {
				uni[choice].admitted_stu[num] =i;
				uni[choice].admitted++;
				uni[choice].last_stu = i;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		if (uni[i].admitted>0) {
			sort(uni[i].admitted_stu, uni[i].admitted_stu + uni[i].admitted,cmpid);
			for (int j = 0; j < uni[i].admitted; j++) {
				printf("%d", stu[uni[i].admitted_stu[j]].id);
				if (j != uni[i].admitted - 1) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}