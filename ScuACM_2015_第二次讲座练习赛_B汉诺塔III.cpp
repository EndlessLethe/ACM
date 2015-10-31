#include <bits/stdc++.h>

#define MAX1 35
#define MAX2 35 
 
long long int f(int a, long long int* val);

int main()
{
	int n = 0, i = 0, k = 0;//计算的次数，都是很小的数 
	long long int res[MAX1] = {0}, val[MAX2] = {0};//res记录结果，val记录f函数的值（中间量） ，需要储存很大的数 
	while (scanf("%d",&n) != EOF) {
		res[i++] = f(n, val);//调用函数得到值 
	}

	for (k = 0; k < i; k++) {	
		printf("%I64d\n", res[k]);//输出结果	
	}
}

long long int f(int a, long long int* val) {
	if (val[a-1]){
		;
	}
	else if (a < 2) {
		val[a-1] = 2;
	}
	else {
		val[a-1] = 3*f(a-1, val) + 2;
	}
	return val[a-1];
}
