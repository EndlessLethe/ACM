#include <bits/stdc++.h>

#define MAX 50

long long int f(int a, long long int* val);

int main()
{
	int n, i;
	scanf("%d", &n);//读入 需要读的数字对数 
	long long int res[n] = {0}, val[MAX] = {0};//定义 并初始化 result 和 函数过程的 value 
	for (i = 0; i < n; i++){
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		a = b - a + 1;
		res[i] = f(a, val);//利用封装的函数计算出结果，并将结果交给 res数组保存 
	}
	for (i = 0; i < n; i++){	
		printf("%lld\n", res[i]);	//输出 
	}
}

long long int f(int a, long long int* val)
{
	if (val[a-1]){
		;
	}
	else if (a == 1 || a == 2) {
		val[a-1] = 1;
	}
	else{
		val[a-1] = f(a-1, val) + f(a-2, val);
	}
	return val[a-1];
}
