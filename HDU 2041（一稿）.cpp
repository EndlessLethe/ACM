#include <bits/stdc++.h>

//思考错了，代码完全不能改了。。。


int main()
{
	int n, i, c;
	scanf("%d", &n);
	int array[n];
	for (i = 0; i < n; i++)
	{
		int b = 0;
		int res = 0;
		scanf("%d", &b);
		c = b - 1;
		switch (c % 2)
		{
		case 1:
			res++;
			/*FALL THRU*/
		case 0:
			if (c == 1)
			{
				array[i] = res;;
			}
			else
			{
				res += pow(2, c/2);
				array[i] = res;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", array[i]);	
	}
}
