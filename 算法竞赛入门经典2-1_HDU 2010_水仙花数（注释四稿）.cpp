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
	//本来想用记忆化搜索来加快速度，不用每次调计算 a * a * a + b * b * b + c * c * c。然而想错了。。。 
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
		//用的三重循环（我犯傻T T），不过应该要比用mod快一点 
		//以上做的事就是用循环找到那些数，并储存在结果result数组中 
		if (k == 0) {
			printf("no\n");
		}
		//如果没有，输出no 
		else {
			int len = 0, temp = 0;
			len = sizeof(res) / sizeof(res[0]);  
			int i;  
  			qsort(res, len, sizeof(res[0]), compDec); 
  			//用了快排。。。 
			while (k > 0) {
				if (res[k] == res[temp]) {
					;
				}
				//跳过重复的结果。。。 
				else {
					printf("%d", res[k]);
					temp = k;
					if (k != 1){
					printf(" ");
					}
					//如果不是末尾打印“ ” 
				}
				k--;

			}
			printf("\n");
			//这次循环后换行，等待下次输入 
		}
			k = 0;
	}
	return 0;
}

int cubesum(int a, int b, int c) {
	return a * a * a + b * b * b + c * c * c;
}
