#include <bits/stdc++.h>

#define MAX 1000000
 
long long int f(int a, long long int* val);

int main()
{
	int a = 0, b = 0, i = 0, k = 0;//计算的次数，都是很小的数 
	long long int res = 0, val[MAX] = {0};
	scanf("%d %d", &a, &b);
	res = f(a, val) % b;//调用函数得到值 
	printf("%lld", res);
}
//Runtime error on test 6
//说明需要用分治的思想 


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
