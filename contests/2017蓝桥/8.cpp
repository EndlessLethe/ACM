#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int a[105];
int dp[100100];

int main() {
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		dp[a[i]] = 1;
	}
	for (int i = 0; i < 100100; i++) {
		for (int j = 0; j < N; j++) {
			if (i-a[j] >= 0 && dp[i-a[j]]) dp[i] = 1;
		}
	}
	for (int i = 0; i < 100100; i++) {
		if (!dp[i]) {
			cnt++;
			//printf("%d", i);
		}
	}
	if (cnt <= 50000) printf("%d\n", cnt-1);
	else printf("INF\n");
	return 0;
}
