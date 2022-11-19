#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
//char digit[10][10] = { "ling","yi","er","san","si",
//					"wu","liu","qi","ba","jiu" };
//char scale[5][10] = { "Yi","Wan","Qian","Bai","Shi" };
//int main() {
//	char input[10];
//	scanf("%s", input);
//	int len = strlen(input);
//	int left = 0, right = len - 1;
//	if (input[left] == '-') {
//		printf("Fu ");
//		left++;
//	}
//	int level = (right - left) / 4;
//	bool printzero ;
//	bool isPrint;
//	while (left + 4 <= right) {
//		right -= 4;
//	}
//	while (right < len) {
//		printzero = false;
//		isPrint = false;
//		while (left <= right) {
//			if (digit[input[left] - '0'] != "zero") {
//
//			}
//
//			if (digit[input[left] - '0'] == "zero") {
//				printzero = true;
//			}
//			else {
//				printf("%s", digit[input[left] - '0']);
//				isPrint = true;
//				if (level > 0 || right != left) printf(" ");
//				if (right - left == 3 && level > 0) printf("%s ", scale[2]);
//				else if (right - left == 2) printf("%s ", scale[3]);
//				else if (right - left == 1) printf("%s ", scale[4]);
//				else if (right - left == 0) {
//					if (isPrint) {
//						if (level == 2) {
//							printf("%s ", scale[0]);
//							level--;
//						}
//						else if (level == 1) {
//							printf("%s ", scale[1]);
//							level--;
//						}
//					}
//					else {
//						level--;
//					}
//				}
//			}
//			left++;
//		}
//		right += 4;
//	}
//	return 0;
//}
char num[10][10] = { "ling","yi","er","san","si",
					"wu","liu","qi","ba","jiu" };
char wei[5][5] = { "Shi","Bai","Qian","Wan","Yi" };
int main() {
	char str[15];
	scanf("%s", str);
	int len = strlen(str);
	int left = 0, right = len - 1;
	if (str[0] == '-') {
		printf("Fu");
		left++;
	}
	while (left + 4 <= right) {
		right -= 4;
	}
	while (left < len) {
		bool flag = false;
		bool isPrint = false;
		while (left <= right) {
			if ( left>0 && str[left] == '0') {
				flag = true;
			}
			else {
				if (flag == true) {
					printf(" ling");
					flag = false;
				}
				if (left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if (left != right) {
					printf(" %s", wei[right - left - 1]);
				}
			}
			left++;
		}
		if (isPrint == true && right != len - 1) {
			printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		}
		right += 4;
	}
	return 0;
}