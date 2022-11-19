#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {
	int  de, cai;
	int level,total;
	char id[10];
}student;
bool cmp(student a, student b) {
	if (a.level != b.level) return a.level < b.level;
	else if (a.total != b.total) return a.total > b.total;
	else if (a.de != b.de) return a.de > b.de;
	else return strcmp(a.id, b.id) < 0;
}
bool cmp2(student a, student b) {
	return a.total > b.total;
}
bool cmp3(student a, student b) {
	return a.de > b.de;
}
bool cmp4(student a, student b) {
	return strcmp(a.id,b.id)>0;
}
bool judge(student* stu, int low, int high);
int main() {
	student stu[10001];
	int N, L, H, M=0;
	int tde, tcai;
	scanf("%d%d%d", &N, &L, &H);
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d", stu[i].id, &tde, &tcai);
		stu[i].de = tde;
		stu[i].cai = tcai;
		if(judge(&stu[i],L,H)) M++;
	}
	printf("%d", M);
	if (M) printf("\n");
	sort(stu, &stu[N], cmp);
	for (int i = 0; i < M; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}
	//int pos = 0,pre=0;
	//for (int i = 1; i < 5&& pos<M; i++) {
	//	while (stu[pos].level == i) pos++;
	//	sort(&stu[pre], &stu[pos], cmp);
	//	for (int j = pre; j < pos; j++) {
	//		printf("%s %d %d", stu[j].id, stu[j].de, stu[j].cai);
	//		if(j!=M-1) printf("\n");
	//	}
	//	pre = pos;
	//}

	return 0;
}

bool judge(student* stu, int low, int high) {
	bool flag;
	stu->total = stu->cai + stu->de;
	if (stu->de >= high && stu->cai >= high) {
		stu->level = 1;
		flag = true;
	}
	else if (stu->de >= high && stu->cai >= low && stu->cai < high) {
		stu->level = 2;
		flag = true;
	}
	else if (stu->de < high && stu->cai >= low && stu->cai < high && stu->de >= low &&
		stu->de >= stu->cai) {
		stu->level = 3;
		flag = true;
	}
	else if (stu->de >= low && stu->cai >= low) {
		stu->level = 4;
		flag = true;
	}
	else {
		stu->level = 5;
		flag = false;
	}
	return flag;
}