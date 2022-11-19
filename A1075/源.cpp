#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
typedef struct {
	int id;
	int partial_score[7];
	int perfectlySolved;
	bool flag;
	int rank;
	int total;
}stu_info;
stu_info stu[maxn];
int full_score[7];
bool cmp(stu_info a, stu_info b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.perfectlySolved != b.perfectlySolved) return a.perfectlySolved > b.perfectlySolved;
	else return a.id < b.id;
}
void init(stu_info* a){
	for (int i = 1; i < maxn; i++) {
		a[i].id = i;
		a[i].flag = false;
		a[i].perfectlySolved = 0;
		a[i].total = 0;
		memset(a[i].partial_score, -1, sizeof(a[i].partial_score));
	}
}
int main() {
	int N, K, M, cnt, precnt=0;
	int user_id, problem_id, partial_score_obtained;
	scanf("%d%d%d", &N, &K, &M);
	init(stu);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &full_score[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &user_id, &problem_id, &partial_score_obtained);
		if (partial_score_obtained > stu[user_id].partial_score[problem_id]) {
			if (partial_score_obtained == full_score[problem_id]) stu[user_id].perfectlySolved++;
			stu[user_id].flag = true;
			stu[user_id].partial_score[problem_id] = partial_score_obtained;
		}
		else if (partial_score_obtained == -1 && stu[user_id].partial_score[problem_id] == -1) {
			stu[user_id].partial_score[problem_id] = 0;
		}
	}
	int sum;
	for (int i = 1; i < maxn; i++) {
		sum = 0;
		if (stu[i].flag) {
			for (int j = 1; j <= K; j++) {
				if (stu[i].partial_score[j] > 0) sum += stu[i].partial_score[j];
			}
			stu[i].total = sum;
			precnt++;
		}
	}
	sort(stu+1, stu + maxn, cmp);
	cnt = 0;
	for (int i = 1; i < maxn; i++) {
		if (stu[i].flag == true) {
			cnt++;
			if (stu[i].total == stu[i - 1].total) {
				stu[i].rank = stu[i - 1].rank;
			}
			else {
				stu[i].rank = cnt;
			}
			printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
			for (int j = 1; j <= K; j++) {
				if (stu[i].partial_score[j] == -1) printf(" -");
				else printf(" %d", stu[i].partial_score[j]);
			}
			if(cnt<precnt) printf("\n");
		}
	}
	return 0;
}