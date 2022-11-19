#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 80010;
struct car {
	char plate_number[10];
	int hh, mm, ss;
	bool status;  
}rec[maxn];
struct park {
	char plate_number[10];
	int start_time;
	int end_time;
	int total;
}valid[maxn];
int time_to_int(car a) {
	return a.hh * 3600 + a.mm * 60 + a.ss;
}
bool cmp_plate(car a, car b) {
	if (strcmp(a.plate_number, b.plate_number) != 0) return strcmp(a.plate_number, b.plate_number) < 0;
	else return time_to_int(a) < time_to_int(b);
}


bool cmp_total(park a, park b) {
	if (a.total != b.total) return a.total > b.total;
	else return strcmp(a.plate_number, b.plate_number) < 0 ? true : false;
}
bool judge(int qtime, park a) {
	if (qtime < a.end_time && qtime >= a.start_time) return true;
	else return false;
}
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	char str[4];
	for (int i = 0; i < N; i++) {
		scanf("%s%d:%d:%d%s", rec[i].plate_number, &rec[i].hh, &rec[i].mm, &rec[i].ss, str);
		if (strcmp(str, "in") == 0) rec[i].status = true;
		else rec[i].status = false;
	}
	sort(rec, rec + N, cmp_plate);
	int start , end = 0, present, flag, pos, cnt=0;
	while (end < N) {
		flag = 0;
		start = end;
		present = start;
		end++;
		while (0==strcmp(rec[end].plate_number, rec[end - 1].plate_number)||end==0) {
			end++;
		}
		while (present < end) {
			if (flag == 0 && rec[present].status) {
				flag = 1;
				pos = present;
			}
			else if (flag == 1 && rec[present].status == false) {
				flag = 0;
				strcpy(valid[cnt].plate_number , rec[present].plate_number);
				valid[cnt].end_time = rec[present].hh * 60 * 60 + rec[present].mm * 60 + rec[present].ss;
				valid[cnt].start_time = rec[pos].hh * 60 * 60 + rec[pos].mm * 60 + rec[pos].ss;
				valid[cnt].total = valid[cnt].end_time - valid[cnt].start_time;
				cnt++;
			}
			else if (flag == 1 && rec[present].status == true) {
				pos = present;
			}
			present++;
		}
	}
	int qhh, qmm, qss, qtime,qcnt;
	for (int i = 0; i < K; i++) {
		qcnt = 0;
		scanf("%d:%d:%d", &qhh, &qmm, &qss);
		qtime = qhh * 60 * 60 + qmm * 60 + qss;
		for (int j = 0; j < cnt; j++) {
			if (judge(qtime,valid[j])) {
				qcnt++;
			}
		}
		printf("%d\n", qcnt);
	}
	sort(valid, valid + cnt, cmp_total);
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (0 == strcmp(valid[j].plate_number, valid[i].plate_number)) valid[i].total += valid[j].total;
		}
	}
	sort(valid, valid + cnt, cmp_total);
	for (int i = 0; i < cnt && valid[i].total == valid[0].total; i++) {
		printf("%s ", valid[i].plate_number);
	}
	qss = valid[0].total;
	qhh = qss / 3600;
	qss %= 3600;
	qmm = qss / 60;
	qss %= 60;
	printf("%02d:%02d:%02d", qhh, qmm, qss);
	return 0;
}