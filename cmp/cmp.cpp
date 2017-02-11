#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#define LL long long
using namespace::std;


int main()
{
	for (int i = 0; i < 1000000; i++) // 对拍 1000 次
	{
		FILE *fp = fopen("in.txt", "w");
		/* 向 fp 中写入输入数据 */
		fclose(fp);
		system("std"), system("mine"); // 分别运行标程和被拍的程序
		if (system("fc std.out mine.out")) // 比较文件
		{
			printf("出错啦！\n");
			getchar();
		}
	}
	return 0;
}
