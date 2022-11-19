#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main() {
	char res[3] = { 'W','T','L' };
	float odd[3][3] = { 0 };
	float max[3] = { 0 };
	int rec[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%f", &odd[i][j]);
			if (odd[i][j] > max[i]) {
				max[i] = odd[i][j];
				rec[i] = j;
			}
		}
	}
	float profit = (max[0] * max[1] * max[2] * 0.65 - 1) * 2;
	printf("%c %c %c %.2f", res[rec[0]], res[rec[1]], res[rec[2]], profit);
	return 0;
}