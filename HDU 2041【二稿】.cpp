#include <bits/stdc++.h>

int f(int a, int* val);

int main()
{
	int n, i;
	scanf("%d", &n);
	//���롰��Ҫ���������ĸ��� 
	int array[n];
	//����ÿ��Ĵ� 
	
	for (i = 0; i < n; i++)
	{
		int a = 0;
		scanf("%d", &a);
/*��������� */
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
