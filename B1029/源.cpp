#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
bool HashTable[128] = { false };
char LowerToUpper(char a)
{
	return a - 'a' + 'A';
}
int main() {
	char str1[80], str2[80];
	int integer[100];
	scanf("%s", str1);
	scanf("%s", str2);
	int p1 = 0, p2 = 0;
	char c1, c2;
	while (str1[p1]!='\0') {
		if (str1[p1] >= 'a'&&str1[p1]<='z') {
			c1 = LowerToUpper(str1[p1]);
		}
		else {
			c1 = str1[p1];
		}
		if (str2[p2] >= 'a'&&str2[p2]<='z') {
			c2 = LowerToUpper(str2[p2]);
		}
		else {
			c2 = str2[p2];
		}
		if (c1 != c2&&HashTable[c1]==false) {
			printf("%c", c1);
			HashTable[c1] = true;
			p1++;
		}
		else if(c1==c2){
			p1++;
			p2++;
		}
		else if (c1 != c2 && HashTable[c1] == true) {
			p1++;
		}
	}
	return 0;
}