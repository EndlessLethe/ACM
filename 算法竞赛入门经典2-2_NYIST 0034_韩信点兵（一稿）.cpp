#include <stdio.h>
#include <stdlib.h>


int compDec(const void *a, const void *b)  
{  
    return *(int *)b - *(int *)a;  
}  
 

int main()
{
	int m = 0, n = 0, l = 0, k = 0, i = 0;
	int a = 0, b = 0;
	while (scanf("%d%d%d", &m, &n, &l) != EOF) {

		a = 1, b = 0;
		i++;
		while ( 10 * a + b <= 100) {
			if ((10 * a + b) % 3 == m && (10 * a + b) % 5 == n && (10 * a + b) % 7 ==l) {
				k++;
				printf("%d\n",10 * a + b);
//				printf("Case %d: %d\n", i, 10 * a + b);
//				OJ要求输出的格式和书上不一样 
				goto end;
			}
			while (10 * a + b <= 100 && b < 10) {
				if ((10 * a + b) % 3 == m && (10 * a + b) % 5 == n && (10 * a + b) % 7 ==l) {
					k++;
					printf("%d\n", 10 * a + b);
//					printf("Case %d: %d\n", i, 10 * a + b);
					goto end;
				}
				b++;
			}
			b = 0;
			a++;
		}
		end:
		if (k == 0) {
			printf("No answer\n");
//			printf("Case %d: No answer\n", i);
		}
	}
	return 0;
}
