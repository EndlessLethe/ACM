#include <stdio.h>
#include<string.h>

int a[15], b[15], c[15];
int how_many[1000];
//好气，这个程序并不能实现求全部清醒的时刻 
int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典4-2_Extraordinary Tired Students && UVa12108.txt", "r", stdin);
	#endif

	int n, i, j, k;
	while (scanf("%d", &n) == 1 && n) {
		memset(how_many, 0, sizeof(how_many));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			j = 0;
			while (j < 1000) {
				for (k = 0; k < a[i]; k++) {
					if (j == 0) {
						if (c[i] > a[i]) {
							break;
						}
						else k = c[i]-1;
					}
					how_many[j++]++;
				}
				for (k = 0; k < b[i]; k++) {
					if (j == 0) {
						if (c[i] > a[i]) k = -a[i]+c[i]-1;
					}
					j++;
				}
			}
		}
		for (k = 0; k < 1000; k++) {
			printf("%6d ", how_many[k]);
		}
		printf("\n\n\n");
	}
	return 0;
}
