#include <bits/stdc++.h>

long long int f(long long int a, long long int* val);

int main()
{
	long long int n, i;
	scanf("%lld", &n);
	//读入“需要读的数”的个数 
	long long int array[n];
	//储存每组的答案 
	
	for (i = 0; i < n; i++)
	{
		long long int a = 0, b = 0;
		scanf("%lld %lld", &a, &b);
/*读入阶梯数 */
		a = b - a + 1;
		if (a == 0)
		{
			array[i] = 0;
		}
		else
		{
			long long int val[a] = {0};
			array[i] = f(a, val);
		}

	}
	
	for (i = 0; i < n; i++)
	{	
		printf("%lld\n", array[i]);	
	}
}

long long int f(long long int a, long long int* val)
{
	if (val[a-1])
	{
		return val[a-1];
	}
	else if (a == 1 || a == 2) 
	{
		val[a-1] = 1;
		return 1;
	}
	else
	{
		val[a-1] = f(a-1, val) + f(a-2, val);
		return val[a-1];
	}

}
