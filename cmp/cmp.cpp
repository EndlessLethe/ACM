#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#define LL long long
using namespace::std;


int main()
{
	for (int i = 0; i < 1000000; i++) // ���� 1000 ��
	{
		FILE *fp = fopen("in.txt", "w");
		/* �� fp ��д���������� */
		fclose(fp);
		system("std"), system("mine"); // �ֱ����б�̺ͱ��ĵĳ���
		if (system("fc std.out mine.out")) // �Ƚ��ļ�
		{
			printf("��������\n");
			getchar();
		}
	}
	return 0;
}
