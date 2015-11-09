#include <bits/stdc++.h>

int f(int a, int* val);

int main()
{
	int n, i;
	scanf("%d", &n);
	//读入“需要读的数”的个数 
	int array[n];
	//储存每组的答案 
	
	for (i = 0; i < n; i++)
	{
		int a = 0;
		scanf("%d", &a);
/*读入阶梯数 */
		if (a == 0)
		{
			array[i] = 0;
		}
		else
		{
			int val[a] = {0};
			array[i] = f(a, val);
		}

	}
	
	for (i = 0; i < n; i++)
	{	
		printf("%d\n", array[i]);	
	}
}

int f(int a, int* val)
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
