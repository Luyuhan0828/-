#include<iostream>
#include<string>
using namespace std;
#define N 100000

int main(void)
{
	string s1, s2;
	getline(cin, s1);//未说明第一行是否为空 
	getline(cin, s2);
	int len1 = s1.length();
	int len2 = s2.length();
	int flag = 0, flag1 = 0, flag2 = 0;
	for (int i = 0; i < len2; i++)
	{
		flag = 0;
		for (int j = 0; j < len1; j++)
		{
			if (s1[i] == '+')
			{
				flag2 = 1;
			}
			//条件不够完整：测试点4会报错 
	//			if(s2[i]==s1[j]||((s1[j]+('a'-'A')==s2[i])&&(s2[i]>='A'&&s2[i]<='Z'))
	//			||(flag2==1&&(s2[i]>='A'&&s2[i]<='Z')))
			if (s2[i] == s1[j] || ((s1[j] == s2[i] + 'A' - 'a') && (s2[i] >= 'a' && s2[i] <= 'z'))
				|| (flag2 == 1 && (s2[i] >= 'A' && s2[i] <= 'Z')))
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << s2[i];
		}
	}
}