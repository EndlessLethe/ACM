#include <bits/stdc++.h>

int f91(int a);

int main()
{
	int a, res;
	while (scanf("%d",&a))
	{
		if (a != 0)
		{
			res = f91(a);
			printf("f91(%d) = %d\n", a, res);
		}
		else 
		{
			return 0;
		}
	}
}

int f91(int a)
{
	int b;
	if (a <= 100)
	{
		b = f91(f91(a+11));
	}
	else
	{
		b = a - 10;
	}
	
	return b;
}
