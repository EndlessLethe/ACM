#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define INF 200

char input[11][11];
int num[11][11] = {0};
int numtwo[11][11] = {0};


int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-6_Crossword Answers && UVa232.txt", "r", stdin);
	#endif
	
	char ch;
	int i, j, k, count= 0, x, y, r, c, eligible;
	while (scanf("%d%d", &r, &c) == 2) {
		count++;
		for (i = 0; i < r; i++) {
			scanf("%s", &input[i]);
		}
		eligible = 1;
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (i == 0 || j == 0 || input[i-1][j] == '*' || input[i][j-1] == '*') {
					if (input[i][j] != '*') {
						num[i][j] = eligible;
						numtwo[i][j] = eligible;
						eligible++;
					}
				}
			}
		}
		printf("puzzle #%d:\n", count);
		printf("Across\n");
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (num[i][j] < INF && num[i][j] != 0) {
					printf("%3d.", num[i][j]);
					for (k = j; k < c; k++) {
						if (input[i][k] != '*') {
							printf("%c", input[i][k]);
							num[i][k] = INF;
						}
						else break;
					}
					printf("\n");
				}
			}
		}
		
		printf("Down\n");
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (numtwo[i][j] < INF && numtwo[i][j] != 0) {
					printf("%3d.", numtwo[i][j]);
					for (k = i; k < r; k++) {
						if (input[k][j] != '*') {
							printf("%c", input[k][j]);
							numtwo[k][j] = INF;
						}
						else break;
					}
					printf("\n");
				}
			}
		}
		ch = getchar();
		ch = getchar();
		if (ch != '0') printf("\n");
		ungetc(ch, stdin);
//		for (i = 0; i < r; i++) {
//			for (j = 0; j < c; j++) {
//				printf("%4d ", num[i][j]);
//			}
//			printf("\n");
//		}
	} 
	return 0;
}
