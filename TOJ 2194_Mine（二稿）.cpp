#include <iostream>
#include <utility>
#include <queue>
#include <cstdio>

#define MAX 105
#define INF 10000
using namespace std;

//���������������--��ʹ���������Ӧ

typedef pair<int, int> P;
int map[MAX][MAX];
int N, M;
int sx,sy;
char output[MAX][MAX];
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int i, j, t, u;
int dx, dy;
int bfs();
queue<P> que;


int main()
{
	#ifdef LOCAL
	freopen("input_TOJ 2194_Mine.txt", "r", stdin);
	#endif
	while (scanf("%d %d", &N, &M), M != 0 && N != 0) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				map[i][j] = 0;
			}
		}
		//��ʼ��map��������Ϣ
		for (t=0; t < M; t++) {
			scanf("%d %d", &i, &j);
			i--, j--;
			map[i][j] = INF;
			for (dx = -1; dx < 2; dx++) {
				for (dy = -1; dy < 2; dy++) {
					if (0 <= i+dx && i+dx < N && 0 <= j+dy && j+dy < N )
						map[i+dx][j+dy]++;
				}
			}
		}
		//�ڵ�ͼ�ϱ�ע���׺͵��׸���������

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				output[i][j] = '.';
			}
		}
		//��ʼ�����

		scanf("%d %d", &sx, &sy);
		sx--, sy--;
		//�������

		que.push(P(sx, sy));
		output[sx][sy] = 0;
		//���������벿�ֺͶ��岿��

		if (map[sx][sy] >= INF) {
			printf("oops!\n\n");
			continue;
		}
		else {
			output[sx][sy] = map[sx][sy] + '0';
			bfs();
		}
		//�õ����

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%c", output[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		//��ӡ���
		while (que.size()) {
			que.pop();
		}
	}
	return 0;
}

int bfs()
{
//	while (que.size()) {
//		P p = que.front();
//		que.pop();
//		que.pop();
////		if (map[p.first][p.second] != 0) {
////			output[p.first][p.second] = map[p.first][p.second];
////			continue;
////		}
//		//�ж�ʲôʱ���ҵ��ˣ�then do something to make sure this program will end.
//
//		for (dx = -1; dx < 2; dx++) {
//			for (dy = -1; dy < 2; dy++) {
//				int nx = p.first + dx, ny = p.second + dy;
//				if (0 <= nx && nx < N && 0 <= ny && ny < N && map[nx][ny] == 0 && output[nx][ny] == '.') {
//					output[nx][ny] = map[nx][ny] + '0';
//					que.push(P(nx, ny));
//				}
//				else if (0 <= nx && nx < N && 0 <= ny && ny < N && map[nx][ny] != 0 && output[nx][ny] == '.') {
//					output[nx][ny] = map[nx][ny] + '0';
//				}
//			}
//		}
//		//
//	}
//	return 0;
}


//�������3B3��3A3��ô���� 
