#include <stdio.h>
char input[100];

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-1_Score && UVa1585.txt", "r", stdin);
	#endif
	int n, i, j, flag, score, x_number, o_number;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", input);
		flag = 0, score = 0, x_number = 0, o_number = 0;
		for (j = 0; input[j] != '\0'; j++) {
			if (input[j] == 'X') flag = 1;
			else if (input[j] == 'O') flag = 0;
			if (flag == 0) {
				o_number++;
				score += o_number;
//				x_number = 0;
			}
			else if (flag == 1) {
//				x_number = 0;
//				score += x_number;
				o_number = 0;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
