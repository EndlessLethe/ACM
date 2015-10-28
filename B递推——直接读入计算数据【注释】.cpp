#include <bits/stdc++.h>

#define MAX ******
//看题目的范围，这种没有提供行数（测试次数）的题目不会有太大的数组 

int f(int a, int* val);

int main()
{
	int n = 0, i = 0, k = 0;
	scanf("%d",&n);
	int res[MAX], val[MAX];//res储存结果，val是计算过程的数据 
	while (n != ****) {
		i = 0;
		res[i++] = f(n, val);
		//所有的细节都交给函数f来实现，只输出结果 
		scanf("%d",&n);
	}

	for (k = 0; k < i; k++) {	
		printf("%d\n", res[k]);	
	}
	//读了多少个数就输出多少个数 
}

int f(int a, int* val) {
	if (val[a-1]){
	//数组从0开始计算 
		;
	}
	//如果已经计算就直接输出 
	if else (a < ***) {
		val[a-1] = 1;
		//必须使循环能够终止，而此时则走出循环 
		//前几项特殊的 
	}
	else {	
		//这里填递推的公式 
	}
	return val[a-1];
}
