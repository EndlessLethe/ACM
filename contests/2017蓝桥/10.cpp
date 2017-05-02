#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mp[10010][10010];

int main() {
	int N, a, b, c, d;
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				mp[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 10010; i++) {
		for (int j = 0; j < 10010; j++) {
			if (mp[i][j]) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
