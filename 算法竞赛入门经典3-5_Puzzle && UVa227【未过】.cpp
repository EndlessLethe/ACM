#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char input[5][5];
char command[100];


//题目上第二个询问没有空格，是PQRS直接换行，然而测试的时候是有空格的Orz
//所以我写的要改回去。。。 
int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典3-5_Puzzle && UVa227.txt", "r", stdin);
	#endif
	char ch;
	int i, j, k, count= 0, x, y, error;
	
	ch = getchar();
	ungetc(ch, stdin);
	while (ch != 'Z') {
		error = 0;
		count++;
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				ch = getchar();
				if (ch == '\n') ch = ' ';
				input[i][j] = ch;
				if (ch == ' ') {
					x = i;
					y = j;
				}
			}
			if (input[i][j-1] == ' ') {
				ungetc(ch, stdin);
			}
			ch = getchar();
		}
		for (k = 0; (ch = getchar()) != '0'; k++) {
			if (ch == '\n') {
				k--;
				continue;
			}
			command[k] = ch;
		}
		command[k] = '\0';
		
		for (k = 0; command[k] != '\0'; k++) {
			if (command[k] == 'A') {
				if (x-1 >= 0) {
					input[x][y] = input[x-1][y];
					input[x-1][y] = ' ';
					x = x-1;
				}
				else {
					error = 1;
					break;
				}
			}
			if (command[k] == 'R') {
				if (y+1 <= 4) {
					input[x][y] = input[x][y+1];
					input[x][y+1] = ' ';
					y = y+1;
				}
				else {
					error = 1;
					break;
				}
			}
			if (command[k] == 'B') {
				if (x+1 <= 4) {
					input[x][y] = input[x+1][y];
					input[x+1][y] = ' ';
					x = x+1;
				}
				else {
					error = 1;
					break;
				}
			}
			if (command[k] == 'L') {
				if (y-1 >= 0) {
					input[x][y] = input[x][y-1];
					input[x][y-1] = ' ';
					y = y-1;
				}
				else {
					error = 1;
					break;
				}
			}
		}
		
		printf("Puzzle #%d:\n", count);
		if (error == 0) {
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 5; j++) {
					printf("%c", input[i][j]);
					if (j < 4) printf(" ");
					if (j == 4 ) printf("\n");
				}
			}
		}
		else {
			printf("This puzzle has no final configuration.\n");
		}
		ch = getchar();
		ch = getchar();
		if (ch != 'Z') printf("\n");
		ungetc(ch, stdin);
	} 
	return 0;
}
