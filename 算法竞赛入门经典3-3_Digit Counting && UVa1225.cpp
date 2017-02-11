#include <stdio.h>
#include <ctype.h>
int each_num[10000+10][10];
int ans[10000+10][10];

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-3_Digit Counting && UVa1225.txt", "r", stdin);
	#endif
	int n, i, j, temp, input;
	for (j = 0; j < 10000+10; j++) {
		temp = j;
		while (temp > 0) {
			each_num[j][temp % 10]++;
			temp /= 10;
		}
	}
	
	for (i = 0; i < 10; i++) {
		ans[0][i] = each_num[0][i];
	}
	
	for (j = 1; j < 10000+10; j++) {
		for (i = 0; i < 10; i++) {
			ans[j][i] = each_num[j][i] + ans[j-1][i];
		}
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &input);
		for (j = 0; j < 9; j++) {
			printf("%d ", ans[input][j]);
		}
		printf("%d\n", ans[input][9]);
	}
	return 0;
}
