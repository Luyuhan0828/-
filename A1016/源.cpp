#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct {
	char name[24];
	int MM, dd, HH, mm;
	bool isOnline;
}user_info;
int price[24];
bool cmp(user_info a, user_info b) {
	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else if (a.MM != b.MM) return a.MM < b.MM;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.HH != b.HH) return a.HH < b.HH;
	else  return a.mm < b.mm;
}

float pay(user_info a, user_info b) {
	float fee=0;
	while (!(a.dd == b.dd && a.HH == b.HH && a.mm == b.mm)) {
		if (a.dd == b.dd && a.HH == b.HH) {
			fee += (b.mm - a.mm) * price[a.HH];
			break;
		}
		else if (a.dd == b.dd&&a.HH != b.HH) {
			fee += (float)(60 - a.mm) * price[a.HH];
			a.HH++;
			a.mm = 0;
		}
		else if (a.dd != b.dd) {
			fee += (60 - a.mm) * price[a.HH] ;
			a.mm = 0;
			a.HH++;
			if (a.HH == 24) {
				a.HH = 0;
				a.dd++;
			}
		}
	}
	return fee;
}
int main() {

	user_info rec[1010],temp;
	int N;
	for (int i = 0; i < 24; i++) {
		scanf("%d", &price[i]);
	}
	scanf("%d", &N);
	char status[10];
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d:%d%s", rec[i].name, &rec[i].MM, &rec[i].dd, &rec[i].HH, &rec[i].mm, status);
		if (!strcmp(status, "on-line")) {
			rec[i].isOnline=true;
		}
		else rec[i].isOnline = false;
	}
	sort(rec,&rec[N],cmp);
	int flag = 0, p=0, next=0, imp=0, cnt;
	float fee = 0, total = 0;
//	printf("%s %02d\n", rec[0].name, rec[0].MM);
/*	if (rec[0].isOnline) {
		flag = 1;
		temp=rec[0];
	}*/
	while (next < N) {
		imp = p;
		cnt = 0;
		total = 0;
		flag = 0;
		while (!strcmp(rec[p].name, rec[next].name)) {
			if (rec[next].isOnline == true && flag == 0 || rec[next].isOnline==true && flag == 2) {
				flag = 1;
			}
			else if (rec[next].isOnline == false && flag == 1) {
				flag = 2;
				cnt++;
			}
			next++;
		}
		/*		if (strcmp(rec[imp].name, rec[imp - 1].name)) {
					printf("Total amount: $%.2f\n%s %'02d\n", total / 100.0, rec[imp].name, rec[imp].MM);
					flag = 0;
					total = 0;
				}*/
		flag = 0;
		if(cnt) printf("%s %02d\n", rec[imp].name, rec[imp].MM);
		while (cnt) {
			if (flag == 0 && rec[imp].isOnline == false) {
				imp++;
				continue;
			}
			else if (flag == 0 && rec[imp].isOnline == true) {
				flag = 1;
				temp = rec[imp];
			}
			else if (flag == 1 && rec[imp].isOnline == true) {
				temp = rec[imp];
				imp++;
				continue;
			}
			else if (flag == 1 && rec[imp].isOnline == false) {
				flag = 0;
				fee = pay(temp, rec[imp]);
				total += fee;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp.dd, temp.HH, temp.mm, rec[imp].dd, rec[imp].HH, rec[imp].mm, rec[imp].dd * 24 * 60 + rec[imp].HH * 60 + rec[imp].mm - (temp.dd * 24 * 60 + temp.HH * 60 + temp.mm), fee / 100.0);
				cnt--;
			}
			imp++;
		}
		if(total) printf("Total amount: $%.2f\n", total / 100.0);
		p = next;
	}

	return 0;
}
