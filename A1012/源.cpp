#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
typedef struct {
	int grade[4];
	int id;
	int rank[4];
}stu_info;
using namespace std;
int pos;
char cla[4] = { 'A','C','M','E' };
bool cmp(stu_info a, stu_info b) {
	return a.grade[pos] > b.grade[pos];
}
int main() {
	int N, M;
	stu_info stu[2010];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &stu[i].id,  &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2]+stu[i].grade[3];
	}
	for (pos = 0; pos < 4; pos++)
	{
		sort(stu, &stu[N], cmp);
		int r = 1;
		stu[0].rank[pos] = r;
		r++;
		for (int i = 1; i < N; i++) {
			if (stu[i - 1].grade[pos] == stu[i].grade[pos]) {
				stu[i].rank[pos] = stu[i - 1].rank[pos];
				r++;
			}
			else {
				stu[i].rank[pos] = r;
				r++;
			}
		}
	}
	int find, find_pos, best_rank;
	for (int i = 0; i < M; i++) {
		find_pos = -1;
		scanf("%d", &find);
		for (int j = 0; j < N; j++) {
			if (stu[j].id == find) {
				find_pos = j;
				break;
			}
		}
		if (find_pos == -1) {
			printf("N/A");
			if (i != M) printf("\n");
			continue;
		}
		best_rank = 0;
		for (int j = 1; j < 4; j++) {
			if (stu[find_pos].rank[j]<stu[find_pos].rank[best_rank]) best_rank = j;
		}
		printf("%d %c", stu[find_pos].rank[best_rank], cla[best_rank]);
		if (i != M) printf("\n");
	}
	return 0;
}