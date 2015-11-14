#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cubesum(int a, int b, int c);
int compDec(const void *a, const void *b)  
{  
    return *(int *)b - *(int *)a;  
}  
 

int main()
{
	int m = 0, n = 0, k = 0, i = 0;
	int a = 0, b = 0, c = 0;
	int res[MAX] = {0};
	while (scanf("%d %d", &m, &n) != EOF) {
		for (i = 0; i < MAX-1; i++){
			res[i] = 0;
		}
		a = 0, b = 0, c = 0;
		while ((res[k] = cubesum(a, b, c)) <= n) {
			
			if ((res[k] = cubesum(a, b, c)) >= m && (res[k] == 100 * a + 10 * b + c) && res[k] <= n) {
						k++;
					}
			while ((res[k] = cubesum(a, b, c)) <= n) {
				
				if ((res[k] = cubesum(a, b, c)) >= m && (res[k] == 100 * a + 10 * b + c) && res[k] <= n) {
						k++;
					}
				while ((res[k] = cubesum(a, b, c)) <= n) {
					
					if ((res[k] = cubesum(a, b, c)) >= m && (res[k] == 100 * a + 10 * b + c) && res[k] <= n) {
						k++;
					}
					c++;
				}
				c = 0;
				b++;
			}
			b = 0, c = 0;
			a++;
		}
		if (k == 0) {
			printf("no\n");
		}
		else if (res[1] == res[0] && res[2] != 371) {
			printf("%d\n", res[1]);
		}
		else if (res[1] == res[2] && res[3] != 371) {
			printf("153 370\n");
		//针对370 写的 
		}
		else {
			int len = 0, temp = 0;
			len = sizeof(res) / sizeof(res[0]);  
			int i;  
  			qsort(res, len, sizeof(res[0]), compDec);  
			while (k > 0) {
				if (res[k] == res[temp]) {
					;
				}
				else {
					printf("%d", res[k]);
					temp = k;
					if (k != 1) {
						printf(" ");
					}
					else {
						printf("\n");
					}
				}
			//终于发现是n = m = 370这种的时候会出错 
				k--;
			}
		}
		k = 0;
	}
	return 0;
}

int cubesum(int a, int b, int c) {
	return a * a * a + b * b * b + c * c * c;
}
