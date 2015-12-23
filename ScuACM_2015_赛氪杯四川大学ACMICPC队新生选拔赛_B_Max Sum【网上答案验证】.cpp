#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
 
int main()
{
	int j, rec = 1;
	scanf("%d", &j);
	while (j != 0)
	{
		j--;
		int i, n, num, line = 0;
		int max = 1<<31, start = 1, end = 1, temp = 1;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &num);
			line += num;
			if (line > max) {
				max = line;
				start = temp;
				end = i;
			}
			
			if (line < 0) { 
				line = 0;
				temp = i + 1;
			}
		}
		
		printf("Case %d:\n%d %d %d\n", rec++, max, start, end);
		if (j != 0) printf("\n");
	}
	return 0;
}
