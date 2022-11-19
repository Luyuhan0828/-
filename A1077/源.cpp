//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <cstring>
//using namespace std;
//int main() {
//	int N;
//	char str[256][260];
//	scanf("%d", &N);
//	getchar();
//	int minlen = 260;
//	for (int i = 0; i < N; i++) {
//		gets_s(str[i]);
//		_strrev(str[i]);
//		if (strlen(str[i]) < minlen) minlen = strlen(str[i]);
//	}
//	int i, j, pos, flag=0;
//	char temp;
//	for (i = 0; i < minlen; i++) {
//		temp = str[0][i];
//		pos = i;
//		for (j = 0; j < N; j++) {
//			if (temp != str[j][i]) {
//				flag = 1;
//				pos--;
//				break;
//			}
//		}
//		if (flag) break;
//	}
//	for (i = pos; i >= 0; i--) {
//		printf("%c", str[0][i]);
//	}
//	if (pos < 0) printf("nai");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int N;
	int i, j, pos, flag = 0, len;
	char temp;
	char str[256][260];
	scanf("%d", &N);
	getchar();
	int minlen = 260;
	for (i = 0; i < N; i++) {
		j = 0;
		scanf("%c", &str[i][j]);
		j++;
		while (str[i][j-1] != '\n') {
			scanf("%c", &str[i][j]);
			j++;
		}
		len = strlen(str[i]);
		for (int k = 0; k < len; k++) {
			temp = str[i][k];
			str[i][k] = str[i][len - k - 1];
			str[i][len - 1 - k] = str[i][k];
		}
		if (strlen(str[i]) < minlen) minlen = strlen(str[i]);
	}
	for (i = 0; i < minlen; i++) {
		temp = str[0][i];
		pos = i;
		for (j = 0; j < N; j++) {
			if (temp != str[j][i]) {
				flag = 1;
				pos--;
				break;
			}
		}
		if (flag) break;
	}
	for (i = pos; i >= 0; i--) {
		printf("%c", str[0][i]);
	}
	if (pos < 0) printf("nai");
	return 0;
}