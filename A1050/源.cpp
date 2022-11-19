#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
using namespace std;
const int maxn = 10010;
bool HashTable[128];
int main() {
	memset(HashTable, false, sizeof(HashTable));
	char str1[maxn];
	int cnt = 0;
	while (true) {
		str1[cnt] = getchar();
		if (str1[cnt] == '\n') break;
		cnt++;
	}
	char temp;
	while (true) {
		temp = getchar();
		if (temp == '\n') break;
		HashTable[temp] = true;
	}
	int len = strlen(str1);
	for (int i = 0; i < cnt; i++) {
		if (HashTable[str1[i]] == false) printf("%c", str1[i]);
	}
	return 0;
}