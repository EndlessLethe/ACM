#include <stdio.h>
#include<string.h>

#define M 10
#define N 9

void ini_map(void);
int is_win(void);
void print_map(void);

int piece_x[10], piece_y[10];
char piece[10];
int map[10][9];
int checking_map[10][9];

int GENERAL_MOVE[9][9] = {0, 1, 0, 1, 0, 0, 0, 0, 0,//第一个[]中表示了将所在的位置，[]指向可以走的位置 
						  1, 0, 1, 0, 1, 0, 0, 0, 0,
						  0, 1, 0, 0, 0, 1, 0, 0, 0,
					      1, 0, 0, 0, 1, 0, 1, 0, 0,
						  0, 1, 0, 1, 0, 1, 0, 1, 0,
						  0, 0, 1, 0, 1, 0, 0, 0, 1,
						  0, 0, 0, 1, 0, 0, 0, 1, 0,
						  0, 0, 0, 0, 1, 0, 1, 0, 1,
						  0, 0, 0, 0, 0, 1, 0, 1, 0,}

int main()
{
	#ifdef LOCAL
		freopen("input_算法竞赛入门经典4-1_Xiangqi && UVa1589.txt", "r", stdin);
	#endif
	
	int n, x, y, k;
	while ((scanf("%d%d%d", &n, &x, &y)) == 3 && n && x && y) {
//		printf("%d%d%d", n, x, y);
		for (k = 0; k < n; k++) {
			getchar();
			piece[k] = getchar();
			scanf("%d%d", &piece_x[k], &piece_y[k]);
		}
		
		ini_map();
		set_position(x, y);
		if (is_win) printf("YES"); 
		else printf("NO"); 
	}
	return 0;
}


int is_win(void) {
	for (i = 0, k = 0; i < 3; i++) {
		for (j = 3; j < 6; j++) {
			checking_map[i][j] = GENERAL_MOVE[(gx-1) * 3 + (gy-4)][k++];
		}
	}
	check_general();
	check_chariot();
	check_cannon();
	check_horse();
}

void ini_map(void) {
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}

void print_map()
{
	printf("\n");
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%6d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//打印结果
}

void set_position(int gx, int gy) {
	int i, j, k;
	for (k = 0; piece[k] == 'G' || piece[k] == 'R' || piece[k] == 'C' || piece[k] == 'H'; k++) {
		if (map[piece_x[k]-1][piece_y[k]-1] != 0) {
			printf("error");
		}
		else if (piece[k] == 'G') {
			map[piece_x[k]-1][piece_y[k]-1] = 'G' - 'A';
		}
		else if (piece[k] == 'R') {
			map[piece_x[k]-1][piece_y[k]-1] = 'R' - 'A';
		}
		else if (piece[k] == 'C') {
			map[piece_x[k]-1][piece_y[k]-1] = 'C' - 'A';
		}
		else if (piece[k] == 'H') {
			map[piece_x[k]-1][piece_y[k]-1] = 'H' - 'A';
		}
	}
}
