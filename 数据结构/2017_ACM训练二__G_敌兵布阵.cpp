//读入从1开始
//注意每次初始化b
//i~j区间求sum是sum(i)-sum(i-1)

#include <stdio.h>
#include <string.h>
const int MAX_N = 50100;

char input[20];
int N;
long long bit[MAX_N+1];

long long sum(int i) {//[1, i]
	long long s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, long long v) {
	while (i <= N) {
		bit[i] += v;//���Ը�Ϊ =
		i += i & -i;
	}
}

int main() {
	#ifdef LOCAL
		freopen("input_2017_ACMѵ����__G_�б�����.txt", "r", stdin);
	#endif
	int T, a, b, tem;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(bit, 0, sizeof(bit)); 
		printf("Case %d:\n", t);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &tem);
			add(i, tem);
		}
		while (scanf("%s", input) == 1) {
			if (input[0] == 'E') break;
			if (input[0] == 'A') {
				scanf("%d%d", &a, &b);
				add(a, b);
			}
			if (input[0] == 'S') {
				scanf("%d%d", &a, &b);
				add(a, -b);
			}
			if (input[0] == 'Q') { 
				scanf("%d%d", &a, &b);
				printf("%d\n", sum(b)-sum(a-1));
			}
		}
	}
	return 0;
}
