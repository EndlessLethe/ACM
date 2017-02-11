#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char input[50][1000+5];
int result[50];


int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-7_DNA Consensus String && UVa1368.txt", "r", stdin);
	#endif
	
	int puzzle, m, n, i, j, k, diff;
	
	scanf("%d", &puzzle);
	while (puzzle--) {
		scanf("%d%d", &m, &n);
		for (i = 0; i < m; i++) {
			scanf("%s", &input[i]);
		}
		
		for (i = 0; i < m; i++) {//所在 
			diff = 0;
			for (k = 0; k < m; k++) {//比较 
				for (j = 0; j < n; j++) {
					if (input[i][j] != input[k][j]) diff++;
				}
			}
			result[i] = diff;
		}
		
		
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%c ", input[i][j]);
			}
			printf("\n");
			printf("\ndiff = %d\n", result[i]);
		}
		printf("\n");
		
	}
	return 0;
}
