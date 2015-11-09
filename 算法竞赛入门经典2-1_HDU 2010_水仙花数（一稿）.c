#include <stdio.h>

#define MAX 100

//心塞，发现又把题看错了。。。
//我以为水仙花数是三个立方数的和 T T 

int main()
{
	int m = 0, n = 0, k = 0;
	int a = 0, b = 0, c = 0;
	int res[MAX] = {0};
	while (scanf("%d %d", &m, &n) != EOF) {
		while ((res[k] = cubesum(a, b, c)) <= n) {
			a++;
			while ((res[k] = cubesum(a, b, c)) <= n) {
				b++;
				while ((res[k] = cubesum(a, b, c)) <= n) {
					c++;
					if ((res[k] = cubesum(a, b, c)) >= m && res[k] <= n) {
						k++;
					}
				}
			}
		}
	if (k == 0) {
		printf("no\n");
	}
	else {
		while (k > 0) {
			printf("%d ", res[k-1]);
			k--;
		}
		printf("\n");
	}
	k = 0;
	}

	return 0;
}

int cubesum(int a, int b, int c) {
	return a * a * a + b * b * b + c * c * c;
}
